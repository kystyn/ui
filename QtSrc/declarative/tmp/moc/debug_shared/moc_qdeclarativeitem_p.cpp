/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativeitem_p.h'
**
** Created: Fri Sep 2 01:13:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphicsitems/qdeclarativeitem_p.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativeitem_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeContents[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeContents[] = {
    "QDeclarativeContents\0\0rectChanged(QRectF)\0"
};

const QMetaObject QDeclarativeContents::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeContents,
      qt_meta_data_QDeclarativeContents, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeContents::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeContents::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeContents::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeContents))
        return static_cast<void*>(const_cast< QDeclarativeContents*>(this));
    if (!strcmp(_clname, "QDeclarativeItemChangeListener"))
        return static_cast< QDeclarativeItemChangeListener*>(const_cast< QDeclarativeContents*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeContents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rectChanged((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QDeclarativeContents::rectChanged(QRectF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QDeclarativeKeyNavigationAttached[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       7,   49, // properties
       1,   77, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      35,   34,   34,   34, 0x05,
      49,   34,   34,   34, 0x05,
      64,   34,   34,   34, 0x05,
      76,   34,   34,   34, 0x05,
      90,   34,   34,   34, 0x05,
     103,   34,   34,   34, 0x05,
     120,   34,   34,   34, 0x05,

 // properties: name, type, flags
     156,  138, 0x0049510b,
     161,  138, 0x0049510b,
     167,  138, 0x0049510b,
     170,  138, 0x0049510b,
     175,  138, 0x0049510b,
     179,  138, 0x0049510b,
     196,  187, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

 // enums: name, flags, count, data
     187, 0x0,    2,   81,

 // enum data: key, value
     205, uint(QDeclarativeKeyNavigationAttached::BeforeItem),
     216, uint(QDeclarativeKeyNavigationAttached::AfterItem),

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeKeyNavigationAttached[] = {
    "QDeclarativeKeyNavigationAttached\0\0"
    "leftChanged()\0rightChanged()\0upChanged()\0"
    "downChanged()\0tabChanged()\0backtabChanged()\0"
    "priorityChanged()\0QDeclarativeItem*\0"
    "left\0right\0up\0down\0tab\0backtab\0Priority\0"
    "priority\0BeforeItem\0AfterItem\0"
};

const QMetaObject QDeclarativeKeyNavigationAttached::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeKeyNavigationAttached,
      qt_meta_data_QDeclarativeKeyNavigationAttached, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeKeyNavigationAttached::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeKeyNavigationAttached::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeKeyNavigationAttached::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeKeyNavigationAttached))
        return static_cast<void*>(const_cast< QDeclarativeKeyNavigationAttached*>(this));
    if (!strcmp(_clname, "QDeclarativeItemKeyFilter"))
        return static_cast< QDeclarativeItemKeyFilter*>(const_cast< QDeclarativeKeyNavigationAttached*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeKeyNavigationAttached::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: leftChanged(); break;
        case 1: rightChanged(); break;
        case 2: upChanged(); break;
        case 3: downChanged(); break;
        case 4: tabChanged(); break;
        case 5: backtabChanged(); break;
        case 6: priorityChanged(); break;
        default: ;
        }
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeItem**>(_v) = left(); break;
        case 1: *reinterpret_cast< QDeclarativeItem**>(_v) = right(); break;
        case 2: *reinterpret_cast< QDeclarativeItem**>(_v) = up(); break;
        case 3: *reinterpret_cast< QDeclarativeItem**>(_v) = down(); break;
        case 4: *reinterpret_cast< QDeclarativeItem**>(_v) = tab(); break;
        case 5: *reinterpret_cast< QDeclarativeItem**>(_v) = backtab(); break;
        case 6: *reinterpret_cast< Priority*>(_v) = priority(); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setLeft(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 1: setRight(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 2: setUp(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 3: setDown(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 4: setTab(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 5: setBacktab(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 6: setPriority(*reinterpret_cast< Priority*>(_v)); break;
        }
        _id -= 7;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativeKeyNavigationAttached::leftChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeKeyNavigationAttached::rightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QDeclarativeKeyNavigationAttached::upChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QDeclarativeKeyNavigationAttached::downChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void QDeclarativeKeyNavigationAttached::tabChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QDeclarativeKeyNavigationAttached::backtabChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QDeclarativeKeyNavigationAttached::priorityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
static const uint qt_meta_data_QDeclarativeLayoutMirroringAttached[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       2,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      37,   36,   36,   36, 0x05,
      54,   36,   36,   36, 0x05,

 // properties: name, type, flags
      84,   79, 0x01495107,
      92,   79, 0x01495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeLayoutMirroringAttached[] = {
    "QDeclarativeLayoutMirroringAttached\0"
    "\0enabledChanged()\0childrenInheritChanged()\0"
    "bool\0enabled\0childrenInherit\0"
};

const QMetaObject QDeclarativeLayoutMirroringAttached::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeLayoutMirroringAttached,
      qt_meta_data_QDeclarativeLayoutMirroringAttached, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeLayoutMirroringAttached::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeLayoutMirroringAttached::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeLayoutMirroringAttached::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeLayoutMirroringAttached))
        return static_cast<void*>(const_cast< QDeclarativeLayoutMirroringAttached*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeLayoutMirroringAttached::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enabledChanged(); break;
        case 1: childrenInheritChanged(); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = enabled(); break;
        case 1: *reinterpret_cast< bool*>(_v) = childrenInherit(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 1: setChildrenInherit(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 0: resetEnabled(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativeLayoutMirroringAttached::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeLayoutMirroringAttached::childrenInheritChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_QDeclarativeKeysAttached[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       3,  224, // properties
       1,  236, // enums/sets
       0,    0, // constructors
       0,       // flags
      42,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,
      43,   25,   25,   25, 0x05,
      67,   61,   25,   25, 0x05,
      98,   61,   25,   25, 0x05,
     130,   61,   25,   25, 0x05,
     167,   61,   25,   25, 0x05,
     204,   61,   25,   25, 0x05,
     241,   61,   25,   25, 0x05,
     278,   61,   25,   25, 0x05,
     315,   61,   25,   25, 0x05,
     352,   61,   25,   25, 0x05,
     389,   61,   25,   25, 0x05,
     426,   61,   25,   25, 0x05,
     463,   61,   25,   25, 0x05,
     500,   61,   25,   25, 0x05,
     535,   61,   25,   25, 0x05,
     571,   61,   25,   25, 0x05,
     604,   61,   25,   25, 0x05,
     639,   61,   25,   25, 0x05,
     673,   61,   25,   25, 0x05,
     711,   61,   25,   25, 0x05,
     750,   61,   25,   25, 0x05,
     791,   61,   25,   25, 0x05,
     828,   61,   25,   25, 0x05,
     865,   61,   25,   25, 0x05,
     901,   61,   25,   25, 0x05,
     938,   61,   25,   25, 0x05,
     974,   61,   25,   25, 0x05,
    1009,   61,   25,   25, 0x05,
    1046,   61,   25,   25, 0x05,
    1083,   61,   25,   25, 0x05,
    1117,   61,   25,   25, 0x05,
    1150,   61,   25,   25, 0x05,
    1189,   61,   25,   25, 0x05,
    1228,   61,   25,   25, 0x05,
    1267,   61,   25,   25, 0x05,
    1306,   61,   25,   25, 0x05,
    1341,   61,   25,   25, 0x05,
    1378,   61,   25,   25, 0x05,
    1413,   61,   25,   25, 0x05,
    1448,   61,   25,   25, 0x05,
    1487,   61,   25,   25, 0x05,

 // properties: name, type, flags
    1533, 1528, 0x01495103,
    1584, 1541, 0x00095009,
    1603, 1594, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       1,

 // enums: name, flags, count, data
    1594, 0x0,    2,  240,

 // enum data: key, value
    1612, uint(QDeclarativeKeysAttached::BeforeItem),
    1623, uint(QDeclarativeKeysAttached::AfterItem),

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeKeysAttached[] = {
    "QDeclarativeKeysAttached\0\0enabledChanged()\0"
    "priorityChanged()\0event\0"
    "pressed(QDeclarativeKeyEvent*)\0"
    "released(QDeclarativeKeyEvent*)\0"
    "digit0Pressed(QDeclarativeKeyEvent*)\0"
    "digit1Pressed(QDeclarativeKeyEvent*)\0"
    "digit2Pressed(QDeclarativeKeyEvent*)\0"
    "digit3Pressed(QDeclarativeKeyEvent*)\0"
    "digit4Pressed(QDeclarativeKeyEvent*)\0"
    "digit5Pressed(QDeclarativeKeyEvent*)\0"
    "digit6Pressed(QDeclarativeKeyEvent*)\0"
    "digit7Pressed(QDeclarativeKeyEvent*)\0"
    "digit8Pressed(QDeclarativeKeyEvent*)\0"
    "digit9Pressed(QDeclarativeKeyEvent*)\0"
    "leftPressed(QDeclarativeKeyEvent*)\0"
    "rightPressed(QDeclarativeKeyEvent*)\0"
    "upPressed(QDeclarativeKeyEvent*)\0"
    "downPressed(QDeclarativeKeyEvent*)\0"
    "tabPressed(QDeclarativeKeyEvent*)\0"
    "backtabPressed(QDeclarativeKeyEvent*)\0"
    "asteriskPressed(QDeclarativeKeyEvent*)\0"
    "numberSignPressed(QDeclarativeKeyEvent*)\0"
    "escapePressed(QDeclarativeKeyEvent*)\0"
    "returnPressed(QDeclarativeKeyEvent*)\0"
    "enterPressed(QDeclarativeKeyEvent*)\0"
    "deletePressed(QDeclarativeKeyEvent*)\0"
    "spacePressed(QDeclarativeKeyEvent*)\0"
    "backPressed(QDeclarativeKeyEvent*)\0"
    "cancelPressed(QDeclarativeKeyEvent*)\0"
    "selectPressed(QDeclarativeKeyEvent*)\0"
    "yesPressed(QDeclarativeKeyEvent*)\0"
    "noPressed(QDeclarativeKeyEvent*)\0"
    "context1Pressed(QDeclarativeKeyEvent*)\0"
    "context2Pressed(QDeclarativeKeyEvent*)\0"
    "context3Pressed(QDeclarativeKeyEvent*)\0"
    "context4Pressed(QDeclarativeKeyEvent*)\0"
    "callPressed(QDeclarativeKeyEvent*)\0"
    "hangupPressed(QDeclarativeKeyEvent*)\0"
    "flipPressed(QDeclarativeKeyEvent*)\0"
    "menuPressed(QDeclarativeKeyEvent*)\0"
    "volumeUpPressed(QDeclarativeKeyEvent*)\0"
    "volumeDownPressed(QDeclarativeKeyEvent*)\0"
    "bool\0enabled\0QDeclarativeListProperty<QDeclarativeItem>\0"
    "forwardTo\0Priority\0priority\0BeforeItem\0"
    "AfterItem\0"
};

const QMetaObject QDeclarativeKeysAttached::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeKeysAttached,
      qt_meta_data_QDeclarativeKeysAttached, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeKeysAttached::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeKeysAttached::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeKeysAttached::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeKeysAttached))
        return static_cast<void*>(const_cast< QDeclarativeKeysAttached*>(this));
    if (!strcmp(_clname, "QDeclarativeItemKeyFilter"))
        return static_cast< QDeclarativeItemKeyFilter*>(const_cast< QDeclarativeKeysAttached*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeKeysAttached::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enabledChanged(); break;
        case 1: priorityChanged(); break;
        case 2: pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 3: released((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 4: digit0Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 5: digit1Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 6: digit2Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 7: digit3Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 8: digit4Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 9: digit5Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 10: digit6Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 11: digit7Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 12: digit8Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 13: digit9Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 14: leftPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 15: rightPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 16: upPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 17: downPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 18: tabPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 19: backtabPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 20: asteriskPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 21: numberSignPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 22: escapePressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 23: returnPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 24: enterPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 25: deletePressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 26: spacePressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 27: backPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 28: cancelPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 29: selectPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 30: yesPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 31: noPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 32: context1Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 33: context2Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 34: context3Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 35: context4Pressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 36: callPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 37: hangupPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 38: flipPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 39: menuPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 40: volumeUpPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        case 41: volumeDownPressed((*reinterpret_cast< QDeclarativeKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 42;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = enabled(); break;
        case 1: *reinterpret_cast< QDeclarativeListProperty<QDeclarativeItem>*>(_v) = forwardTo(); break;
        case 2: *reinterpret_cast< Priority*>(_v) = priority(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 2: setPriority(*reinterpret_cast< Priority*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativeKeysAttached::enabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeKeysAttached::priorityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QDeclarativeKeysAttached::pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QDeclarativeKeysAttached::released(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QDeclarativeKeysAttached::digit0Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QDeclarativeKeysAttached::digit1Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QDeclarativeKeysAttached::digit2Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QDeclarativeKeysAttached::digit3Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QDeclarativeKeysAttached::digit4Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QDeclarativeKeysAttached::digit5Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QDeclarativeKeysAttached::digit6Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QDeclarativeKeysAttached::digit7Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QDeclarativeKeysAttached::digit8Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QDeclarativeKeysAttached::digit9Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QDeclarativeKeysAttached::leftPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QDeclarativeKeysAttached::rightPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void QDeclarativeKeysAttached::upPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void QDeclarativeKeysAttached::downPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void QDeclarativeKeysAttached::tabPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void QDeclarativeKeysAttached::backtabPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void QDeclarativeKeysAttached::asteriskPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void QDeclarativeKeysAttached::numberSignPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void QDeclarativeKeysAttached::escapePressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void QDeclarativeKeysAttached::returnPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void QDeclarativeKeysAttached::enterPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void QDeclarativeKeysAttached::deletePressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void QDeclarativeKeysAttached::spacePressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void QDeclarativeKeysAttached::backPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void QDeclarativeKeysAttached::cancelPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void QDeclarativeKeysAttached::selectPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void QDeclarativeKeysAttached::yesPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void QDeclarativeKeysAttached::noPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void QDeclarativeKeysAttached::context1Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void QDeclarativeKeysAttached::context2Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void QDeclarativeKeysAttached::context3Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void QDeclarativeKeysAttached::context4Pressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void QDeclarativeKeysAttached::callPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void QDeclarativeKeysAttached::hangupPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void QDeclarativeKeysAttached::flipPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void QDeclarativeKeysAttached::menuPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void QDeclarativeKeysAttached::volumeUpPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void QDeclarativeKeysAttached::volumeDownPressed(QDeclarativeKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}
QT_END_MOC_NAMESPACE
