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

#include <aws/workdocs/model/UpdateDocumentVersionRequest.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::WorkDocs::Model;
using namespace Aws::Utils::Json;
using namespace Aws::Utils;

UpdateDocumentVersionRequest::UpdateDocumentVersionRequest() : 
    m_authenticationTokenHasBeenSet(false),
    m_documentIdHasBeenSet(false),
    m_versionIdHasBeenSet(false),
    m_versionStatus(DocumentVersionStatus::NOT_SET),
    m_versionStatusHasBeenSet(false)
{
}

Aws::String UpdateDocumentVersionRequest::SerializePayload() const
{
  JsonValue payload;

  if(m_versionStatusHasBeenSet)
  {
   payload.WithString("VersionStatus", DocumentVersionStatusMapper::GetNameForDocumentVersionStatus(m_versionStatus));
  }

  return payload.View().WriteReadable();
}

Aws::Http::HeaderValueCollection UpdateDocumentVersionRequest::GetRequestSpecificHeaders() const
{
  Aws::Http::HeaderValueCollection headers;
  Aws::StringStream ss;
  if(m_authenticationTokenHasBeenSet)
  {
    ss << m_authenticationToken;
    headers.emplace("authentication",  ss.str());
    ss.str("");
  }

  return headers;

}




