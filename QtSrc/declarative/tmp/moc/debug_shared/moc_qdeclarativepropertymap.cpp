/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativepropertymap.h'
**
** Created: Fri Sep 2 01:12:51 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../util/qdeclarativepropertymap.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativepropertymap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativePropertyMap[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   25,   24,   24, 0x05,

 // methods: signature, parameters, type, tag, flags
      78,   24,   66,   24, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativePropertyMap[] = {
    "QDeclarativePropertyMap\0\0key,value\0"
    "valueChanged(QString,QVariant)\0"
    "QStringList\0keys()\0"
};

const QMetaObject QDeclarativePropertyMap::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativePropertyMap,
      qt_meta_data_QDeclarativePropertyMap, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativePropertyMap::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativePropertyMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativePropertyMap::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativePropertyMap))
        return static_cast<void*>(const_cast< QDeclarativePropertyMap*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativePropertyMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 1: { QStringList _r = keys();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QDeclarativePropertyMap::valueChanged(const QString & _t1, const QVariant & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
