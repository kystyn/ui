/****************************************************************************
** Meta object code from reading C++ file 'qcleanlooksstyle.h'
**
** Created: Fri Sep 2 00:07:40 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../styles/qcleanlooksstyle.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcleanlooksstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QCleanlooksStyle[] = {

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
      51,   24,   18,   17, 0x09,
     149,  129,   18,   17, 0x29,

       0        // eod
};

static const char qt_meta_stringdata_QCleanlooksStyle[] = {
    "QCleanlooksStyle\0\0QIcon\0"
    "standardIcon,option,widget\0"
    "standardIconImplementation(StandardPixmap,const QStyleOption*,const QW"
    "idget*)\0"
    "standardIcon,option\0"
    "standardIconImplementation(StandardPixmap,const QStyleOption*)\0"
};

const QMetaObject QCleanlooksStyle::staticMetaObject = {
    { &QWindowsStyle::staticMetaObject, qt_meta_stringdata_QCleanlooksStyle,
      qt_meta_data_QCleanlooksStyle, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QCleanlooksStyle::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QCleanlooksStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QCleanlooksStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QCleanlooksStyle))
        return static_cast<void*>(const_cast< QCleanlooksStyle*>(this));
    return QWindowsStyle::qt_metacast(_clname);
}

int QCleanlooksStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWindowsStyle::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QIcon _r = standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])),(*reinterpret_cast< const QWidget*(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        case 1: { QIcon _r = standardIconImplementation((*reinterpret_cast< StandardPixmap(*)>(_a[1])),(*reinterpret_cast< const QStyleOption*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QIcon*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
