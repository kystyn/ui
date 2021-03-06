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

#include "JSSVGPathSegCurvetoQuadraticRel.h"

#include "SVGPathSegCurvetoQuadratic.h"
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSSVGPathSegCurvetoQuadraticRel);

/* Hash table */

static const HashTableValue JSSVGPathSegCurvetoQuadraticRelTableValues[6] =
{
    { "x", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticRelX), (intptr_t)setJSSVGPathSegCurvetoQuadraticRelX },
    { "y", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticRelY), (intptr_t)setJSSVGPathSegCurvetoQuadraticRelY },
    { "x1", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticRelX1), (intptr_t)setJSSVGPathSegCurvetoQuadraticRelX1 },
    { "y1", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticRelY1), (intptr_t)setJSSVGPathSegCurvetoQuadraticRelY1 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsSVGPathSegCurvetoQuadraticRelConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegCurvetoQuadraticRelTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 15, JSSVGPathSegCurvetoQuadraticRelTableValues, 0 };
#else
    { 16, 15, JSSVGPathSegCurvetoQuadraticRelTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSSVGPathSegCurvetoQuadraticRelConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegCurvetoQuadraticRelConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGPathSegCurvetoQuadraticRelConstructorTableValues, 0 };
#else
    { 1, 0, JSSVGPathSegCurvetoQuadraticRelConstructorTableValues, 0 };
#endif

class JSSVGPathSegCurvetoQuadraticRelConstructor : public DOMConstructorObject {
public:
    JSSVGPathSegCurvetoQuadraticRelConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSSVGPathSegCurvetoQuadraticRelConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSSVGPathSegCurvetoQuadraticRelPrototype::self(exec, globalObject), None);
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

const ClassInfo JSSVGPathSegCurvetoQuadraticRelConstructor::s_info = { "SVGPathSegCurvetoQuadraticRelConstructor", 0, &JSSVGPathSegCurvetoQuadraticRelConstructorTable, 0 };

bool JSSVGPathSegCurvetoQuadraticRelConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGPathSegCurvetoQuadraticRelConstructor, DOMObject>(exec, &JSSVGPathSegCurvetoQuadraticRelConstructorTable, this, propertyName, slot);
}

bool JSSVGPathSegCurvetoQuadraticRelConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGPathSegCurvetoQuadraticRelConstructor, DOMObject>(exec, &JSSVGPathSegCurvetoQuadraticRelConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSSVGPathSegCurvetoQuadraticRelPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSSVGPathSegCurvetoQuadraticRelPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSSVGPathSegCurvetoQuadraticRelPrototypeTableValues, 0 };
#else
    { 1, 0, JSSVGPathSegCurvetoQuadraticRelPrototypeTableValues, 0 };
#endif

const ClassInfo JSSVGPathSegCurvetoQuadraticRelPrototype::s_info = { "SVGPathSegCurvetoQuadraticRelPrototype", 0, &JSSVGPathSegCurvetoQuadraticRelPrototypeTable, 0 };

JSObject* JSSVGPathSegCurvetoQuadraticRelPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSSVGPathSegCurvetoQuadraticRel>(exec, globalObject);
}

const ClassInfo JSSVGPathSegCurvetoQuadraticRel::s_info = { "SVGPathSegCurvetoQuadraticRel", &JSSVGPathSeg::s_info, &JSSVGPathSegCurvetoQuadraticRelTable, 0 };

JSSVGPathSegCurvetoQuadraticRel::JSSVGPathSegCurvetoQuadraticRel(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<SVGPathSegCurvetoQuadraticRel> impl)
    : JSSVGPathSeg(structure, globalObject, impl)
{
}

JSObject* JSSVGPathSegCurvetoQuadraticRel::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSSVGPathSegCurvetoQuadraticRelPrototype(JSSVGPathSegCurvetoQuadraticRelPrototype::createStructure(JSSVGPathSegPrototype::self(exec, globalObject)));
}

bool JSSVGPathSegCurvetoQuadraticRel::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSSVGPathSegCurvetoQuadraticRel, Base>(exec, &JSSVGPathSegCurvetoQuadraticRelTable, this, propertyName, slot);
}

bool JSSVGPathSegCurvetoQuadraticRel::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSSVGPathSegCurvetoQuadraticRel, Base>(exec, &JSSVGPathSegCurvetoQuadraticRelTable, this, propertyName, descriptor);
}

JSValue jsSVGPathSegCurvetoQuadraticRelX(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThis = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->x());
    return result;
}

JSValue jsSVGPathSegCurvetoQuadraticRelY(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThis = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->y());
    return result;
}

JSValue jsSVGPathSegCurvetoQuadraticRelX1(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThis = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->x1());
    return result;
}

JSValue jsSVGPathSegCurvetoQuadraticRelY1(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThis = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->y1());
    return result;
}

JSValue jsSVGPathSegCurvetoQuadraticRelConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSSVGPathSegCurvetoQuadraticRel* domObject = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(asObject(slotBase));
    return JSSVGPathSegCurvetoQuadraticRel::getConstructor(exec, domObject->globalObject());
}
void JSSVGPathSegCurvetoQuadraticRel::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSSVGPathSegCurvetoQuadraticRel, Base>(exec, propertyName, value, &JSSVGPathSegCurvetoQuadraticRelTable, this, slot);
}

void setJSSVGPathSegCurvetoQuadraticRelX(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThisObj = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(thisObject);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThisObj->impl());
    imp->setX(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

void setJSSVGPathSegCurvetoQuadraticRelY(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThisObj = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(thisObject);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThisObj->impl());
    imp->setY(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

void setJSSVGPathSegCurvetoQuadraticRelX1(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThisObj = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(thisObject);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThisObj->impl());
    imp->setX1(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

void setJSSVGPathSegCurvetoQuadraticRelY1(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSSVGPathSegCurvetoQuadraticRel* castedThisObj = static_cast<JSSVGPathSegCurvetoQuadraticRel*>(thisObject);
    SVGPathSegCurvetoQuadraticRel* imp = static_cast<SVGPathSegCurvetoQuadraticRel*>(castedThisObj->impl());
    imp->setY1(value.toFloat(exec));
    JSSVGContextCache::propagateSVGDOMChange(castedThisObj, imp->associatedAttributeName());
}

JSValue JSSVGPathSegCurvetoQuadraticRel::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSSVGPathSegCurvetoQuadraticRelConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}

#endif // ENABLE(SVG)
