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

#include "JSSVGTextElement.h"

#include "JSSVGAnimatedTransformList.h"
#include "JSSVGElement.h"
#include "JSSVGMatrix.h"
#include "JSSVGRect.h"
#include "SVGElement.h"
#include "SVGTextElement.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGTextElement);

/* Hash table */

static const HashTableValue JSSVGTextElementTableValues[5] =
{
    { "transform", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGTextElementTransform), (intptr_t)0 },
    { "nearestViewportElement", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGTextElementNearestViewportElement), (intptr_t)0 },
    { "farthestViewportElement", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGTextElementFarthestViewportElement), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGTextElementConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 31, JSSVGTextElementTableValues, 0 };
#else
    { 9, 7, JSSVGTextElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGTextElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGTextElementConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGTextElementConstructorTableValues, 0 };
#endif

class JSSVGTextElementConstructor : public DOMConstructorObject {
public:
    JSSVGTextElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGTextElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGTextElementPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGTextElementConstructor::s_info = { "SVGTextElementConstructor", 0, &JSSVGTextElementConstructorTable, 0 };

bool JSSVGTextElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGTextElementConstructor, DOMObject>(exec, &JSSVGTextElementConstructorTable, this, propertyName, slot);
}

bool JSSVGTextElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGTextElementConstructor, DOMObject>(exec, &JSSVGTextElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGTextElementPrototypeTableValues[5] =
{
    { "getBBox", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGTextElementPrototypeFunctionGetBBox), (intptr_t)0 },
    { "getCTM", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGTextElementPrototypeFunctionGetCTM), (intptr_t)0 },
    { "getScreenCTM", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGTextElementPrototypeFunctionGetScreenCTM), (intptr_t)0 },
    { "getTransformToElement", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGTextElementPrototypeFunctionGetTransformToElement), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGTextElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSSVGTextElementPrototypeTableValues, 0 };
#else
    { 8, 7, JSSVGTextElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGTextElementPrototype::s_info = { "SVGTextElementPrototype", 0, &JSSVGTextElementPrototypeTable, 0 };

JSObject* JSSVGTextElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGTextElement>(exec, globalObject);
}

bool JSSVGTextElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSVGTextElementPrototypeTable, this, propertyName, slot);
}

bool JSSVGTextElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSVGTextElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGTextElement::s_info = { "SVGTextElement", &JSSVGTextPositioningElement::s_info, &JSSVGTextElementTable, 0 };

JSSVGTextElement::JSSVGTextElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGTextElement> impl)
    : JSSVGTextPositioningElement(structure, globalObject, impl)
{
}

JSObject* JSSVGTextElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGTextElementPrototype(JSSVGTextElementPrototype::createStructure(JSSVGTextPositioningElementPrototype::self(exec, globalObject)));
}

bool JSSVGTextElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGTextElement, Base>(exec, &JSSVGTextElementTable, this, propertyName, slot);
}

bool JSSVGTextElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGTextElement, Base>(exec, &JSSVGTextElementTable, this, propertyName, descriptor);
}

JSValue jsSVGTextElementTransform(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGTextElement* castedThis = static_cast<JSSVGTextElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThis->impl());
    RefPtr<SVGAnimatedTransformList> obj = imp->transformAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGTextElementNearestViewportElement(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGTextElement* castedThis = static_cast<JSSVGTextElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->nearestViewportElement()));
    return result;
}

JSValue jsSVGTextElementFarthestViewportElement(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGTextElement* castedThis = static_cast<JSSVGTextElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->farthestViewportElement()));
    return result;
}

JSValue jsSVGTextElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGTextElement* domObject = static_cast<JSSVGTextElement*>(asObject(slotBase));
    return JSSVGTextElement::getConstructor(exec, domObject->globalObject());
}
JSValue JSSVGTextElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGTextElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetBBox(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<FloatRect>::create(imp->getBBox()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetCTM(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<AffineTransform>::create(imp->getCTM()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetScreenCTM(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<AffineTransform>::create(imp->getScreenCTM()).get(), 0 /* no context on purpose */);
    return result;
}

JSValue JSC_HOST_CALL jsSVGTextElementPrototypeFunctionGetTransformToElement(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGTextElement::s_info))
        return throwError(exec, TypeError);
    JSSVGTextElement* castedThisObj = static_cast<JSSVGTextElement*>(asObject(thisValue));
    SVGTextElement* imp = static_cast<SVGTextElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    SVGElement* element = toSVGElement(args.at(0));


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), JSSVGStaticPODTypeWrapper<AffineTransform>::create(imp->getTransformToElement(element, ec)).get(), 0 /* no context on purpose */);
    setDOMException(exec, ec);
    return result;
}


}

#endif // ENABLE(SVG)
