/****************************************************************************
** Meta object code from reading C++ file 'q3socket.h'
**
** Created: Fri Sep 2 00:25:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../network/q3socket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'q3socket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Q3Socket[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      22,    9,    9,    9, 0x05,
      34,    9,    9,    9, 0x05,
      53,    9,    9,    9, 0x05,
      76,    9,    9,    9, 0x05,
      95,   88,    9,    9, 0x05,
     113,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     130,  124,    9,    9, 0x09,
     144,    9,    9,    9, 0x29,
     154,    9,    9,    9, 0x09,
     165,    9,    9,    9, 0x08,
     181,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Q3Socket[] = {
    "Q3Socket\0\0hostFound()\0connected()\0"
    "connectionClosed()\0delayedCloseFinished()\0"
    "readyRead()\0nbytes\0bytesWritten(int)\0"
    "error(int)\0force\0sn_read(bool)\0sn_read()\0"
    "sn_write()\0tryConnecting()\0"
    "emitErrorConnectionRefused()\0"
};

const QMetaObject Q3Socket::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_Q3Socket,
      qt_meta_data_Q3Socket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Q3Socket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Q3Socket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Q3Socket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Q3Socket))
        return static_cast<void*>(const_cast< Q3Socket*>(this));
    return QIODevice::qt_metacast(_clname);
}

int Q3Socket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hostFound(); break;
        case 1: connected(); break;
        case 2: connectionClosed(); break;
        case 3: delayedCloseFinished(); break;
        case 4: readyRead(); break;
        case 5: bytesWritten((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: error((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: sn_read((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: sn_read(); break;
        case 9: sn_write(); break;
        case 10: tryConnecting(); break;
        case 11: emitErrorConnectionRefused(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Q3Socket::hostFound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Q3Socket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Q3Socket::connectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Q3Socket::delayedCloseFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Q3Socket::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void Q3Socket::bytesWritten(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Q3Socket::error(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
