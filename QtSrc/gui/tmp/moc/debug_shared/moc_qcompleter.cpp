/****************************************************************************
** Meta object code from reading C++ file 'qcompleter.h'
**
** Created: Fri Sep 2 00:06:32 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../util/qcompleter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcompleter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCompleter[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       8,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x05,
      42,   36,   11,   11, 0x05,
      65,   12,   11,   11, 0x05,
      86,   36,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     118,  111,   11,   11, 0x0a,
     152,  147,   11,   11, 0x0a,
     168,   11,   11,   11, 0x2a,
     184,  179,   11,   11, 0x0a,
     204,   11,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,

 // properties: name, type, flags
     339,  331, 0x0a095103,
     369,  356, 0x0009510b,
     397,  382, 0x0009510b,
     416,  412, 0x02095103,
     433,  412, 0x02095103,
     448,  412, 0x02095103,
     484,  464, 0x0009510b,
     505,  500, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_QCompleter[] = {
    "QCompleter\0\0text\0activated(QString)\0"
    "index\0activated(QModelIndex)\0"
    "highlighted(QString)\0highlighted(QModelIndex)\0"
    "prefix\0setCompletionPrefix(QString)\0"
    "rect\0complete(QRect)\0complete()\0wrap\0"
    "setWrapAround(bool)\0_q_complete(QModelIndex)\0"
    "_q_completionSelected(QItemSelection)\0"
    "_q_autoResizePopup()\0"
    "_q_fileSystemModelDirectoryLoaded(QString)\0"
    "QString\0completionPrefix\0ModelSorting\0"
    "modelSorting\0CompletionMode\0completionMode\0"
    "int\0completionColumn\0completionRole\0"
    "maxVisibleItems\0Qt::CaseSensitivity\0"
    "caseSensitivity\0bool\0wrapAround\0"
};

const QMetaObject QCompleter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QCompleter,
      qt_meta_data_QCompleter, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QCompleter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QCompleter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QCompleter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCompleter))
        return static_cast<void*>(const_cast< QCompleter*>(this));
    return QObject::qt_metacast(_clname);
}

int QCompleter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: highlighted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: highlighted((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: setCompletionPrefix((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: complete((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 6: complete(); break;
        case 7: setWrapAround((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: d_func()->_q_complete((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: d_func()->_q_completionSelected((*reinterpret_cast< const QItemSelection(*)>(_a[1]))); break;
        case 10: d_func()->_q_autoResizePopup(); break;
        case 11: d_func()->_q_fileSystemModelDirectoryLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = completionPrefix(); break;
        case 1: *reinterpret_cast< ModelSorting*>(_v) = modelSorting(); break;
        case 2: *reinterpret_cast< CompletionMode*>(_v) = completionMode(); break;
        case 3: *reinterpret_cast< int*>(_v) = completionColumn(); break;
        case 4: *reinterpret_cast< int*>(_v) = completionRole(); break;
        case 5: *reinterpret_cast< int*>(_v) = maxVisibleItems(); break;
        case 6: *reinterpret_cast< Qt::CaseSensitivity*>(_v) = caseSensitivity(); break;
        case 7: *reinterpret_cast< bool*>(_v) = wrapAround(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setCompletionPrefix(*reinterpret_cast< QString*>(_v)); break;
        case 1: setModelSorting(*reinterpret_cast< ModelSorting*>(_v)); break;
        case 2: setCompletionMode(*reinterpret_cast< CompletionMode*>(_v)); break;
        case 3: setCompletionColumn(*reinterpret_cast< int*>(_v)); break;
        case 4: setCompletionRole(*reinterpret_cast< int*>(_v)); break;
        case 5: setMaxVisibleItems(*reinterpret_cast< int*>(_v)); break;
        case 6: setCaseSensitivity(*reinterpret_cast< Qt::CaseSensitivity*>(_v)); break;
        case 7: setWrapAround(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QCompleter::activated(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCompleter::activated(const QModelIndex & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QCompleter::highlighted(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QCompleter::highlighted(const QModelIndex & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
