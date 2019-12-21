/****************************************************************************
** Meta object code from reading C++ file 'qnativewifiengine.h'
**
** Created: Fri Sep 2 03:49:11 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qnativewifiengine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnativewifiengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QNativeWifiEngine[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      34,   18,   18,   18, 0x08,

 // methods: signature, parameters, type, tag, flags
      48,   18,   18,   18, 0x02,
      61,   18,   18,   18, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_QNativeWifiEngine[] = {
    "QNativeWifiEngine\0\0scanComplete()\0"
    "closeHandle()\0initialize()\0requestUpdate()\0"
};

const QMetaObject QNativeWifiEngine::staticMetaObject = {
    { &QBearerEngineImpl::staticMetaObject, qt_meta_stringdata_QNativeWifiEngine,
      qt_meta_data_QNativeWifiEngine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QNativeWifiEngine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QNativeWifiEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QNativeWifiEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QNativeWifiEngine))
        return static_cast<void*>(const_cast< QNativeWifiEngine*>(this));
    return QBearerEngineImpl::qt_metacast(_clname);
}

int QNativeWifiEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QBearerEngineImpl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scanComplete(); break;
        case 1: closeHandle(); break;
        case 2: initialize(); break;
        case 3: requestUpdate(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
