/****************************************************************************
** Meta object code from reading C++ file 'qdeclarativeanimation_p.h'
**
** Created: Fri Sep 2 01:12:30 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../util/qdeclarativeanimation_p.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdeclarativeanimation_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QDeclarativeAbstractAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       1,   14, // classinfo
      14,   16, // methods
       4,   86, // properties
       1,  102, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // classinfo: key, value
      38,   30,

 // signals: signature, parameters, type, tag, flags
      53,   52,   52,   52, 0x05,
      63,   52,   52,   52, 0x05,
      75,   52,   52,   52, 0x05,
      96,   52,   52,   52, 0x05,
     116,   52,   52,   52, 0x05,
     144,   52,   52,   52, 0x05,

 // slots: signature, parameters, type, tag, flags
     166,   52,   52,   52, 0x0a,
      30,   52,   52,   52, 0x0a,
     176,   52,   52,   52, 0x0a,
     184,   52,   52,   52, 0x0a,
     193,   52,   52,   52, 0x0a,
     200,   52,   52,   52, 0x0a,
     211,   52,   52,   52, 0x08,
     230,   52,   52,   52, 0x08,

 // properties: name, type, flags
     256,  251, 0x01495103,
     264,  251, 0x01495103,
     271,  251, 0x01495103,
     290,  286, 0x02495103,

 // properties: notify_signal_id
       2,
       3,
       4,
       5,

 // enums: name, flags, count, data
     296, 0x0,    1,  106,

 // enum data: key, value
     302, uint(QDeclarativeAbstractAnimation::Infinite),

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeAbstractAnimation[] = {
    "QDeclarativeAbstractAnimation\0start()\0"
    "DefaultMethod\0\0started()\0completed()\0"
    "runningChanged(bool)\0pausedChanged(bool)\0"
    "alwaysRunToEndChanged(bool)\0"
    "loopCountChanged(int)\0restart()\0pause()\0"
    "resume()\0stop()\0complete()\0"
    "timelineComplete()\0componentFinalized()\0"
    "bool\0running\0paused\0alwaysRunToEnd\0"
    "int\0loops\0Loops\0Infinite\0"
};

const QMetaObject QDeclarativeAbstractAnimation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QDeclarativeAbstractAnimation,
      qt_meta_data_QDeclarativeAbstractAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeAbstractAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeAbstractAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeAbstractAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeAbstractAnimation))
        return static_cast<void*>(const_cast< QDeclarativeAbstractAnimation*>(this));
    if (!strcmp(_clname, "QDeclarativePropertyValueSource"))
        return static_cast< QDeclarativePropertyValueSource*>(const_cast< QDeclarativeAbstractAnimation*>(this));
    if (!strcmp(_clname, "QDeclarativeParserStatus"))
        return static_cast< QDeclarativeParserStatus*>(const_cast< QDeclarativeAbstractAnimation*>(this));
    if (!strcmp(_clname, "com.trolltech.qml.QDeclarativeParserStatus"))
        return static_cast< QDeclarativeParserStatus*>(const_cast< QDeclarativeAbstractAnimation*>(this));
    if (!strcmp(_clname, "com.trolltech.qml.QDeclarativePropertyValueSource"))
        return static_cast< QDeclarativePropertyValueSource*>(const_cast< QDeclarativeAbstractAnimation*>(this));
    return QObject::qt_metacast(_clname);
}

int QDeclarativeAbstractAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: started(); break;
        case 1: completed(); break;
        case 2: runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: pausedChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: alwaysRunToEndChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: loopCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: restart(); break;
        case 7: start(); break;
        case 8: pause(); break;
        case 9: resume(); break;
        case 10: stop(); break;
        case 11: complete(); break;
        case 12: timelineComplete(); break;
        case 13: componentFinalized(); break;
        default: ;
        }
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isRunning(); break;
        case 1: *reinterpret_cast< bool*>(_v) = isPaused(); break;
        case 2: *reinterpret_cast< bool*>(_v) = alwaysRunToEnd(); break;
        case 3: *reinterpret_cast< int*>(_v) = loops(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setRunning(*reinterpret_cast< bool*>(_v)); break;
        case 1: setPaused(*reinterpret_cast< bool*>(_v)); break;
        case 2: setAlwaysRunToEnd(*reinterpret_cast< bool*>(_v)); break;
        case 3: setLoops(*reinterpret_cast< int*>(_v)); break;
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
void QDeclarativeAbstractAnimation::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeAbstractAnimation::completed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QDeclarativeAbstractAnimation::runningChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QDeclarativeAbstractAnimation::pausedChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QDeclarativeAbstractAnimation::alwaysRunToEndChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QDeclarativeAbstractAnimation::loopCountChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
static const uint qt_meta_data_QDeclarativePauseAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   19, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,

 // properties: name, type, flags
      53,   49, 0x02495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativePauseAnimation[] = {
    "QDeclarativePauseAnimation\0\0"
    "durationChanged(int)\0int\0duration\0"
};

const QMetaObject QDeclarativePauseAnimation::staticMetaObject = {
    { &QDeclarativeAbstractAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativePauseAnimation,
      qt_meta_data_QDeclarativePauseAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativePauseAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativePauseAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativePauseAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativePauseAnimation))
        return static_cast<void*>(const_cast< QDeclarativePauseAnimation*>(this));
    return QDeclarativeAbstractAnimation::qt_metacast(_clname);
}

int QDeclarativePauseAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: durationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = duration(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDuration(*reinterpret_cast< int*>(_v)); break;
        }
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
void QDeclarativePauseAnimation::durationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QDeclarativeScriptAction[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      50,   25, 0x0009510b,
      65,   57, 0x0a095003,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeScriptAction[] = {
    "QDeclarativeScriptAction\0"
    "QDeclarativeScriptString\0script\0QString\0"
    "scriptName\0"
};

const QMetaObject QDeclarativeScriptAction::staticMetaObject = {
    { &QDeclarativeAbstractAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeScriptAction,
      qt_meta_data_QDeclarativeScriptAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeScriptAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeScriptAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeScriptAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeScriptAction))
        return static_cast<void*>(const_cast< QDeclarativeScriptAction*>(this));
    return QDeclarativeAbstractAnimation::qt_metacast(_clname);
}

int QDeclarativeScriptAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeScriptString*>(_v) = script(); break;
        case 1: *reinterpret_cast< QString*>(_v) = stateChangeScriptName(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setScript(*reinterpret_cast< QDeclarativeScriptString*>(_v)); break;
        case 1: setStateChangeScriptName(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
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
static const uint qt_meta_data_QDeclarativePropertyAction[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       6,   34, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      51,   27,   27,   27, 0x05,
      78,   27,   27,   27, 0x05,
      94,   27,   27,   27, 0x05,

 // properties: name, type, flags
     121,  112, 0x88495103,
     136,  128, 0x0a495103,
     145,  128, 0x0a495103,
     190,  156, 0x00095009,
     198,  156, 0x00095009,
     215,  206, 0xff495103,

 // properties: notify_signal_id
       2,
       3,
       1,
       0,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativePropertyAction[] = {
    "QDeclarativePropertyAction\0\0"
    "valueChanged(QVariant)\0"
    "propertiesChanged(QString)\0targetChanged()\0"
    "propertyChanged()\0QObject*\0target\0"
    "QString\0property\0properties\0"
    "QDeclarativeListProperty<QObject>\0"
    "targets\0exclude\0QVariant\0value\0"
};

const QMetaObject QDeclarativePropertyAction::staticMetaObject = {
    { &QDeclarativeAbstractAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativePropertyAction,
      qt_meta_data_QDeclarativePropertyAction, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativePropertyAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativePropertyAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativePropertyAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativePropertyAction))
        return static_cast<void*>(const_cast< QDeclarativePropertyAction*>(this));
    return QDeclarativeAbstractAnimation::qt_metacast(_clname);
}

int QDeclarativePropertyAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 1: propertiesChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: targetChanged(); break;
        case 3: propertyChanged(); break;
        default: ;
        }
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QObject**>(_v) = target(); break;
        case 1: *reinterpret_cast< QString*>(_v) = property(); break;
        case 2: *reinterpret_cast< QString*>(_v) = properties(); break;
        case 3: *reinterpret_cast< QDeclarativeListProperty<QObject>*>(_v) = targets(); break;
        case 4: *reinterpret_cast< QDeclarativeListProperty<QObject>*>(_v) = exclude(); break;
        case 5: *reinterpret_cast< QVariant*>(_v) = value(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTarget(*reinterpret_cast< QObject**>(_v)); break;
        case 1: setProperty(*reinterpret_cast< QString*>(_v)); break;
        case 2: setProperties(*reinterpret_cast< QString*>(_v)); break;
        case 5: setValue(*reinterpret_cast< QVariant*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativePropertyAction::valueChanged(const QVariant & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDeclarativePropertyAction::propertiesChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QDeclarativePropertyAction::targetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QDeclarativePropertyAction::propertyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
static const uint qt_meta_data_QDeclarativePropertyAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       9,   49, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x05,
      52,   30,   30,   30, 0x05,
      74,   30,   30,   30, 0x05,
      94,   30,   30,   30, 0x05,
     122,   30,   30,   30, 0x05,
     149,   30,   30,   30, 0x05,
     165,   30,   30,   30, 0x05,

 // properties: name, type, flags
     187,  183, 0x02495103,
     205,  196, 0xff495103,
     210,  196, 0xff495103,
     226,  213, 0x1d495103,
     242,  233, 0x88495103,
     257,  249, 0x0a495103,
     266,  249, 0x0a495103,
     311,  277, 0x00095009,
     319,  277, 0x00095009,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       5,
       6,
       4,
       0,
       0,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativePropertyAnimation[] = {
    "QDeclarativePropertyAnimation\0\0"
    "durationChanged(int)\0fromChanged(QVariant)\0"
    "toChanged(QVariant)\0easingChanged(QEasingCurve)\0"
    "propertiesChanged(QString)\0targetChanged()\0"
    "propertyChanged()\0int\0duration\0QVariant\0"
    "from\0to\0QEasingCurve\0easing\0QObject*\0"
    "target\0QString\0property\0properties\0"
    "QDeclarativeListProperty<QObject>\0"
    "targets\0exclude\0"
};

const QMetaObject QDeclarativePropertyAnimation::staticMetaObject = {
    { &QDeclarativeAbstractAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativePropertyAnimation,
      qt_meta_data_QDeclarativePropertyAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativePropertyAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativePropertyAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativePropertyAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativePropertyAnimation))
        return static_cast<void*>(const_cast< QDeclarativePropertyAnimation*>(this));
    return QDeclarativeAbstractAnimation::qt_metacast(_clname);
}

int QDeclarativePropertyAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: durationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: fromChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 2: toChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 3: easingChanged((*reinterpret_cast< const QEasingCurve(*)>(_a[1]))); break;
        case 4: propertiesChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: targetChanged(); break;
        case 6: propertyChanged(); break;
        default: ;
        }
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = duration(); break;
        case 1: *reinterpret_cast< QVariant*>(_v) = from(); break;
        case 2: *reinterpret_cast< QVariant*>(_v) = to(); break;
        case 3: *reinterpret_cast< QEasingCurve*>(_v) = easing(); break;
        case 4: *reinterpret_cast< QObject**>(_v) = target(); break;
        case 5: *reinterpret_cast< QString*>(_v) = property(); break;
        case 6: *reinterpret_cast< QString*>(_v) = properties(); break;
        case 7: *reinterpret_cast< QDeclarativeListProperty<QObject>*>(_v) = targets(); break;
        case 8: *reinterpret_cast< QDeclarativeListProperty<QObject>*>(_v) = exclude(); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDuration(*reinterpret_cast< int*>(_v)); break;
        case 1: setFrom(*reinterpret_cast< QVariant*>(_v)); break;
        case 2: setTo(*reinterpret_cast< QVariant*>(_v)); break;
        case 3: setEasing(*reinterpret_cast< QEasingCurve*>(_v)); break;
        case 4: setTarget(*reinterpret_cast< QObject**>(_v)); break;
        case 5: setProperty(*reinterpret_cast< QString*>(_v)); break;
        case 6: setProperties(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QDeclarativePropertyAnimation::durationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDeclarativePropertyAnimation::fromChanged(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QDeclarativePropertyAnimation::toChanged(QVariant _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QDeclarativePropertyAnimation::easingChanged(const QEasingCurve & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QDeclarativePropertyAnimation::propertiesChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QDeclarativePropertyAnimation::targetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QDeclarativePropertyAnimation::propertyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
static const uint qt_meta_data_QDeclarativeColorAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      34,   27, 0x43095103,
      39,   27, 0x43095103,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeColorAnimation[] = {
    "QDeclarativeColorAnimation\0QColor\0"
    "from\0to\0"
};

const QMetaObject QDeclarativeColorAnimation::staticMetaObject = {
    { &QDeclarativePropertyAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeColorAnimation,
      qt_meta_data_QDeclarativeColorAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeColorAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeColorAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeColorAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeColorAnimation))
        return static_cast<void*>(const_cast< QDeclarativeColorAnimation*>(this));
    return QDeclarativePropertyAnimation::qt_metacast(_clname);
}

int QDeclarativeColorAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativePropertyAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = from(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = to(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFrom(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setTo(*reinterpret_cast< QColor*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
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
static const uint qt_meta_data_QDeclarativeNumberAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      34,   28, (QMetaType::QReal << 24) | 0x00095103,
      39,   28, (QMetaType::QReal << 24) | 0x00095103,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeNumberAnimation[] = {
    "QDeclarativeNumberAnimation\0qreal\0"
    "from\0to\0"
};

const QMetaObject QDeclarativeNumberAnimation::staticMetaObject = {
    { &QDeclarativePropertyAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeNumberAnimation,
      qt_meta_data_QDeclarativeNumberAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeNumberAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeNumberAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeNumberAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeNumberAnimation))
        return static_cast<void*>(const_cast< QDeclarativeNumberAnimation*>(this));
    return QDeclarativePropertyAnimation::qt_metacast(_clname);
}

int QDeclarativeNumberAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativePropertyAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = from(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = to(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFrom(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setTo(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
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
static const uint qt_meta_data_QDeclarativeVector3dAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      40,   30, 0x54095103,
      45,   30, 0x54095103,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeVector3dAnimation[] = {
    "QDeclarativeVector3dAnimation\0QVector3D\0"
    "from\0to\0"
};

const QMetaObject QDeclarativeVector3dAnimation::staticMetaObject = {
    { &QDeclarativePropertyAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeVector3dAnimation,
      qt_meta_data_QDeclarativeVector3dAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeVector3dAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeVector3dAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeVector3dAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeVector3dAnimation))
        return static_cast<void*>(const_cast< QDeclarativeVector3dAnimation*>(this));
    return QDeclarativePropertyAnimation::qt_metacast(_clname);
}

int QDeclarativeVector3dAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativePropertyAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVector3D*>(_v) = from(); break;
        case 1: *reinterpret_cast< QVector3D*>(_v) = to(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFrom(*reinterpret_cast< QVector3D*>(_v)); break;
        case 1: setTo(*reinterpret_cast< QVector3D*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
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
static const uint qt_meta_data_QDeclarativeRotationAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       3,   19, // properties
       1,   31, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x05,

 // properties: name, type, flags
      56,   50, (QMetaType::QReal << 24) | 0x00095103,
      61,   50, (QMetaType::QReal << 24) | 0x00095103,
      82,   64, 0x0049510b,

 // properties: notify_signal_id
       0,
       0,
       0,

 // enums: name, flags, count, data
      64, 0x0,    4,   35,

 // enum data: key, value
      92, uint(QDeclarativeRotationAnimation::Numerical),
     102, uint(QDeclarativeRotationAnimation::Shortest),
     111, uint(QDeclarativeRotationAnimation::Clockwise),
     121, uint(QDeclarativeRotationAnimation::Counterclockwise),

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeRotationAnimation[] = {
    "QDeclarativeRotationAnimation\0\0"
    "directionChanged()\0qreal\0from\0to\0"
    "RotationDirection\0direction\0Numerical\0"
    "Shortest\0Clockwise\0Counterclockwise\0"
};

const QMetaObject QDeclarativeRotationAnimation::staticMetaObject = {
    { &QDeclarativePropertyAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeRotationAnimation,
      qt_meta_data_QDeclarativeRotationAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeRotationAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeRotationAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeRotationAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeRotationAnimation))
        return static_cast<void*>(const_cast< QDeclarativeRotationAnimation*>(this));
    return QDeclarativePropertyAnimation::qt_metacast(_clname);
}

int QDeclarativeRotationAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativePropertyAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: directionChanged(); break;
        default: ;
        }
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = from(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = to(); break;
        case 2: *reinterpret_cast< RotationDirection*>(_v) = direction(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setFrom(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setTo(*reinterpret_cast< qreal*>(_v)); break;
        case 2: setDirection(*reinterpret_cast< RotationDirection*>(_v)); break;
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
void QDeclarativeRotationAnimation::directionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_QDeclarativeAnimationGroup[] = {

 // content:
       5,       // revision
       0,       // classname
       1,   14, // classinfo
       0,    0, // methods
       1,   16, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
      38,   27,

 // properties: name, type, flags
      27,   54, 0x00095009,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeAnimationGroup[] = {
    "QDeclarativeAnimationGroup\0animations\0"
    "DefaultProperty\0"
    "QDeclarativeListProperty<QDeclarativeAbstractAnimation>\0"
};

const QMetaObject QDeclarativeAnimationGroup::staticMetaObject = {
    { &QDeclarativeAbstractAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeAnimationGroup,
      qt_meta_data_QDeclarativeAnimationGroup, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeAnimationGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeAnimationGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeAnimationGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeAnimationGroup))
        return static_cast<void*>(const_cast< QDeclarativeAnimationGroup*>(this));
    return QDeclarativeAbstractAnimation::qt_metacast(_clname);
}

int QDeclarativeAnimationGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeListProperty<QDeclarativeAbstractAnimation>*>(_v) = animations(); break;
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
static const uint qt_meta_data_QDeclarativeSequentialAnimation[] = {

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

static const char qt_meta_stringdata_QDeclarativeSequentialAnimation[] = {
    "QDeclarativeSequentialAnimation\0"
};

const QMetaObject QDeclarativeSequentialAnimation::staticMetaObject = {
    { &QDeclarativeAnimationGroup::staticMetaObject, qt_meta_stringdata_QDeclarativeSequentialAnimation,
      qt_meta_data_QDeclarativeSequentialAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeSequentialAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeSequentialAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeSequentialAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeSequentialAnimation))
        return static_cast<void*>(const_cast< QDeclarativeSequentialAnimation*>(this));
    return QDeclarativeAnimationGroup::qt_metacast(_clname);
}

int QDeclarativeSequentialAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAnimationGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QDeclarativeParallelAnimation[] = {

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

static const char qt_meta_stringdata_QDeclarativeParallelAnimation[] = {
    "QDeclarativeParallelAnimation\0"
};

const QMetaObject QDeclarativeParallelAnimation::staticMetaObject = {
    { &QDeclarativeAnimationGroup::staticMetaObject, qt_meta_stringdata_QDeclarativeParallelAnimation,
      qt_meta_data_QDeclarativeParallelAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeParallelAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeParallelAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeParallelAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeParallelAnimation))
        return static_cast<void*>(const_cast< QDeclarativeParallelAnimation*>(this));
    return QDeclarativeAnimationGroup::qt_metacast(_clname);
}

int QDeclarativeParallelAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAnimationGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QDeclarativeParentAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   29, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x05,
      45,   28,   28,   28, 0x05,
      64,   28,   28,   28, 0x05,

 // properties: name, type, flags
      95,   77, 0x0049510b,
     102,   77, 0x0049510b,
     112,   77, 0x0049510b,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeParentAnimation[] = {
    "QDeclarativeParentAnimation\0\0"
    "targetChanged()\0newParentChanged()\0"
    "viaChanged()\0QDeclarativeItem*\0target\0"
    "newParent\0via\0"
};

const QMetaObject QDeclarativeParentAnimation::staticMetaObject = {
    { &QDeclarativeAnimationGroup::staticMetaObject, qt_meta_stringdata_QDeclarativeParentAnimation,
      qt_meta_data_QDeclarativeParentAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeParentAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeParentAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeParentAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeParentAnimation))
        return static_cast<void*>(const_cast< QDeclarativeParentAnimation*>(this));
    return QDeclarativeAnimationGroup::qt_metacast(_clname);
}

int QDeclarativeParentAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAnimationGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: targetChanged(); break;
        case 1: newParentChanged(); break;
        case 2: viaChanged(); break;
        default: ;
        }
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeItem**>(_v) = target(); break;
        case 1: *reinterpret_cast< QDeclarativeItem**>(_v) = newParent(); break;
        case 2: *reinterpret_cast< QDeclarativeItem**>(_v) = via(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTarget(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 1: setNewParent(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
        case 2: setVia(*reinterpret_cast< QDeclarativeItem**>(_v)); break;
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
void QDeclarativeParentAnimation::targetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QDeclarativeParentAnimation::newParentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QDeclarativeParentAnimation::viaChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
static const uint qt_meta_data_QDeclarativeAnchorAnimation[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   28,   28,   28, 0x05,
      50,   28,   28,   28, 0x05,

 // properties: name, type, flags
     121,   78, 0x00095009,
     133,  129, 0x02495103,
     155,  142, 0x1d495103,

 // properties: notify_signal_id
       0,
       0,
       1,

       0        // eod
};

static const char qt_meta_stringdata_QDeclarativeAnchorAnimation[] = {
    "QDeclarativeAnchorAnimation\0\0"
    "durationChanged(int)\0easingChanged(QEasingCurve)\0"
    "QDeclarativeListProperty<QDeclarativeItem>\0"
    "targets\0int\0duration\0QEasingCurve\0"
    "easing\0"
};

const QMetaObject QDeclarativeAnchorAnimation::staticMetaObject = {
    { &QDeclarativeAbstractAnimation::staticMetaObject, qt_meta_stringdata_QDeclarativeAnchorAnimation,
      qt_meta_data_QDeclarativeAnchorAnimation, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QDeclarativeAnchorAnimation::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QDeclarativeAnchorAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QDeclarativeAnchorAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QDeclarativeAnchorAnimation))
        return static_cast<void*>(const_cast< QDeclarativeAnchorAnimation*>(this));
    return QDeclarativeAbstractAnimation::qt_metacast(_clname);
}

int QDeclarativeAnchorAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeclarativeAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: durationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: easingChanged((*reinterpret_cast< const QEasingCurve(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QDeclarativeListProperty<QDeclarativeItem>*>(_v) = targets(); break;
        case 1: *reinterpret_cast< int*>(_v) = duration(); break;
        case 2: *reinterpret_cast< QEasingCurve*>(_v) = easing(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: setDuration(*reinterpret_cast< int*>(_v)); break;
        case 2: setEasing(*reinterpret_cast< QEasingCurve*>(_v)); break;
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
void QDeclarativeAnchorAnimation::durationChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QDeclarativeAnchorAnimation::easingChanged(const QEasingCurve & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
