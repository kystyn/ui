/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativebehavior_p.h'
**
** Created: Fri Sep 2 01:12:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../util/qdeclarativebehavior_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativebehavior_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeBehavior[] = {

 // content:
       5,       // revision
       0,       // classname
       2,   14, // classinfo
       3,   18, // methods
       2,   33, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
      31,   21,
      47,   21,

 // signals: signature, parameters, type, tag, flags
      70,   69,   69,   69, 0x05,

 // slots: signature, parameters, type, tag, flags
      87,   69,   69,   69, 0x08,
     110,  108,   69,   69, 0x08,

 // properties: name, type, flags
      21,  187, 0x0009510b,
     223,  218, 0x01495103,

 // properties: notify_signal_id
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeBehavior[] = {
    "QDeclarativeBehavior\0animation\0"
    "DefaultProperty\0DeferredPropertyNames\0"
    "\0enabledChanged()\0componentFinalized()\0"
    ",\0"
    "qtAnimationStateChanged(QAbstractAnimation::State,QAbstractAnimation::"
    "State)\0"
    "QDeclarativeAbstractAnimation*\0bool\0"
    "enabled\0"
};

const QMetaObject QDeclarativeBehavior::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeBehavior,
      qt_meta_data_QDeclarativeBehavior, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeBehavior::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeBehavior::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeBehavior::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeBehavior))
        return static_cast<void*>(const_cast< QDeclarativeBehavior*>(this));
    if (!strcmp(_clname, "QDeclarativePropertyValueInterceptor"))
        return static_cast< QDeclarativePropertyValueInterceptor*>(const_cast< QDeclarativeBehavior*>(this));
    if (!strcmp(_clname, "com.trolltech.qml.QDeclarativePropertyValueInterceptor"))
        return static_cast< QDeclarativePropertyValueInterceptor*>(const_cast< QDeclarativeBehavior*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeBehavior::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enabledChanged(); break;
        case 1: componentFinalized(); break;
        case 2: qtAnimationStateChanged((*reinterpret_cast< QAbstractAnimation::State(*)>(_a[1])),(*reinterpret_cast< QAbstractAnimation::State(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeAbstractAnimation**>(_v) = animation(); break;
        case 1: *reinterpret_cast< bool*>(_v) = enabled(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setAnimation(*reinterpret_cast< QDeclarativeAbstractAnimation**>(_v)); break;
        case 1: setEnabled(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativeBehavior::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
