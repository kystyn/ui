/*
 * Copyright (C) 2008 Apple Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "LocalStorageTask.h"

#if ENABLE(DOM_STORAGE)

#include "LocalStorageThread.h"
#include "StorageAreaSync.h"

namespace WebCore {

LocalStorageTask::LocalStorageTask(Type type, StorageAreaSync* area)
    : m_type(type)
    , m_area(area)
    , m_thread(0)
{
    ASSERT(m_area);
    ASSERT(m_type == AreaImport || m_type == AreaSync);
}

LocalStorageTask::LocalStorageTask(Type type, LocalStorageThread* thread)
    : m_type(type)
    , m_area(0)
    , m_thread(thread)
{
    ASSERT(m_thread);
    ASSERT(m_type == TerminateThread);
}

LocalStorageTask::~LocalStorageTask()
{
}

void LocalStorageTask::performTask()
{
    switch (m_type) {
        case AreaImport:
            m_area->performImport();
            break;
        case AreaSync:
            m_area->performSync();
            break;
        case TerminateThread:
            m_thread->performTerminate();
            break;
    }
}

}

#endif // ENABLE(DOM_STORAGE)
