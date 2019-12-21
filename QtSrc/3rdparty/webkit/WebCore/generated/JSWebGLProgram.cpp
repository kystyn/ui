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

#if ENABLE(3D_CANVAS)

#include "JSWebGLProgram.h"

#include "WebGLProgram.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSWebGLProgram);

/* Hash table for prototype */

static const HashTableValue JSWebGLProgramPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSWebGLProgramPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSWebGLProgramPrototypeTableValues, 0 };
#else
    { 1, 0, JSWebGLProgramPrototypeTableValues, 0 };
#endif

const ClassInfo JSWebGLProgramPrototype::s_info = { "WebGLProgramPrototype", 0, &JSWebGLProgramPrototypeTable, 0 };

JSObject* JSWebGLProgramPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSWebGLProgram>(exec, globalObject);
}

const ClassInfo JSWebGLProgram::s_info = { "WebGLProgram", 0, 0, 0 };

JSWebGLProgram::JSWebGLProgram(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<WebGLProgram> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSWebGLProgram::~JSWebGLProgram()
{
    forgetDOMObject(this, impl());
}

JSObject* JSWebGLProgram::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSWebGLProgramPrototype(JSWebGLProgramPrototype::createStructure(globalObject->objectPrototype()));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, WebGLProgram* object)
{
    return getDOMObjectWrapper<JSWebGLProgram>(exec, globalObject, object);
}
WebGLProgram* toWebGLProgram(JSC::JSValue value)
{
    return value.inherits(&JSWebGLProgram::s_info) ? static_cast<JSWebGLProgram*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(3D_CANVAS)
