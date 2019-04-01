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

#include <aws/chime/model/InviteStatus.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace Chime
  {
    namespace Model
    {
      namespace InviteStatusMapper
      {

        static const int Pending_HASH = HashingUtils::HashString("Pending");
        static const int Accepted_HASH = HashingUtils::HashString("Accepted");
        static const int Failed_HASH = HashingUtils::HashString("Failed");


        InviteStatus GetInviteStatusForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == Pending_HASH)
          {
            return InviteStatus::Pending;
          }
          else if (hashCode == Accepted_HASH)
          {
            return InviteStatus::Accepted;
          }
          else if (hashCode == Failed_HASH)
          {
            return InviteStatus::Failed;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<InviteStatus>(hashCode);
          }

          return InviteStatus::NOT_SET;
        }

        Aws::String GetNameForInviteStatus(InviteStatus enumValue)
        {
          switch(enumValue)
          {
          case InviteStatus::Pending:
            return "Pending";
          case InviteStatus::Accepted:
            return "Accepted";
          case InviteStatus::Failed:
            return "Failed";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace InviteStatusMapper
    } // namespace Model
  } // namespace Chime
} // namespace Aws
