/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativetranslate_p.h'
**
** Created: Fri Sep 2 01:13:41 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphicsitems/qdeclarativetranslate_p.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativetranslate_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeTranslate[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      34,   22,   22,   22, 0x05,

 // properties: name, type, flags
      51,   45, (QMetaType::QReal << 24) | 0x00495103,
      53,   45, (QMetaType::QReal << 24) | 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeTranslate[] = {
    "QDeclarativeTranslate\0\0xChanged()\0"
    "yChanged()\0qreal\0x\0y\0"
};

const QMetaObject QDeclarativeTranslate::staticMetaObject = {
    { &QGraphicsTransform::staticMetaObject, qt_meta_stringdata_QDeclarativeTranslate,
      qt_meta_data_QDeclarativeTranslate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeTranslate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeTranslate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeTranslate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeTranslate))
        return static_cast<void*>(const_cast< QDeclarativeTranslate*>(this));
    return QGraphicsTransform::qt_metacast(_clname);
}

int QDeclarativeTranslate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsTransform::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: xChanged(); break;
        case 1: yChanged(); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = x(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = y(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setX(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setY(*reinterpret_cast< qreal*>(_v)); break;
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
void QDeclarativeTranslate::xChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeTranslate::yChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
