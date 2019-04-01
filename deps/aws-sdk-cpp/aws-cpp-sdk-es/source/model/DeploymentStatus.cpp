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

#include <aws/es/model/DeploymentStatus.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace ElasticsearchService
  {
    namespace Model
    {
      namespace DeploymentStatusMapper
      {

        static const int PENDING_UPDATE_HASH = HashingUtils::HashString("PENDING_UPDATE");
        static const int IN_PROGRESS_HASH = HashingUtils::HashString("IN_PROGRESS");
        static const int COMPLETED_HASH = HashingUtils::HashString("COMPLETED");
        static const int NOT_ELIGIBLE_HASH = HashingUtils::HashString("NOT_ELIGIBLE");
        static const int ELIGIBLE_HASH = HashingUtils::HashString("ELIGIBLE");


        DeploymentStatus GetDeploymentStatusForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == PENDING_UPDATE_HASH)
          {
            return DeploymentStatus::PENDING_UPDATE;
          }
          else if (hashCode == IN_PROGRESS_HASH)
          {
            return DeploymentStatus::IN_PROGRESS;
          }
          else if (hashCode == COMPLETED_HASH)
          {
            return DeploymentStatus::COMPLETED;
          }
          else if (hashCode == NOT_ELIGIBLE_HASH)
          {
            return DeploymentStatus::NOT_ELIGIBLE;
          }
          else if (hashCode == ELIGIBLE_HASH)
          {
            return DeploymentStatus::ELIGIBLE;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<DeploymentStatus>(hashCode);
          }

          return DeploymentStatus::NOT_SET;
        }

        Aws::String GetNameForDeploymentStatus(DeploymentStatus enumValue)
        {
          switch(enumValue)
          {
          case DeploymentStatus::PENDING_UPDATE:
            return "PENDING_UPDATE";
          case DeploymentStatus::IN_PROGRESS:
            return "IN_PROGRESS";
          case DeploymentStatus::COMPLETED:
            return "COMPLETED";
          case DeploymentStatus::NOT_ELIGIBLE:
            return "NOT_ELIGIBLE";
          case DeploymentStatus::ELIGIBLE:
            return "ELIGIBLE";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace DeploymentStatusMapper
    } // namespace Model
  } // namespace ElasticsearchService
} // namespace Aws
