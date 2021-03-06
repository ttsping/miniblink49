// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "config.h"
#include "core/html/LinkDefaultPresentation.h"

#include "core/dom/Document.h"
#include "core/frame/LocalFrame.h"
#include "core/html/HTMLLinkElement.h"
#include "core/loader/FrameLoaderClient.h"

namespace blink {

PassOwnPtrWillBeRawPtr<LinkDefaultPresentation> LinkDefaultPresentation::create(HTMLLinkElement* owner)
{
    return adoptPtrWillBeNoop(new LinkDefaultPresentation(owner));
}

LinkDefaultPresentation::LinkDefaultPresentation(HTMLLinkElement* owner)
    : LinkResource(owner)
{
}

LinkDefaultPresentation::~LinkDefaultPresentation()
{
}

void LinkDefaultPresentation::process()
{
    if (!m_owner || !m_owner->document().frame())
        return;

    m_owner->document().frame()->loader().client()->dispatchDidChangeDefaultPresentation();
}

bool LinkDefaultPresentation::hasLoaded() const
{
    return false;
}

void LinkDefaultPresentation::ownerRemoved()
{
    process();
}

} // namespace blink
