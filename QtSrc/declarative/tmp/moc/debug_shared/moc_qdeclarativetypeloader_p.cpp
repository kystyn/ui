/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativetypeloader_p.h'
**
** Created: Fri Sep 2 01:14:08 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qml/qdeclarativetypeloader_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativetypeloader_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeDataLoader[] = {

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
      24,   23,   23,   23, 0x08,
      49,   47,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeDataLoader[] = {
    "QDeclarativeDataLoader\0\0networkReplyFinished()\0"
    ",\0networkReplyProgress(qint64,qint64)\0"
};

const QMetaObject QDeclarativeDataLoader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeDataLoader,
      qt_meta_data_QDeclarativeDataLoader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeDataLoader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeDataLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeDataLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeDataLoader))
        return static_cast<void*>(const_cast< QDeclarativeDataLoader*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeDataLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: networkReplyFinished(); break;
        case 1: networkReplyProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_QDeclarativeTypeLoader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeTypeLoader[] = {
    "QDeclarativeTypeLoader\0"
};

const QMetaObject QDeclarativeTypeLoader::staticMetaObject = {
    { &QDeclarativeDataLoader::staticMetaObject, qt_meta_stringdata_QDeclarativeTypeLoader,
      qt_meta_data_QDeclarativeTypeLoader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeTypeLoader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeTypeLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeTypeLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeTypeLoader))
        return static_cast<void*>(const_cast< QDeclarativeTypeLoader*>(this));
    return QDeclarativeDataLoader::qt_metacast(_clname);
}

int QDeclarativeTypeLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeDataLoader::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
