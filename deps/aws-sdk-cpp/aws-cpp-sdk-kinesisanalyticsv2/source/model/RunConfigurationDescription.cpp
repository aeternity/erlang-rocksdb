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

#include <aws/kinesisanalyticsv2/model/RunConfigurationDescription.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace KinesisAnalyticsV2
{
namespace Model
{

RunConfigurationDescription::RunConfigurationDescription() : 
    m_applicationRestoreConfigurationDescriptionHasBeenSet(false)
{
}

RunConfigurationDescription::RunConfigurationDescription(JsonView jsonValue) : 
    m_applicationRestoreConfigurationDescriptionHasBeenSet(false)
{
  *this = jsonValue;
}

RunConfigurationDescription& RunConfigurationDescription::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("ApplicationRestoreConfigurationDescription"))
  {
    m_applicationRestoreConfigurationDescription = jsonValue.GetObject("ApplicationRestoreConfigurationDescription");

    m_applicationRestoreConfigurationDescriptionHasBeenSet = true;
  }

  return *this;
}

JsonValue RunConfigurationDescription::Jsonize() const
{
  JsonValue payload;

  if(m_applicationRestoreConfigurationDescriptionHasBeenSet)
  {
   payload.WithObject("ApplicationRestoreConfigurationDescription", m_applicationRestoreConfigurationDescription.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace KinesisAnalyticsV2
} // namespace Aws
