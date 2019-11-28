/****************************************************************************
** Meta object code from reading C++ file 'qnetworkconfigmanager_p.h'
**
** Created: Thu Sep 1 23:51:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../bearer/qnetworkconfigmanager_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkconfigmanager_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QNetworkConfigurationManagerPrivate[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      44,   37,   36,   36, 0x05,
      86,   37,   36,   36, 0x05,
     130,   36,   36,   36, 0x05,
     160,   37,   36,   36, 0x05,
     213,  204,   36,   36, 0x05,
     238,   36,   36,   36, 0x05,

 // slots: signature, parameters, type, tag, flags
     246,   36,   36,   36, 0x0a,
     273,  269,   36,   36, 0x08,
     329,  269,   36,   36, 0x08,
     387,  269,   36,   36, 0x08,
     445,   36,   36,   36, 0x08,

 // methods: signature, parameters, type, tag, flags
     459,   36,   36,   36, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_QNetworkConfigurationManagerPrivate[] = {
    "QNetworkConfigurationManagerPrivate\0"
    "\0config\0configurationAdded(QNetworkConfiguration)\0"
    "configurationRemoved(QNetworkConfiguration)\0"
    "configurationUpdateComplete()\0"
    "configurationChanged(QNetworkConfiguration)\0"
    "isOnline\0onlineStateChanged(bool)\0"
    "abort()\0updateConfigurations()\0ptr\0"
    "configurationAdded(QNetworkConfigurationPrivatePointer)\0"
    "configurationRemoved(QNetworkConfigurationPrivatePointer)\0"
    "configurationChanged(QNetworkConfigurationPrivatePointer)\0"
    "pollEngines()\0startPolling()\0"
};

const QMetaObject QNetworkConfigurationManagerPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QNetworkConfigurationManagerPrivate,
      qt_meta_data_QNetworkConfigurationManagerPrivate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QNetworkConfigurationManagerPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QNetworkConfigurationManagerPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QNetworkConfigurationManagerPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QNetworkConfigurationManagerPrivate))
        return static_cast<void*>(const_cast< QNetworkConfigurationManagerPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int QNetworkConfigurationManagerPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: configurationAdded((*reinterpret_cast< const QNetworkConfiguration(*)>(_a[1]))); break;
        case 1: configurationRemoved((*reinterpret_cast< const QNetworkConfiguration(*)>(_a[1]))); break;
        case 2: configurationUpdateComplete(); break;
        case 3: configurationChanged((*reinterpret_cast< const QNetworkConfiguration(*)>(_a[1]))); break;
        case 4: onlineStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: abort(); break;
        case 6: updateConfigurations(); break;
        case 7: configurationAdded((*reinterpret_cast< QNetworkConfigurationPrivatePointer(*)>(_a[1]))); break;
        case 8: configurationRemoved((*reinterpret_cast< QNetworkConfigurationPrivatePointer(*)>(_a[1]))); break;
        case 9: configurationChanged((*reinterpret_cast< QNetworkConfigurationPrivatePointer(*)>(_a[1]))); break;
        case 10: pollEngines(); break;
        case 11: startPolling(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QNetworkConfigurationManagerPrivate::configurationAdded(const QNetworkConfiguration & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QNetworkConfigurationManagerPrivate::configurationRemoved(const QNetworkConfiguration & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QNetworkConfigurationManagerPrivate::configurationUpdateComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QNetworkConfigurationManagerPrivate::configurationChanged(const QNetworkConfiguration & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QNetworkConfigurationManagerPrivate::onlineStateChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QNetworkConfigurationManagerPrivate::abort()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
