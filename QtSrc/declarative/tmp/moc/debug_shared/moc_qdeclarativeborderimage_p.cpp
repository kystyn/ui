/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativeborderimage_p.h'
**
** Created: Fri Sep 2 01:13:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphicsitems/qdeclarativeborderimage_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativeborderimage_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeBorderImage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   44, // properties
       1,   60, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,
      53,   24,   24,   24, 0x05,
      79,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,   24,   24,   24, 0x08,
     110,   24,   24,   24, 0x08,
     128,   24,   24,   24, 0x08,

 // properties: name, type, flags
     172,  149, 0x00095409,
     188,  179, 0x0049510b,
     207,  179, 0x0049510b,
     230,  224, 0x15495001,

 // properties: notify_signal_id
       0,
       0,
       1,
       2,

 // enums: name, flags, count, data
     179, 0x0,    3,   64,

 // enum data: key, value
     241, uint(QDeclarativeBorderImage::Stretch),
     249, uint(QDeclarativeBorderImage::Repeat),
     256, uint(QDeclarativeBorderImage::Round),

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeBorderImage[] = {
    "QDeclarativeBorderImage\0\0"
    "horizontalTileModeChanged()\0"
    "verticalTileModeChanged()\0sourceSizeChanged()\0"
    "doUpdate()\0requestFinished()\0"
    "sciRequestFinished()\0QDeclarativeScaleGrid*\0"
    "border\0TileMode\0horizontalTileMode\0"
    "verticalTileMode\0QSize\0sourceSize\0"
    "Stretch\0Repeat\0Round\0"
};

const QMetaObject QDeclarativeBorderImage::staticMetaObject = {
    { &QDeclarativeImageBase::staticMetaObject, qt_meta_stringdata_QDeclarativeBorderImage,
      qt_meta_data_QDeclarativeBorderImage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeBorderImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeBorderImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeBorderImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeBorderImage))
        return static_cast<void*>(const_cast< QDeclarativeBorderImage*>(this));
    return QDeclarativeImageBase::qt_metacast(_clname);
}

int QDeclarativeBorderImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeImageBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: horizontalTileModeChanged(); break;
        case 1: verticalTileModeChanged(); break;
        case 2: sourceSizeChanged(); break;
        case 3: doUpdate(); break;
        case 4: requestFinished(); break;
        case 5: sciRequestFinished(); break;
        default: ;
        }
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeScaleGrid**>(_v) = border(); break;
        case 1: *reinterpret_cast< TileMode*>(_v) = horizontalTileMode(); break;
        case 2: *reinterpret_cast< TileMode*>(_v) = verticalTileMode(); break;
        case 3: *reinterpret_cast< QSize*>(_v) = sourceSize(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setHorizontalTileMode(*reinterpret_cast< TileMode*>(_v)); break;
        case 2: setVerticalTileMode(*reinterpret_cast< TileMode*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativeBorderImage::horizontalTileModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeBorderImage::verticalTileModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QDeclarativeBorderImage::sourceSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
