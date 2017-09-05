
%% Copyright (c) 2010-2013 Basho Technologies, Inc. All Rights Reserved.
%% Copyright (c) 2017 Benoît Chesneau
%%
%% This file is provided to you under the Apache License,
%% Version 2.0 (the "License"); you may not use this file
%% except in compliance with the License.  You may obtain
%% a copy of the License at
%%
%%   http://www.apache.org/licenses/LICENSE-2.0
%%
%% Unless required by applicable law or agreed to in writing,
%% software distributed under the License is distributed on an
%% "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
%% KIND, either express or implied.  See the License for the
%% specific language governing permissions and limitations
%% under the License.
%%
%% -------------------------------------------------------------------
-module(cache).

-compile(export_all).

-include_lib("eunit/include/eunit.hrl").

capacity_test() ->
  ?assertEqual(4194304, rocksdb:block_cache_capacity()),
  ok = rocksdb:block_cache_capacity(83886080),
  ?assertEqual(83886080, rocksdb:block_cache_capacity()).


cacheleak_test_() ->
  {timeout, 10*60, fun() ->
                [] = os:cmd("rm -rf /tmp/erocksdb.cacheleak.test"),
                Blobs = [{<<I:128/unsigned>>, compressible_bytes(10240)} ||
                      I <- lists:seq(1, 10000)],
                cacheleak_loop(10, Blobs, 500000)
            end}.

%% It's very important for this test that the data is compressible. Otherwise,
%% the file will be mmaped, and nothing will fill up the cache.
compressible_bytes(Count) ->
  list_to_binary([0 || _I <- lists:seq(1, Count)]).

cacheleak_loop(0, _Blobs, _MaxFinalRSS) ->
  ok;
cacheleak_loop(Count, Blobs, MaxFinalRSS) ->
  %% We spawn a process to open a LevelDB instance and do a series of
  %% reads/writes to fill up the cache. When the process exits, the LevelDB
  %% ref will get GC'd and we can re-evaluate the memory footprint of the
  %% process to make sure everything got cleaned up as expected.
  F = fun() ->
          {ok, Ref} = rocksdb:open("/tmp/erocksdb.cacheleak.test",
                                   [{create_if_missing, true},
                                    {table_factory_block_cache_size, 83886080}]),
          ?assertEqual(83886080, rocksdb:block_cache_capacity()),
          [ok = rocksdb:put(Ref, I, B, []) || {I, B} <- Blobs],
          rocksdb:fold(Ref, fun({_K, _V}, A) -> A end, [], [{fill_cache, true}]),
          [{ok, B} = rocksdb:get(Ref, I, []) || {I, B} <- Blobs],
          ok = rocksdb:close(Ref),
          erlang:garbage_collect(),
          io:format(user, "cache usage: ~p\n", [rocksdb:get_block_cache_usage()]),
          io:format(user, "RSS1: ~p\n", [rssmem()])
      end,
  {_Pid, Mref} = spawn_monitor(F),
  receive
    {'DOWN', Mref, process, _, _} ->
      ok
  end,
  RSS = rssmem(),
  ?assert(MaxFinalRSS > RSS),
  cacheleak_loop(Count-1, Blobs, MaxFinalRSS).

rssmem() ->
  Cmd = io_lib:format("ps -o rss= -p ~s", [os:getpid()]),
  S = string:strip(os:cmd(Cmd), both),
  case string:to_integer(S) of
    {error, _} ->
      io:format(user, "Error parsing integer in: ~s\n", [S]),
      error;
    {I, _} ->
      I
  end.