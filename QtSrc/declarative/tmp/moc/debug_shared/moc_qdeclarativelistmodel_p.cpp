/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativelistmodel_p.h'
**
** Created: Fri Sep 2 01:12:44 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../util/qdeclarativelistmodel_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativelistmodel_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeListModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   64, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,

 // methods: signature, parameters, type, tag, flags
      38,   22,   22,   22, 0x02,
      52,   46,   22,   22, 0x02,
      64,   22,   22,   22, 0x02,
      92,   85,   22,   22, 0x02,
     130,   46,  117,   22, 0x02,
     139,   85,   22,   22, 0x02,
     182,  161,   22,   22, 0x02,
     230,  216,   22,   22, 0x02,
     248,   22,   22,   22, 0x02,

 // properties: name, type, flags
     259,  255, 0x02495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeListModel[] = {
    "QDeclarativeListModel\0\0countChanged()\0"
    "clear()\0index\0remove(int)\0"
    "append(QScriptValue)\0index,\0"
    "insert(int,QScriptValue)\0QScriptValue\0"
    "get(int)\0set(int,QScriptValue)\0"
    "index,property,value\0"
    "setProperty(int,QString,QVariant)\0"
    "from,to,count\0move(int,int,int)\0sync()\0"
    "int\0count\0"
};

const QMetaObject QDeclarativeListModel::staticMetaObject = {
    { &QListModelInterface::staticMetaObject, qt_meta_stringdata_QDeclarativeListModel,
      qt_meta_data_QDeclarativeListModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeListModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeListModel))
        return static_cast<void*>(const_cast< QDeclarativeListModel*>(this));
    return QListModelInterface::qt_metacast(_clname);
}

int QDeclarativeListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListModelInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: countChanged(); break;
        case 1: clear(); break;
        case 2: remove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: append((*reinterpret_cast< const QScriptValue(*)>(_a[1]))); break;
        case 4: insert((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QScriptValue(*)>(_a[2]))); break;
        case 5: { QScriptValue _r = get((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 6: set((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QScriptValue(*)>(_a[2]))); break;
        case 7: setProperty((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3]))); break;
        case 8: move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: sync(); break;
        default: ;
        }
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = count(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativeListModel::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_QDeclarativeListElement[] = {

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

static const char qt_meta_stringdata_QDeclarativeListElement[] = {
    "QDeclarativeListElement\0"
};

const QMetaObject QDeclarativeListElement::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeListElement,
      qt_meta_data_QDeclarativeListElement, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeListElement::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeListElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeListElement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeListElement))
        return static_cast<void*>(const_cast< QDeclarativeListElement*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeListElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
