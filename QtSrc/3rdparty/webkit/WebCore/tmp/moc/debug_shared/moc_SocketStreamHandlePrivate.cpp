/****************************************************************************
** Meta object code from reading C++ file 'SocketStreamHandlePrivate.h'
**
** Created: Fri Sep 2 02:35:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../platform/network/qt/SocketStreamHandlePrivate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SocketStreamHandlePrivate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebCore__SocketStreamHandlePrivate[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x0a,
      54,   35,   35,   35, 0x0a,
      85,   76,   72,   35, 0x0a,
     107,   35,   35,   35, 0x0a,
     115,   35,   35,   35, 0x0a,
     132,   35,   35,   35, 0x0a,
     147,   35,   35,   35, 0x0a,
     189,   35,   35,   35, 0x0a,
     212,   35,   35,   35, 0x0a,
     237,   35,   35,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WebCore__SocketStreamHandlePrivate[] = {
    "WebCore::SocketStreamHandlePrivate\0\0"
    "socketConnected()\0socketReadyRead()\0"
    "int\0data,len\0send(const char*,int)\0"
    "close()\0socketSentdata()\0socketClosed()\0"
    "socketError(QAbstractSocket::SocketError)\0"
    "socketClosedCallback()\0socketErrorCallback(int)\0"
    "socketSslErrors(QList<QSslError>)\0"
};

const QMetaObject WebCore::SocketStreamHandlePrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebCore__SocketStreamHandlePrivate,
      qt_meta_data_WebCore__SocketStreamHandlePrivate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebCore::SocketStreamHandlePrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebCore::SocketStreamHandlePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebCore::SocketStreamHandlePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebCore__SocketStreamHandlePrivate))
        return static_cast<void*>(const_cast< SocketStreamHandlePrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int WebCore::SocketStreamHandlePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: socketConnected(); break;
        case 1: socketReadyRead(); break;
        case 2: { int _r = send((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: close(); break;
        case 4: socketSentdata(); break;
        case 5: socketClosed(); break;
        case 6: socketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: socketClosedCallback(); break;
        case 8: socketErrorCallback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: socketSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
