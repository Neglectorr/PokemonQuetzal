/****************************************************************************
** Meta object code from reading C++ file 'Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__Window_t {
    QByteArrayData data[62];
    char stringdata0[778];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__Window_t qt_meta_stringdata_QGBA__Window = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QGBA::Window"
QT_MOC_LITERAL(1, 13, 12), // "startDrawing"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "shutdown"
QT_MOC_LITERAL(4, 36, 6), // "paused"
QT_MOC_LITERAL(5, 43, 19), // "shaderSelectorAdded"
QT_MOC_LITERAL(6, 63, 15), // "ShaderSelector*"
QT_MOC_LITERAL(7, 79, 13), // "setController"
QT_MOC_LITERAL(8, 93, 15), // "CoreController*"
QT_MOC_LITERAL(9, 109, 10), // "controller"
QT_MOC_LITERAL(10, 120, 5), // "fname"
QT_MOC_LITERAL(11, 126, 9), // "selectROM"
QT_MOC_LITERAL(12, 136, 8), // "bootBIOS"
QT_MOC_LITERAL(13, 145, 18), // "selectROMInArchive"
QT_MOC_LITERAL(14, 164, 15), // "addDirToLibrary"
QT_MOC_LITERAL(15, 180, 10), // "selectSave"
QT_MOC_LITERAL(16, 191, 9), // "temporary"
QT_MOC_LITERAL(17, 201, 11), // "selectState"
QT_MOC_LITERAL(18, 213, 4), // "load"
QT_MOC_LITERAL(19, 218, 11), // "selectPatch"
QT_MOC_LITERAL(20, 230, 8), // "scanCard"
QT_MOC_LITERAL(21, 239, 9), // "parseCard"
QT_MOC_LITERAL(22, 249, 15), // "enterFullScreen"
QT_MOC_LITERAL(23, 265, 14), // "exitFullScreen"
QT_MOC_LITERAL(24, 280, 16), // "toggleFullScreen"
QT_MOC_LITERAL(25, 297, 10), // "loadConfig"
QT_MOC_LITERAL(26, 308, 12), // "reloadConfig"
QT_MOC_LITERAL(27, 321, 10), // "saveConfig"
QT_MOC_LITERAL(28, 332, 12), // "loadCamImage"
QT_MOC_LITERAL(29, 345, 10), // "replaceROM"
QT_MOC_LITERAL(30, 356, 18), // "multiplayerChanged"
QT_MOC_LITERAL(31, 375, 15), // "importSharkport"
QT_MOC_LITERAL(32, 391, 15), // "exportSharkport"
QT_MOC_LITERAL(33, 407, 18), // "openSettingsWindow"
QT_MOC_LITERAL(34, 426, 18), // "SettingsView::Page"
QT_MOC_LITERAL(35, 445, 13), // "startVideoLog"
QT_MOC_LITERAL(36, 459, 8), // "openView"
QT_MOC_LITERAL(37, 468, 8), // "QWidget*"
QT_MOC_LITERAL(38, 477, 6), // "widget"
QT_MOC_LITERAL(39, 484, 8), // "showMenu"
QT_MOC_LITERAL(40, 493, 11), // "consoleOpen"
QT_MOC_LITERAL(41, 505, 7), // "gdbOpen"
QT_MOC_LITERAL(42, 513, 13), // "scriptingOpen"
QT_MOC_LITERAL(43, 527, 11), // "gameStarted"
QT_MOC_LITERAL(44, 539, 11), // "gameStopped"
QT_MOC_LITERAL(45, 551, 11), // "gameCrashed"
QT_MOC_LITERAL(46, 563, 10), // "gameFailed"
QT_MOC_LITERAL(47, 574, 21), // "unimplementedBiosCall"
QT_MOC_LITERAL(48, 596, 17), // "reloadAudioDriver"
QT_MOC_LITERAL(49, 614, 19), // "reloadDisplayDriver"
QT_MOC_LITERAL(50, 634, 13), // "attachDisplay"
QT_MOC_LITERAL(51, 648, 14), // "changeRenderer"
QT_MOC_LITERAL(52, 663, 15), // "tryMakePortable"
QT_MOC_LITERAL(53, 679, 11), // "mustRestart"
QT_MOC_LITERAL(54, 691, 9), // "mustReset"
QT_MOC_LITERAL(55, 701, 11), // "recordFrame"
QT_MOC_LITERAL(56, 713, 7), // "showFPS"
QT_MOC_LITERAL(57, 721, 10), // "focusCheck"
QT_MOC_LITERAL(58, 732, 11), // "updateFrame"
QT_MOC_LITERAL(59, 744, 10), // "updateMute"
QT_MOC_LITERAL(60, 755, 7), // "setLogo"
QT_MOC_LITERAL(61, 763, 14) // "delayedCleanup"

    },
    "QGBA::Window\0startDrawing\0\0shutdown\0"
    "paused\0shaderSelectorAdded\0ShaderSelector*\0"
    "setController\0CoreController*\0controller\0"
    "fname\0selectROM\0bootBIOS\0selectROMInArchive\0"
    "addDirToLibrary\0selectSave\0temporary\0"
    "selectState\0load\0selectPatch\0scanCard\0"
    "parseCard\0enterFullScreen\0exitFullScreen\0"
    "toggleFullScreen\0loadConfig\0reloadConfig\0"
    "saveConfig\0loadCamImage\0replaceROM\0"
    "multiplayerChanged\0importSharkport\0"
    "exportSharkport\0openSettingsWindow\0"
    "SettingsView::Page\0startVideoLog\0"
    "openView\0QWidget*\0widget\0showMenu\0"
    "consoleOpen\0gdbOpen\0scriptingOpen\0"
    "gameStarted\0gameStopped\0gameCrashed\0"
    "gameFailed\0unimplementedBiosCall\0"
    "reloadAudioDriver\0reloadDisplayDriver\0"
    "attachDisplay\0changeRenderer\0"
    "tryMakePortable\0mustRestart\0mustReset\0"
    "recordFrame\0showFPS\0focusCheck\0"
    "updateFrame\0updateMute\0setLogo\0"
    "delayedCleanup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  274,    2, 0x06 /* Public */,
       3,    0,  275,    2, 0x06 /* Public */,
       4,    1,  276,    2, 0x06 /* Public */,
       5,    1,  279,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,  282,    2, 0x0a /* Public */,
      11,    0,  287,    2, 0x0a /* Public */,
      12,    0,  288,    2, 0x0a /* Public */,
      13,    0,  289,    2, 0x0a /* Public */,
      14,    0,  290,    2, 0x0a /* Public */,
      15,    1,  291,    2, 0x0a /* Public */,
      17,    1,  294,    2, 0x0a /* Public */,
      19,    0,  297,    2, 0x0a /* Public */,
      20,    0,  298,    2, 0x0a /* Public */,
      21,    0,  299,    2, 0x0a /* Public */,
      22,    0,  300,    2, 0x0a /* Public */,
      23,    0,  301,    2, 0x0a /* Public */,
      24,    0,  302,    2, 0x0a /* Public */,
      25,    0,  303,    2, 0x0a /* Public */,
      26,    0,  304,    2, 0x0a /* Public */,
      27,    0,  305,    2, 0x0a /* Public */,
      28,    0,  306,    2, 0x0a /* Public */,
      29,    0,  307,    2, 0x0a /* Public */,
      30,    0,  308,    2, 0x0a /* Public */,
      31,    0,  309,    2, 0x0a /* Public */,
      32,    0,  310,    2, 0x0a /* Public */,
      33,    0,  311,    2, 0x0a /* Public */,
      33,    1,  312,    2, 0x0a /* Public */,
      35,    0,  315,    2, 0x0a /* Public */,
      36,    1,  316,    2, 0x0a /* Public */,
      39,    1,  319,    2, 0x0a /* Public */,
      40,    0,  322,    2, 0x0a /* Public */,
      41,    0,  323,    2, 0x0a /* Public */,
      42,    0,  324,    2, 0x0a /* Public */,
      43,    0,  325,    2, 0x08 /* Private */,
      44,    0,  326,    2, 0x08 /* Private */,
      45,    1,  327,    2, 0x08 /* Private */,
      46,    0,  330,    2, 0x08 /* Private */,
      47,    1,  331,    2, 0x08 /* Private */,
      48,    0,  334,    2, 0x08 /* Private */,
      49,    0,  335,    2, 0x08 /* Private */,
      50,    0,  336,    2, 0x08 /* Private */,
      51,    0,  337,    2, 0x08 /* Private */,
      52,    0,  338,    2, 0x08 /* Private */,
      53,    0,  339,    2, 0x08 /* Private */,
      54,    0,  340,    2, 0x08 /* Private */,
      55,    0,  341,    2, 0x08 /* Private */,
      56,    0,  342,    2, 0x08 /* Private */,
      57,    0,  343,    2, 0x08 /* Private */,
      58,    0,  344,    2, 0x08 /* Private */,
      59,    0,  345,    2, 0x08 /* Private */,
      60,    0,  346,    2, 0x08 /* Private */,
      61,    0,  347,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 37,   38,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startDrawing(); break;
        case 1: _t->shutdown(); break;
        case 2: _t->paused((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->shaderSelectorAdded((*reinterpret_cast< ShaderSelector*(*)>(_a[1]))); break;
        case 4: _t->setController((*reinterpret_cast< CoreController*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->selectROM(); break;
        case 6: _t->bootBIOS(); break;
        case 7: _t->selectROMInArchive(); break;
        case 8: _t->addDirToLibrary(); break;
        case 9: _t->selectSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->selectState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->selectPatch(); break;
        case 12: _t->scanCard(); break;
        case 13: _t->parseCard(); break;
        case 14: _t->enterFullScreen(); break;
        case 15: _t->exitFullScreen(); break;
        case 16: _t->toggleFullScreen(); break;
        case 17: _t->loadConfig(); break;
        case 18: _t->reloadConfig(); break;
        case 19: _t->saveConfig(); break;
        case 20: _t->loadCamImage(); break;
        case 21: _t->replaceROM(); break;
        case 22: _t->multiplayerChanged(); break;
        case 23: _t->importSharkport(); break;
        case 24: _t->exportSharkport(); break;
        case 25: _t->openSettingsWindow(); break;
        case 26: _t->openSettingsWindow((*reinterpret_cast< SettingsView::Page(*)>(_a[1]))); break;
        case 27: _t->startVideoLog(); break;
        case 28: _t->openView((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 29: _t->showMenu((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->consoleOpen(); break;
        case 31: _t->gdbOpen(); break;
        case 32: _t->scriptingOpen(); break;
        case 33: _t->gameStarted(); break;
        case 34: _t->gameStopped(); break;
        case 35: _t->gameCrashed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->gameFailed(); break;
        case 37: _t->unimplementedBiosCall((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->reloadAudioDriver(); break;
        case 39: _t->reloadDisplayDriver(); break;
        case 40: _t->attachDisplay(); break;
        case 41: _t->changeRenderer(); break;
        case 42: _t->tryMakePortable(); break;
        case 43: _t->mustRestart(); break;
        case 44: _t->mustReset(); break;
        case 45: _t->recordFrame(); break;
        case 46: _t->showFPS(); break;
        case 47: _t->focusCheck(); break;
        case 48: _t->updateFrame(); break;
        case 49: _t->updateMute(); break;
        case 50: _t->setLogo(); break;
        case 51: _t->delayedCleanup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ShaderSelector* >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window::startDrawing)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Window::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window::shutdown)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Window::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window::paused)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Window::*)(ShaderSelector * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Window::shaderSelectorAdded)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QGBA__Window.data,
    qt_meta_data_QGBA__Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QGBA::Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    }
    return _id;
}

// SIGNAL 0
void QGBA::Window::startDrawing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGBA::Window::shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGBA::Window::paused(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGBA::Window::shaderSelectorAdded(ShaderSelector * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_QGBA__WindowBackground_t {
    QByteArrayData data[1];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__WindowBackground_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__WindowBackground_t qt_meta_stringdata_QGBA__WindowBackground = {
    {
QT_MOC_LITERAL(0, 0, 22) // "QGBA::WindowBackground"

    },
    "QGBA::WindowBackground"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__WindowBackground[] = {

 // content:
       8,       // revision
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

void QGBA::WindowBackground::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject QGBA::WindowBackground::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__WindowBackground.data,
    qt_meta_data_QGBA__WindowBackground,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::WindowBackground::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::WindowBackground::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__WindowBackground.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QGBA::WindowBackground::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
