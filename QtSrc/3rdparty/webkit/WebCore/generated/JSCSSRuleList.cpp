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
#include "JSCSSRuleList.h"

#include "CSSRule.h"
#include "CSSRuleList.h"
#include "JSCSSRule.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSCSSRuleList);

/* Hash table */

static const HashTableValue JSCSSRuleListTableValues[3] =
{
    { "length", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleListLength), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsCSSRuleListConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSRuleListTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSCSSRuleListTableValues, 0 };
#else
    { 5, 3, JSCSSRuleListTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSCSSRuleListConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSRuleListConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSCSSRuleListConstructorTableValues, 0 };
#else
    { 1, 0, JSCSSRuleListConstructorTableValues, 0 };
#endif

class JSCSSRuleListConstructor : public DOMConstructorObject {
public:
    JSCSSRuleListConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSCSSRuleListConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSCSSRuleListPrototype::self(exec, globalObject), None);
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

const ClassInfo JSCSSRuleListConstructor::s_info = { "CSSRuleListConstructor", 0, &JSCSSRuleListConstructorTable, 0 };

bool JSCSSRuleListConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSRuleListConstructor, DOMObject>(exec, &JSCSSRuleListConstructorTable, this, propertyName, slot);
}

bool JSCSSRuleListConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSRuleListConstructor, DOMObject>(exec, &JSCSSRuleListConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSCSSRuleListPrototypeTableValues[2] =
{
    { "item", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsCSSRuleListPrototypeFunctionItem), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSRuleListPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSCSSRuleListPrototypeTableValues, 0 };
#else
    { 2, 1, JSCSSRuleListPrototypeTableValues, 0 };
#endif

const ClassInfo JSCSSRuleListPrototype::s_info = { "CSSRuleListPrototype", 0, &JSCSSRuleListPrototypeTable, 0 };

JSObject* JSCSSRuleListPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSCSSRuleList>(exec, globalObject);
}

bool JSCSSRuleListPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSCSSRuleListPrototypeTable, this, propertyName, slot);
}

bool JSCSSRuleListPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSCSSRuleListPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSCSSRuleList::s_info = { "CSSRuleList", 0, &JSCSSRuleListTable, 0 };

JSCSSRuleList::JSCSSRuleList(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<CSSRuleList> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSCSSRuleList::~JSCSSRuleList()
{
    forgetDOMObject(this, impl());
}

JSObject* JSCSSRuleList::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSCSSRuleListPrototype(JSCSSRuleListPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSCSSRuleList::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    const HashEntry* entry = JSCSSRuleListTable.entry(exec, propertyName);
    if (entry) {
        slot.setCustom(this, entry->propertyGetter());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<CSSRuleList*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    return getStaticValueSlot<JSCSSRuleList, Base>(exec, &JSCSSRuleListTable, this, propertyName, slot);
}

bool JSCSSRuleList::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    const HashEntry* entry = JSCSSRuleListTable.entry(exec, propertyName);
    if (entry) {
        PropertySlot slot;
        slot.setCustom(this, entry->propertyGetter());
        descriptor.setDescriptor(slot.getValue(exec, propertyName), entry->attributes());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<CSSRuleList*>(impl())->length()) {
        PropertySlot slot;
        slot.setCustomIndex(this, index, indexGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), DontDelete | ReadOnly);
        return true;
    }
    return getStaticValueDescriptor<JSCSSRuleList, Base>(exec, &JSCSSRuleListTable, this, propertyName, descriptor);
}

bool JSCSSRuleList::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<CSSRuleList*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue jsCSSRuleListLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRuleList* castedThis = static_cast<JSCSSRuleList*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    CSSRuleList* imp = static_cast<CSSRuleList*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->length());
    return result;
}

JSValue jsCSSRuleListConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSCSSRuleList* domObject = static_cast<JSCSSRuleList*>(asObject(slotBase));
    return JSCSSRuleList::getConstructor(exec, domObject->globalObject());
}
void JSCSSRuleList::getOwnPropertyNames(ExecState* exec, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    for (unsigned i = 0; i < static_cast<CSSRuleList*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getOwnPropertyNames(exec, propertyNames, mode);
}

JSValue JSCSSRuleList::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSCSSRuleListConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsCSSRuleListPrototypeFunctionItem(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSCSSRuleList::s_info))
        return throwError(exec, TypeError);
    JSCSSRuleList* castedThisObj = static_cast<JSCSSRuleList*>(asObject(thisValue));
    CSSRuleList* imp = static_cast<CSSRuleList*>(castedThisObj->impl());
    unsigned index = args.at(0).toInt32(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->item(index)));
    return result;
}


JSValue JSCSSRuleList::indexGetter(ExecState* exec, JSValue slotBase, unsigned index)
{
    JSCSSRuleList* thisObj = static_cast<JSCSSRuleList*>(asObject(slotBase));
    return toJS(exec, thisObj->globalObject(), static_cast<CSSRuleList*>(thisObj->impl())->item(index));
}
JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, CSSRuleList* object)
{
    return getDOMObjectWrapper<JSCSSRuleList>(exec, globalObject, object);
}
CSSRuleList* toCSSRuleList(JSC::JSValue value)
{
    return value.inherits(&JSCSSRuleList::s_info) ? static_cast<JSCSSRuleList*>(asObject(value))->impl() : 0;
}

}
