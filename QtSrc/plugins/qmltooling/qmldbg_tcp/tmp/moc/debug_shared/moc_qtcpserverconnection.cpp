/****************************************************************************
** Meta object code from reading C++ file 'qtcpserverconnection.h'
**
** Created: Fri Sep 2 03:53:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qtcpserverconnection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtcpserverconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QTcpServerConnection[] = {

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
      22,   21,   21,   21, 0x08,
      34,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QTcpServerConnection[] = {
    "QTcpServerConnection\0\0readyRead()\0"
    "newConnection()\0"
};

const QMetaObject QTcpServerConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QTcpServerConnection,
      qt_meta_data_QTcpServerConnection, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QTcpServerConnection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QTcpServerConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QTcpServerConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QTcpServerConnection))
        return static_cast<void*>(const_cast< QTcpServerConnection*>(this));
    if (!strcmp(_clname, "QDeclarativeDebugServerConnection"))
        return static_cast< QDeclarativeDebugServerConnection*>(const_cast< QTcpServerConnection*>(this));
    if (!strcmp(_clname, "com.trolltech.Qt.QDeclarativeDebugServerConnection/1.0"))
        return static_cast< QDeclarativeDebugServerConnection*>(const_cast< QTcpServerConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int QTcpServerConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readyRead(); break;
        case 1: newConnection(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
