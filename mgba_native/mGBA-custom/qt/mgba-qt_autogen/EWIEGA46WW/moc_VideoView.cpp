/****************************************************************************
** Meta object code from reading C++ file 'VideoView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/VideoView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__VideoView_t {
    QByteArrayData data[26];
    char stringdata0[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__VideoView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__VideoView_t qt_meta_stringdata_QGBA__VideoView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::VideoView"
QT_MOC_LITERAL(1, 16, 16), // "recordingStarted"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "mAVStream*"
QT_MOC_LITERAL(4, 45, 16), // "recordingStopped"
QT_MOC_LITERAL(5, 62, 13), // "setController"
QT_MOC_LITERAL(6, 76, 31), // "std::shared_ptr<CoreController>"
QT_MOC_LITERAL(7, 108, 14), // "startRecording"
QT_MOC_LITERAL(8, 123, 13), // "stopRecording"
QT_MOC_LITERAL(9, 137, 19), // "setNativeResolution"
QT_MOC_LITERAL(10, 157, 10), // "selectFile"
QT_MOC_LITERAL(11, 168, 11), // "setFilename"
QT_MOC_LITERAL(12, 180, 13), // "setAudioCodec"
QT_MOC_LITERAL(13, 194, 13), // "setVideoCodec"
QT_MOC_LITERAL(14, 208, 12), // "setContainer"
QT_MOC_LITERAL(15, 221, 15), // "setAudioBitrate"
QT_MOC_LITERAL(16, 237, 15), // "setVideoBitrate"
QT_MOC_LITERAL(17, 253, 18), // "setVideoRateFactor"
QT_MOC_LITERAL(18, 272, 8), // "setWidth"
QT_MOC_LITERAL(19, 281, 9), // "setHeight"
QT_MOC_LITERAL(20, 291, 14), // "setAspectWidth"
QT_MOC_LITERAL(21, 306, 15), // "setAspectHeight"
QT_MOC_LITERAL(22, 322, 12), // "showAdvanced"
QT_MOC_LITERAL(23, 335, 19), // "uncheckIncompatible"
QT_MOC_LITERAL(24, 355, 13), // "updatePresets"
QT_MOC_LITERAL(25, 369, 15) // "changeExtension"

    },
    "QGBA::VideoView\0recordingStarted\0\0"
    "mAVStream*\0recordingStopped\0setController\0"
    "std::shared_ptr<CoreController>\0"
    "startRecording\0stopRecording\0"
    "setNativeResolution\0selectFile\0"
    "setFilename\0setAudioCodec\0setVideoCodec\0"
    "setContainer\0setAudioBitrate\0"
    "setVideoBitrate\0setVideoRateFactor\0"
    "setWidth\0setHeight\0setAspectWidth\0"
    "setAspectHeight\0showAdvanced\0"
    "uncheckIncompatible\0updatePresets\0"
    "changeExtension"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__VideoView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    0,  127,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,  128,    2, 0x0a /* Public */,
       7,    0,  131,    2, 0x0a /* Public */,
       8,    0,  132,    2, 0x0a /* Public */,
       9,    1,  133,    2, 0x0a /* Public */,
      10,    0,  136,    2, 0x08 /* Private */,
      11,    1,  137,    2, 0x08 /* Private */,
      12,    1,  140,    2, 0x08 /* Private */,
      13,    1,  143,    2, 0x08 /* Private */,
      14,    1,  146,    2, 0x08 /* Private */,
      15,    1,  149,    2, 0x08 /* Private */,
      16,    1,  152,    2, 0x08 /* Private */,
      17,    1,  155,    2, 0x08 /* Private */,
      18,    1,  158,    2, 0x08 /* Private */,
      19,    1,  161,    2, 0x08 /* Private */,
      20,    1,  164,    2, 0x08 /* Private */,
      21,    1,  167,    2, 0x08 /* Private */,
      22,    1,  170,    2, 0x08 /* Private */,
      23,    0,  173,    2, 0x08 /* Private */,
      24,    0,  174,    2, 0x08 /* Private */,
      25,    0,  175,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::VideoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->recordingStarted((*reinterpret_cast< mAVStream*(*)>(_a[1]))); break;
        case 1: _t->recordingStopped(); break;
        case 2: _t->setController((*reinterpret_cast< std::shared_ptr<CoreController>(*)>(_a[1]))); break;
        case 3: _t->startRecording(); break;
        case 4: _t->stopRecording(); break;
        case 5: _t->setNativeResolution((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 6: _t->selectFile(); break;
        case 7: _t->setFilename((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setAudioCodec((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setVideoCodec((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setContainer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setAudioBitrate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setVideoBitrate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setVideoRateFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setAspectWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->setAspectHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->showAdvanced((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->uncheckIncompatible(); break;
        case 20: _t->updatePresets(); break;
        case 21: _t->changeExtension(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoView::*)(mAVStream * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoView::recordingStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoView::recordingStopped)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::VideoView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__VideoView.data,
    qt_meta_data_QGBA__VideoView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::VideoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::VideoView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__VideoView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QGBA::VideoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void QGBA::VideoView::recordingStarted(mAVStream * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::VideoView::recordingStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
