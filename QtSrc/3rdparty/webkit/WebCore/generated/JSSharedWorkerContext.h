/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSSharedWorkerContext_h
#define JSSharedWorkerContext_h

#if ENABLE(SHARED_WORKERS)

#include "JSWorkerContext.h"
#include "SharedWorkerContext.h"

namespace WebCore {

class SharedWorkerContext;

class JSSharedWorkerContext : public JSWorkerContext {
    typedef JSWorkerContext Base;
public:
    JSSharedWorkerContext(NonNullPassRefPtr<JSC::Structure>, PassRefPtr<SharedWorkerContext>);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }

    SharedWorkerContext* impl() const
    {
        return static_cast<SharedWorkerContext*>(Base::impl());
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

SharedWorkerContext* toSharedWorkerContext(JSC::JSValue);

class JSSharedWorkerContextPrototype : public JSC::JSObject {
    typedef JSC::JSObject Base;
public:
    void* operator new(size_t, JSC::JSGlobalData*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }
    JSSharedWorkerContextPrototype(NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
protected:
    static const unsigned StructureFlags = Base::StructureFlags;
};

// Attributes

JSC::JSValue jsSharedWorkerContextName(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsSharedWorkerContextOnconnect(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
void setJSSharedWorkerContextOnconnect(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);

} // namespace WebCore

#endif // ENABLE(SHARED_WORKERS)

#endif
