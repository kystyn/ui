/****************************************************************************
** Meta object code from reading C++ file 'MediaPlayerPrivatePhonon.h'
**
** Created: Fri Sep 2 02:25:47 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../platform/graphics/qt/MediaPlayerPrivatePhonon.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MediaPlayerPrivatePhonon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebCore__MediaPlayerPrivate[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       3,   59, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   29,   28,   28, 0x08,
      73,   28,   28,   28, 0x08,
      91,   28,   28,   28, 0x08,
     113,   28,   28,   28, 0x08,
     135,   28,   28,   28, 0x08,
     153,   28,   28,   28, 0x08,
     164,   28,   28,   28, 0x08,
     206,   28,   28,   28, 0x08,
     222,   28,   28,   28, 0x08,

 // enums: name, flags, count, data
     247, 0x0,    5,   71,
     258, 0x0,    7,   81,
     271, 0x0,    6,   95,

 // enum data: key, value
     283, uint(WebCore::MediaPlayerPrivate::HaveNothing),
     295, uint(WebCore::MediaPlayerPrivate::HaveMetadata),
     308, uint(WebCore::MediaPlayerPrivate::HaveCurrentData),
     324, uint(WebCore::MediaPlayerPrivate::HaveFutureData),
     339, uint(WebCore::MediaPlayerPrivate::HaveEnoughData),
     354, uint(WebCore::MediaPlayerPrivate::Empty),
     360, uint(WebCore::MediaPlayerPrivate::Idle),
     365, uint(WebCore::MediaPlayerPrivate::Loading),
     373, uint(WebCore::MediaPlayerPrivate::Loaded),
     380, uint(WebCore::MediaPlayerPrivate::FormatError),
     392, uint(WebCore::MediaPlayerPrivate::NetworkError),
     405, uint(WebCore::MediaPlayerPrivate::DecodeError),
     417, uint(WebCore::MediaPlayerPrivate::LoadingState),
     430, uint(WebCore::MediaPlayerPrivate::StoppedState),
     443, uint(WebCore::MediaPlayerPrivate::PlayingState),
     456, uint(WebCore::MediaPlayerPrivate::BufferingState),
     471, uint(WebCore::MediaPlayerPrivate::PausedState),
     483, uint(WebCore::MediaPlayerPrivate::ErrorState),

       0        // eod
};

static const char qt_meta_stringdata_WebCore__MediaPlayerPrivate[] = {
    "WebCore::MediaPlayerPrivate\0\0,\0"
    "stateChanged(Phonon::State,Phonon::State)\0"
    "metaDataChanged()\0seekableChanged(bool)\0"
    "hasVideoChanged(bool)\0bufferStatus(int)\0"
    "finished()\0currentSourceChanged(Phonon::MediaSource)\0"
    "aboutToFinish()\0totalTimeChanged(qint64)\0"
    "ReadyState\0NetworkState\0PhononState\0"
    "HaveNothing\0HaveMetadata\0HaveCurrentData\0"
    "HaveFutureData\0HaveEnoughData\0Empty\0"
    "Idle\0Loading\0Loaded\0FormatError\0"
    "NetworkError\0DecodeError\0LoadingState\0"
    "StoppedState\0PlayingState\0BufferingState\0"
    "PausedState\0ErrorState\0"
};

const QMetaObject WebCore::MediaPlayerPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebCore__MediaPlayerPrivate,
      qt_meta_data_WebCore__MediaPlayerPrivate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebCore::MediaPlayerPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebCore::MediaPlayerPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebCore::MediaPlayerPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebCore__MediaPlayerPrivate))
        return static_cast<void*>(const_cast< MediaPlayerPrivate*>(this));
    if (!strcmp(_clname, "MediaPlayerPrivateInterface"))
        return static_cast< MediaPlayerPrivateInterface*>(const_cast< MediaPlayerPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int WebCore::MediaPlayerPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 1: metaDataChanged(); break;
        case 2: seekableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: hasVideoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: bufferStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: finished(); break;
        case 6: currentSourceChanged((*reinterpret_cast< const Phonon::MediaSource(*)>(_a[1]))); break;
        case 7: aboutToFinish(); break;
        case 8: totalTimeChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
