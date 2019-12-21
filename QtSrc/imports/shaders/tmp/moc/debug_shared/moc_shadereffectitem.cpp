/****************************************************************************
** Meta object code from reading C++ file 'shadereffectitem.h'
**
** Created: Fri Sep 2 03:54:43 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../shadereffectitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shadereffectitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShaderEffectItem[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      42,   17,   17,   17, 0x05,
      64,   17,   17,   17, 0x05,
      82,   17,   17,   17, 0x05,
      98,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,  122,   17,   17, 0x08,
     146,   17,   17,   17, 0x08,
     171,   17,   17,   17, 0x08,

 // properties: name, type, flags
     191,  183, 0x0a495103,
     206,  183, 0x0a495103,
     224,  219, 0x01495103,
     239,  233, 0x15495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       4,

       0        // eod
};

static const char qt_meta_stringdata_ShaderEffectItem[] = {
    "ShaderEffectItem\0\0fragmentShaderChanged()\0"
    "vertexShaderChanged()\0blendingChanged()\0"
    "activeChanged()\0meshResolutionChanged()\0"
    "index\0changeSource(int)\0"
    "handleVisibilityChange()\0markDirty()\0"
    "QString\0fragmentShader\0vertexShader\0"
    "bool\0blending\0QSize\0meshResolution\0"
};

const QMetaObject ShaderEffectItem::staticMetaObject = {
    { &QDeclarativeItem::staticMetaObject, qt_meta_stringdata_ShaderEffectItem,
      qt_meta_data_ShaderEffectItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShaderEffectItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShaderEffectItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShaderEffectItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShaderEffectItem))
        return static_cast<void*>(const_cast< ShaderEffectItem*>(this));
    if (!strcmp(_clname, "com.trolltech.qml.QDeclarativeParserStatus"))
        return static_cast< QDeclarativeParserStatus*>(const_cast< ShaderEffectItem*>(this));
    return QDeclarativeItem::qt_metacast(_clname);
}

int ShaderEffectItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fragmentShaderChanged(); break;
        case 1: vertexShaderChanged(); break;
        case 2: blendingChanged(); break;
        case 3: activeChanged(); break;
        case 4: meshResolutionChanged(); break;
        case 5: changeSource((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: handleVisibilityChange(); break;
        case 7: markDirty(); break;
        default: ;
        }
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = fragmentShader(); break;
        case 1: *reinterpret_cast< QString*>(_v) = vertexShader(); break;
        case 2: *reinterpret_cast< bool*>(_v) = blending(); break;
        case 3: *reinterpret_cast< QSize*>(_v) = meshResolution(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFragmentShader(*reinterpret_cast< QString*>(_v)); break;
        case 1: setVertexShader(*reinterpret_cast< QString*>(_v)); break;
        case 2: setBlending(*reinterpret_cast< bool*>(_v)); break;
        case 3: setMeshResolution(*reinterpret_cast< QSize*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ShaderEffectItem::fragmentShaderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ShaderEffectItem::vertexShaderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ShaderEffectItem::blendingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ShaderEffectItem::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ShaderEffectItem::meshResolutionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
