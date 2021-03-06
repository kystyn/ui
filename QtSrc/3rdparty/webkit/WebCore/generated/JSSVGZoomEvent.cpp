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

#if ENABLE(SVG)

#include "JSSVGZoomEvent.h"

#include "JSSVGPoint.h"
#include "JSSVGRect.h"
#include "SVGZoomEvent.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGZoomEvent);

/* Hash table */

static const HashTableValue JSSVGZoomEventTableValues[7] =
{
    { "zoomRectScreen", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGZoomEventZoomRectScreen), (intptr_t)0 },
    { "previousScale", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGZoomEventPreviousScale), (intptr_t)0 },
    { "previousTranslate", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGZoomEventPreviousTranslate), (intptr_t)0 },
    { "newScale", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGZoomEventNewScale), (intptr_t)0 },
    { "newTranslate", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGZoomEventNewTranslate), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGZoomEventConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGZoomEventTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 31, JSSVGZoomEventTableValues, 0 };
#else
    { 17, 15, JSSVGZoomEventTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGZoomEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGZoomEventConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGZoomEventConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGZoomEventConstructorTableValues, 0 };
#endif

class JSSVGZoomEventConstructor : public DOMConstructorObject {
public:
    JSSVGZoomEventConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGZoomEventConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGZoomEventPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGZoomEventConstructor::s_info = { "SVGZoomEventConstructor", 0, &JSSVGZoomEventConstructorTable, 0 };

bool JSSVGZoomEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGZoomEventConstructor, DOMObject>(exec, &JSSVGZoomEventConstructorTable, this, propertyName, slot);
}

bool JSSVGZoomEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGZoomEventConstructor, DOMObject>(exec, &JSSVGZoomEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGZoomEventPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGZoomEventPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGZoomEventPrototypeTableValues, 0 };
#else
    { 1, 0, JSSVGZoomEventPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGZoomEventPrototype::s_info = { "SVGZoomEventPrototype", 0, &JSSVGZoomEventPrototypeTable, 0 };

JSObject* JSSVGZoomEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGZoomEvent>(exec, globalObject);
}

const ClassInfo JSSVGZoomEvent::s_info = { "SVGZoomEvent", &JSUIEvent::s_info, &JSSVGZoomEventTable, 0 };

JSSVGZoomEvent::JSSVGZoomEvent(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGZoomEvent> impl)
    : JSUIEvent(structure, globalObject, impl)
{
}

JSObject* JSSVGZoomEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGZoomEventPrototype(JSSVGZoomEventPrototype::createStructure(JSUIEventPrototype::self(exec, globalObject)));
}

bool JSSVGZoomEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGZoomEvent, Base>(exec, &JSSVGZoomEventTable, this, propertyName, slot);
}

bool JSSVGZoomEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGZoomEvent, Base>(exec, &JSSVGZoomEventTable, this, propertyName, descriptor);
}

JSValue jsSVGZoomEventZoomRectScreen(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGZoomEvent* castedThis = static_cast<JSSVGZoomEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGZoomEvent* imp = static_cast<SVGZoomEvent*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), JSSVGStaticPODTypeWrapper<FloatRect>::create(imp->zoomRectScreen()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue jsSVGZoomEventPreviousScale(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGZoomEvent* castedThis = static_cast<JSSVGZoomEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGZoomEvent* imp = static_cast<SVGZoomEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->previousScale());
    return result;
}

JSValue jsSVGZoomEventPreviousTranslate(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGZoomEvent* castedThis = static_cast<JSSVGZoomEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGZoomEvent* imp = static_cast<SVGZoomEvent*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), JSSVGStaticPODTypeWrapper<FloatPoint>::create(imp->previousTranslate()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue jsSVGZoomEventNewScale(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGZoomEvent* castedThis = static_cast<JSSVGZoomEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGZoomEvent* imp = static_cast<SVGZoomEvent*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->newScale());
    return result;
}

JSValue jsSVGZoomEventNewTranslate(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGZoomEvent* castedThis = static_cast<JSSVGZoomEvent*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGZoomEvent* imp = static_cast<SVGZoomEvent*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), JSSVGStaticPODTypeWrapper<FloatPoint>::create(imp->newTranslate()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue jsSVGZoomEventConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGZoomEvent* domObject = static_cast<JSSVGZoomEvent*>(asObject(slotBase));
    return JSSVGZoomEvent::getConstructor(exec, domObject->globalObject());
}
JSValue JSSVGZoomEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGZoomEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}

#endif // ENABLE(SVG)
