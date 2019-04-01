﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/robomaker/model/BatchDescribeSimulationJobResult.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/UnreferencedParam.h>

#include <utility>

using namespace Aws::RoboMaker::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;
using namespace Aws;

BatchDescribeSimulationJobResult::BatchDescribeSimulationJobResult()
{
}

BatchDescribeSimulationJobResult::BatchDescribeSimulationJobResult(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  *this = result;
}

BatchDescribeSimulationJobResult& BatchDescribeSimulationJobResult::operator =(const Aws::AmazonWebServiceResult<JsonValue>& result)
{
  JsonView jsonValue = result.GetPayload().View();
  if(jsonValue.ValueExists("jobs"))
  {
    Array<JsonView> jobsJsonList = jsonValue.GetArray("jobs");
    for(unsigned jobsIndex = 0; jobsIndex < jobsJsonList.GetLength(); ++jobsIndex)
    {
      m_jobs.push_back(jobsJsonList[jobsIndex].AsObject());
    }
  }

  if(jsonValue.ValueExists("unprocessedJobs"))
  {
    Array<JsonView> unprocessedJobsJsonList = jsonValue.GetArray("unprocessedJobs");
    for(unsigned unprocessedJobsIndex = 0; unprocessedJobsIndex < unprocessedJobsJsonList.GetLength(); ++unprocessedJobsIndex)
    {
      m_unprocessedJobs.push_back(unprocessedJobsJsonList[unprocessedJobsIndex].AsString());
    }
  }



  return *this;
}
