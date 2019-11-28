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
#include "JSCSSValue.h"

#include "CSSValue.h"
#include "KURL.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSCSSValue);

/* Hash table */

static const HashTableValue JSCSSValueTableValues[4] =
{
    { "cssText", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCssText), (intptr_t)setJSCSSValueCssText },
    { "cssValueType", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCssValueType), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSValueTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSCSSValueTableValues, 0 };
#else
    { 8, 7, JSCSSValueTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSCSSValueConstructorTableValues[5] =
{
    { "CSS_INHERIT", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_INHERIT), (intptr_t)0 },
    { "CSS_PRIMITIVE_VALUE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_PRIMITIVE_VALUE), (intptr_t)0 },
    { "CSS_VALUE_LIST", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_VALUE_LIST), (intptr_t)0 },
    { "CSS_CUSTOM", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_CUSTOM), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSValueConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSCSSValueConstructorTableValues, 0 };
#else
    { 8, 7, JSCSSValueConstructorTableValues, 0 };
#endif

class JSCSSValueConstructor : public DOMConstructorObject {
public:
    JSCSSValueConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSCSSValueConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSCSSValuePrototype::self(exec, globalObject), None);
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

const ClassInfo JSCSSValueConstructor::s_info = { "CSSValueConstructor", 0, &JSCSSValueConstructorTable, 0 };

bool JSCSSValueConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSValueConstructor, DOMObject>(exec, &JSCSSValueConstructorTable, this, propertyName, slot);
}

bool JSCSSValueConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSValueConstructor, DOMObject>(exec, &JSCSSValueConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSCSSValuePrototypeTableValues[5] =
{
    { "CSS_INHERIT", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_INHERIT), (intptr_t)0 },
    { "CSS_PRIMITIVE_VALUE", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_PRIMITIVE_VALUE), (intptr_t)0 },
    { "CSS_VALUE_LIST", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_VALUE_LIST), (intptr_t)0 },
    { "CSS_CUSTOM", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSValueCSS_CUSTOM), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSValuePrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSCSSValuePrototypeTableValues, 0 };
#else
    { 8, 7, JSCSSValuePrototypeTableValues, 0 };
#endif

const ClassInfo JSCSSValuePrototype::s_info = { "CSSValuePrototype", 0, &JSCSSValuePrototypeTable, 0 };

JSObject* JSCSSValuePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSCSSValue>(exec, globalObject);
}

bool JSCSSValuePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSValuePrototype, JSObject>(exec, &JSCSSValuePrototypeTable, this, propertyName, slot);
}

bool JSCSSValuePrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSValuePrototype, JSObject>(exec, &JSCSSValuePrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSCSSValue::s_info = { "CSSValue", 0, &JSCSSValueTable, 0 };

JSCSSValue::JSCSSValue(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<CSSValue> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSCSSValue::~JSCSSValue()
{
    forgetDOMObject(this, impl());
}

JSObject* JSCSSValue::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSCSSValuePrototype(JSCSSValuePrototype::createStructure(globalObject->objectPrototype()));
}

bool JSCSSValue::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSValue, Base>(exec, &JSCSSValueTable, this, propertyName, slot);
}

bool JSCSSValue::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSValue, Base>(exec, &JSCSSValueTable, this, propertyName, descriptor);
}

JSValue jsCSSValueCssText(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSValue* castedThis = static_cast<JSCSSValue*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSValue* imp = static_cast<CSSValue*>(castedThis->impl());
    JSValue result = jsStringOrNull(exec, imp->cssText());
    return result;
}

JSValue jsCSSValueCssValueType(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSValue* castedThis = static_cast<JSCSSValue*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSValue* imp = static_cast<CSSValue*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->cssValueType());
    return result;
}

JSValue jsCSSValueConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSValue* domObject = static_cast<JSCSSValue*>(asObject(slotBase));
    return JSCSSValue::getConstructor(exec, domObject->globalObject());
}
void JSCSSValue::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSCSSValue, Base>(exec, propertyName, value, &JSCSSValueTable, this, slot);
}

void setJSCSSValueCssText(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSCSSValue* castedThisObj = static_cast<JSCSSValue*>(thisObject);
    CSSValue* imp = static_cast<CSSValue*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    imp->setCssText(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

JSValue JSCSSValue::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSCSSValueConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

// Constant getters

JSValue jsCSSValueCSS_INHERIT(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(0));
}

JSValue jsCSSValueCSS_PRIMITIVE_VALUE(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsCSSValueCSS_VALUE_LIST(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsCSSValueCSS_CUSTOM(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(3));
}

CSSValue* toCSSValue(JSC::JSValue value)
{
    return value.inherits(&JSCSSValue::s_info) ? static_cast<JSCSSValue*>(asObject(value))->impl() : 0;
}

}
