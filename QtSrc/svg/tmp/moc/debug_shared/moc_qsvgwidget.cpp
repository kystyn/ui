/****************************************************************************
** Meta object code from reading C++ file 'qsvgwidget.h'
**
** Created: Fri Sep 2 00:52:17 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qsvgwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsvgwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSvgWidget[] = {

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
      17,   12,   11,   11, 0x0a,
      40,   31,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSvgWidget[] = {
    "QSvgWidget\0\0file\0load(QString)\0contents\0"
    "load(QByteArray)\0"
};

const QMetaObject QSvgWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QSvgWidget,
      qt_meta_data_QSvgWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSvgWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSvgWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSvgWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSvgWidget))
        return static_cast<void*>(const_cast< QSvgWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QSvgWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: load((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
