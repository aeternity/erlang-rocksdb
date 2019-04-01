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

#include <aws/workdocs/model/PrincipalType.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace WorkDocs
  {
    namespace Model
    {
      namespace PrincipalTypeMapper
      {

        static const int USER_HASH = HashingUtils::HashString("USER");
        static const int GROUP_HASH = HashingUtils::HashString("GROUP");
        static const int INVITE_HASH = HashingUtils::HashString("INVITE");
        static const int ANONYMOUS_HASH = HashingUtils::HashString("ANONYMOUS");
        static const int ORGANIZATION_HASH = HashingUtils::HashString("ORGANIZATION");


        PrincipalType GetPrincipalTypeForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == USER_HASH)
          {
            return PrincipalType::USER;
          }
          else if (hashCode == GROUP_HASH)
          {
            return PrincipalType::GROUP;
          }
          else if (hashCode == INVITE_HASH)
          {
            return PrincipalType::INVITE;
          }
          else if (hashCode == ANONYMOUS_HASH)
          {
            return PrincipalType::ANONYMOUS;
          }
          else if (hashCode == ORGANIZATION_HASH)
          {
            return PrincipalType::ORGANIZATION;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<PrincipalType>(hashCode);
          }

          return PrincipalType::NOT_SET;
        }

        Aws::String GetNameForPrincipalType(PrincipalType enumValue)
        {
          switch(enumValue)
          {
          case PrincipalType::USER:
            return "USER";
          case PrincipalType::GROUP:
            return "GROUP";
          case PrincipalType::INVITE:
            return "INVITE";
          case PrincipalType::ANONYMOUS:
            return "ANONYMOUS";
          case PrincipalType::ORGANIZATION:
            return "ORGANIZATION";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace PrincipalTypeMapper
    } // namespace Model
  } // namespace WorkDocs
} // namespace Aws
