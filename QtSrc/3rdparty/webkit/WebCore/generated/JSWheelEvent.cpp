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

#include "config.h"
#include "JSWheelEvent.h"

#include "JSDOMWindow.h"
#include "WheelEvent.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSWheelEvent);

/* Hash table */

static const HashTableValue JSWheelEventTableValues[17] =
{
    { "screenX", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventScreenX), (intptr_t)0 },
    { "screenY", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventScreenY), (intptr_t)0 },
    { "clientX", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventClientX), (intptr_t)0 },
    { "clientY", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventClientY), (intptr_t)0 },
    { "ctrlKey", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventCtrlKey), (intptr_t)0 },
    { "shiftKey", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventShiftKey), (intptr_t)0 },
    { "altKey", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventAltKey), (intptr_t)0 },
    { "metaKey", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventMetaKey), (intptr_t)0 },
    { "wheelDelta", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventWheelDelta), (intptr_t)0 },
    { "wheelDeltaX", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventWheelDeltaX), (intptr_t)0 },
    { "wheelDeltaY", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventWheelDeltaY), (intptr_t)0 },
    { "offsetX", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventOffsetX), (intptr_t)0 },
    { "offsetY", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventOffsetY), (intptr_t)0 },
    { "x", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventX), (intptr_t)0 },
    { "y", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventY), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWheelEventConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWheelEventTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSWheelEventTableValues, 0 };
#else
    { 33, 31, JSWheelEventTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSWheelEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWheelEventConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSWheelEventConstructorTableValues, 0 };
#else
    { 1, 0, JSWheelEventConstructorTableValues, 0 };
#endif

class JSWheelEventConstructor : public DOMConstructorObject {
public:
    JSWheelEventConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSWheelEventConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSWheelEventPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSWheelEventConstructor::s_info = { "WheelEventConstructor", 0, &JSWheelEventConstructorTable, 0 };

bool JSWheelEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWheelEventConstructor, DOMObject>(exec, &JSWheelEventConstructorTable, this, propertyName, slot);
}

bool JSWheelEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWheelEventConstructor, DOMObject>(exec, &JSWheelEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSWheelEventPrototypeTableValues[2] =
{
    { "initWebKitWheelEvent", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsWheelEventPrototypeFunctionInitWebKitWheelEvent), (intptr_t)11 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWheelEventPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSWheelEventPrototypeTableValues, 0 };
#else
    { 2, 1, JSWheelEventPrototypeTableValues, 0 };
#endif

const ClassInfo JSWheelEventPrototype::s_info = { "WheelEventPrototype", 0, &JSWheelEventPrototypeTable, 0 };

JSObject* JSWheelEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSWheelEvent>(exec, globalObject);
}

bool JSWheelEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSWheelEventPrototypeTable, this, propertyName, slot);
}

bool JSWheelEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSWheelEventPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSWheelEvent::s_info = { "WheelEvent", &JSUIEvent::s_info, &JSWheelEventTable, 0 };

JSWheelEvent::JSWheelEvent(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<WheelEvent> impl)
    : JSUIEvent(structure, globalObject, impl)
{
}

JSObject* JSWheelEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSWheelEventPrototype(JSWheelEventPrototype::createStructure(JSUIEventPrototype::self(exec, globalObject)));
}

bool JSWheelEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWheelEvent, Base>(exec, &JSWheelEventTable, this, propertyName, slot);
}

bool JSWheelEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWheelEvent, Base>(exec, &JSWheelEventTable, this, propertyName, descriptor);
}

JSValue jsWheelEventScreenX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->screenX());
    return result;
}

JSValue jsWheelEventScreenY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->screenY());
    return result;
}

JSValue jsWheelEventClientX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->clientX());
    return result;
}

JSValue jsWheelEventClientY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->clientY());
    return result;
}

JSValue jsWheelEventCtrlKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->ctrlKey());
    return result;
}

JSValue jsWheelEventShiftKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->shiftKey());
    return result;
}

JSValue jsWheelEventAltKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->altKey());
    return result;
}

JSValue jsWheelEventMetaKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsBoolean(imp->metaKey());
    return result;
}

JSValue jsWheelEventWheelDelta(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->wheelDelta());
    return result;
}

JSValue jsWheelEventWheelDeltaX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->wheelDeltaX());
    return result;
}

JSValue jsWheelEventWheelDeltaY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->wheelDeltaY());
    return result;
}

JSValue jsWheelEventOffsetX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->offsetX());
    return result;
}

JSValue jsWheelEventOffsetY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->offsetY());
    return result;
}

JSValue jsWheelEventX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->x());
    return result;
}

JSValue jsWheelEventY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* castedThis = static_cast<JSWheelEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WheelEvent* imp = static_cast<WheelEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->y());
    return result;
}

JSValue jsWheelEventConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWheelEvent* domObject = static_cast<JSWheelEvent*>(asObject(slotBase));
    return JSWheelEvent::getConstructor(exec, domObject->globalObject());
}
JSValue JSWheelEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSWheelEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsWheelEventPrototypeFunctionInitWebKitWheelEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSWheelEvent::s_info))
        return throwError(exec, TypeError);
    JSWheelEvent* castedThisObj = static_cast<JSWheelEvent*>(asObject(thisValue));
    WheelEvent* imp = static_cast<WheelEvent*>(castedThisObj->impl());
    int wheelDeltaX = args.at(0).toInt32(exec);
    int wheelDeltaY = args.at(1).toInt32(exec);
    DOMWindow* view = toDOMWindow(args.at(2));
    int screenX = args.at(3).toInt32(exec);
    int screenY = args.at(4).toInt32(exec);
    int clientX = args.at(5).toInt32(exec);
    int clientY = args.at(6).toInt32(exec);
    bool ctrlKey = args.at(7).toBoolean(exec);
    bool altKey = args.at(8).toBoolean(exec);
    bool shiftKey = args.at(9).toBoolean(exec);
    bool metaKey = args.at(10).toBoolean(exec);

    imp->initWebKitWheelEvent(wheelDeltaX, wheelDeltaY, view, screenX, screenY, clientX, clientY, ctrlKey, altKey, shiftKey, metaKey);
    return jsUndefined();
}


}
