/****************************************************************************
** Meta object code from reading C++ file 'DnsPrefetchHelper.h'
**
** Created: Fri Sep 2 02:35:44 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../platform/network/qt/DnsPrefetchHelper.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DnsPrefetchHelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebCore__DnsPrefetchHelper[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      37,   28,   27,   27, 0x0a,
      53,   27,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WebCore__DnsPrefetchHelper[] = {
    "WebCore::DnsPrefetchHelper\0\0hostname\0"
    "lookup(QString)\0lookedUp(QHostInfo)\0"
};

const QMetaObject WebCore::DnsPrefetchHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebCore__DnsPrefetchHelper,
      qt_meta_data_WebCore__DnsPrefetchHelper, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebCore::DnsPrefetchHelper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebCore::DnsPrefetchHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebCore::DnsPrefetchHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebCore__DnsPrefetchHelper))
        return static_cast<void*>(const_cast< DnsPrefetchHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int WebCore::DnsPrefetchHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: lookup((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: lookedUp((*reinterpret_cast< const QHostInfo(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
