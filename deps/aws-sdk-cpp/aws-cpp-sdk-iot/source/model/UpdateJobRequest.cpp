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

#include <aws/iot/model/UpdateJobRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::IoT::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateJobRequest::UpdateJobRequest() : 
    m_jobIdHasBeenSet(false),
    m_descriptionHasBeenSet(false),
    m_presignedUrlConfigHasBeenSet(false),
    m_jobExecutionsRolloutConfigHasBeenSet(false),
    m_abortConfigHasBeenSet(false),
    m_timeoutConfigHasBeenSet(false)
{
}

Aws::String UpdateJobRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_descriptionHasBeenSet)
  {
   payload.WithString("description", m_description);

  }

  if(m_presignedUrlConfigHasBeenSet)
  {
   payload.WithObject("presignedUrlConfig", m_presignedUrlConfig.Jsonize());

  }

  if(m_jobExecutionsRolloutConfigHasBeenSet)
  {
   payload.WithObject("jobExecutionsRolloutConfig", m_jobExecutionsRolloutConfig.Jsonize());

  }

  if(m_abortConfigHasBeenSet)
  {
   payload.WithObject("abortConfig", m_abortConfig.Jsonize());

  }

  if(m_timeoutConfigHasBeenSet)
  {
   payload.WithObject("timeoutConfig", m_timeoutConfig.Jsonize());

  }

  return payload.View().WriteReadable();
}




