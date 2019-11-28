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

#include "JSSVGMaskElement.h"

#include "CSSMutableStyleDeclaration.h"
#include "CSSStyleDeclaration.h"
#include "CSSValue.h"
#include "JSCSSStyleDeclaration.h"
#include "JSCSSValue.h"
#include "JSSVGAnimatedBoolean.h"
#include "JSSVGAnimatedEnumeration.h"
#include "JSSVGAnimatedLength.h"
#include "JSSVGAnimatedString.h"
#include "JSSVGStringList.h"
#include "KURL.h"
#include "SVGMaskElement.h"
#include "SVGStringList.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGMaskElement);

/* Hash table */

static const HashTableValue JSSVGMaskElementTableValues[16] =
{
    { "maskUnits", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementMaskUnits), (intptr_t)0 },
    { "maskContentUnits", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementMaskContentUnits), (intptr_t)0 },
    { "x", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementX), (intptr_t)0 },
    { "y", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementY), (intptr_t)0 },
    { "width", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementWidth), (intptr_t)0 },
    { "height", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementHeight), (intptr_t)0 },
    { "requiredFeatures", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementRequiredFeatures), (intptr_t)0 },
    { "requiredExtensions", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementRequiredExtensions), (intptr_t)0 },
    { "systemLanguage", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementSystemLanguage), (intptr_t)0 },
    { "xmllang", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementXmllang), (intptr_t)setJSSVGMaskElementXmllang },
    { "xmlspace", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementXmlspace), (intptr_t)setJSSVGMaskElementXmlspace },
    { "externalResourcesRequired", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementExternalResourcesRequired), (intptr_t)0 },
    { "className", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementClassName), (intptr_t)0 },
    { "style", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementStyle), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGMaskElementConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGMaskElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 255, JSSVGMaskElementTableValues, 0 };
#else
    { 37, 31, JSSVGMaskElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGMaskElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGMaskElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGMaskElementConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGMaskElementConstructorTableValues, 0 };
#endif

class JSSVGMaskElementConstructor : public DOMConstructorObject {
public:
    JSSVGMaskElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGMaskElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGMaskElementPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGMaskElementConstructor::s_info = { "SVGMaskElementConstructor", 0, &JSSVGMaskElementConstructorTable, 0 };

bool JSSVGMaskElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGMaskElementConstructor, DOMObject>(exec, &JSSVGMaskElementConstructorTable, this, propertyName, slot);
}

bool JSSVGMaskElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGMaskElementConstructor, DOMObject>(exec, &JSSVGMaskElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGMaskElementPrototypeTableValues[3] =
{
    { "hasExtension", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGMaskElementPrototypeFunctionHasExtension), (intptr_t)1 },
    { "getPresentationAttribute", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsSVGMaskElementPrototypeFunctionGetPresentationAttribute), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGMaskElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1, JSSVGMaskElementPrototypeTableValues, 0 };
#else
    { 4, 3, JSSVGMaskElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGMaskElementPrototype::s_info = { "SVGMaskElementPrototype", 0, &JSSVGMaskElementPrototypeTable, 0 };

JSObject* JSSVGMaskElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGMaskElement>(exec, globalObject);
}

bool JSSVGMaskElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSSVGMaskElementPrototypeTable, this, propertyName, slot);
}

bool JSSVGMaskElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSSVGMaskElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSSVGMaskElement::s_info = { "SVGMaskElement", &JSSVGElement::s_info, &JSSVGMaskElementTable, 0 };

JSSVGMaskElement::JSSVGMaskElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGMaskElement> impl)
    : JSSVGElement(structure, globalObject, impl)
{
}

JSObject* JSSVGMaskElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGMaskElementPrototype(JSSVGMaskElementPrototype::createStructure(JSSVGElementPrototype::self(exec, globalObject)));
}

bool JSSVGMaskElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGMaskElement, Base>(exec, &JSSVGMaskElementTable, this, propertyName, slot);
}

bool JSSVGMaskElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGMaskElement, Base>(exec, &JSSVGMaskElementTable, this, propertyName, descriptor);
}

JSValue jsSVGMaskElementMaskUnits(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedEnumeration> obj = imp->maskUnitsAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementMaskContentUnits(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedEnumeration> obj = imp->maskContentUnitsAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->xAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->yAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementWidth(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->widthAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementHeight(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedLength> obj = imp->heightAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementRequiredFeatures(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->requiredFeatures()), imp);
    return result;
}

JSValue jsSVGMaskElementRequiredExtensions(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->requiredExtensions()), imp);
    return result;
}

JSValue jsSVGMaskElementSystemLanguage(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->systemLanguage()), imp);
    return result;
}

JSValue jsSVGMaskElementXmllang(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->xmllang());
    return result;
}

JSValue jsSVGMaskElementXmlspace(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->xmlspace());
    return result;
}

JSValue jsSVGMaskElementExternalResourcesRequired(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedBoolean> obj = imp->externalResourcesRequiredAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementClassName(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    RefPtr<SVGAnimatedString> obj = imp->classNameAnimated();
    JSValue result =  toJS(exec, castedThis->globalObject(), obj.get(), imp);
    return result;
}

JSValue jsSVGMaskElementStyle(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* castedThis = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThis->impl());
    JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->style()));
    return result;
}

JSValue jsSVGMaskElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGMaskElement* domObject = static_cast<JSSVGMaskElement*>(asObject(slotBase));
    return JSSVGMaskElement::getConstructor(exec, domObject->globalObject());
}
void JSSVGMaskElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGMaskElement, Base>(exec, propertyName, value, &JSSVGMaskElementTable, this, slot);
}

void setJSSVGMaskElementXmllang(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGMaskElement* castedThisObj = static_cast<JSSVGMaskElement*>(thisObject);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThisObj->impl());
    imp->setXmllang(value.toString(exec));
}

void setJSSVGMaskElementXmlspace(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGMaskElement* castedThisObj = static_cast<JSSVGMaskElement*>(thisObject);
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThisObj->impl());
    imp->setXmlspace(value.toString(exec));
}

JSValue JSSVGMaskElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGMaskElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsSVGMaskElementPrototypeFunctionHasExtension(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGMaskElement::s_info))
        return throwError(exec, TypeError);
    JSSVGMaskElement* castedThisObj = static_cast<JSSVGMaskElement*>(asObject(thisValue));
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThisObj->impl());
    const UString& extension = args.at(0).toString(exec);


    JSC::JSValue result = jsBoolean(imp->hasExtension(extension));
    return result;
}

JSValue JSC_HOST_CALL jsSVGMaskElementPrototypeFunctionGetPresentationAttribute(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSSVGMaskElement::s_info))
        return throwError(exec, TypeError);
    JSSVGMaskElement* castedThisObj = static_cast<JSSVGMaskElement*>(asObject(thisValue));
    SVGMaskElement* imp = static_cast<SVGMaskElement*>(castedThisObj->impl());
    const UString& name = args.at(0).toString(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->getPresentationAttribute(name)));
    return result;
}


}

#endif // ENABLE(SVG)
