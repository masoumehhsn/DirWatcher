/****************************************************************************
** Meta object code from reading C++ file 'dirwatcher.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../dirwatcher.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dirwatcher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDirWatcherENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDirWatcherENDCLASS = QtMocHelpers::stringData(
    "DirWatcher",
    "FileModified",
    "",
    "path",
    "FileAdded",
    "FolderAdded",
    "FileRemoved",
    "FolderRemoved",
    "FileRenamed",
    "old_path",
    "new_path",
    "FolderRenamed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDirWatcherENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[10];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[14];
    char stringdata8[12];
    char stringdata9[9];
    char stringdata10[9];
    char stringdata11[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDirWatcherENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDirWatcherENDCLASS_t qt_meta_stringdata_CLASSDirWatcherENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "DirWatcher"
        QT_MOC_LITERAL(11, 12),  // "FileModified"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 4),  // "path"
        QT_MOC_LITERAL(30, 9),  // "FileAdded"
        QT_MOC_LITERAL(40, 11),  // "FolderAdded"
        QT_MOC_LITERAL(52, 11),  // "FileRemoved"
        QT_MOC_LITERAL(64, 13),  // "FolderRemoved"
        QT_MOC_LITERAL(78, 11),  // "FileRenamed"
        QT_MOC_LITERAL(90, 8),  // "old_path"
        QT_MOC_LITERAL(99, 8),  // "new_path"
        QT_MOC_LITERAL(108, 13)   // "FolderRenamed"
    },
    "DirWatcher",
    "FileModified",
    "",
    "path",
    "FileAdded",
    "FolderAdded",
    "FileRemoved",
    "FolderRemoved",
    "FileRenamed",
    "old_path",
    "new_path",
    "FolderRenamed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDirWatcherENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    1,   59,    2, 0x06,    3 /* Public */,
       5,    1,   62,    2, 0x06,    5 /* Public */,
       6,    1,   65,    2, 0x06,    7 /* Public */,
       7,    1,   68,    2, 0x06,    9 /* Public */,
       8,    2,   71,    2, 0x06,   11 /* Public */,
      11,    2,   76,    2, 0x06,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject DirWatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDirWatcherENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDirWatcherENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDirWatcherENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DirWatcher, std::true_type>,
        // method 'FileModified'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FileAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FolderAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FileRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FolderRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FileRenamed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'FolderRenamed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void DirWatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DirWatcher *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->FileModified((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->FileAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->FolderAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->FileRemoved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->FolderRemoved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->FileRenamed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->FolderRenamed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DirWatcher::*)(const QString & );
            if (_t _q_method = &DirWatcher::FileModified; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DirWatcher::*)(const QString & );
            if (_t _q_method = &DirWatcher::FileAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DirWatcher::*)(const QString & );
            if (_t _q_method = &DirWatcher::FolderAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DirWatcher::*)(const QString & );
            if (_t _q_method = &DirWatcher::FileRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DirWatcher::*)(const QString & );
            if (_t _q_method = &DirWatcher::FolderRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DirWatcher::*)(const QString & , const QString & );
            if (_t _q_method = &DirWatcher::FileRenamed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DirWatcher::*)(const QString & , const QString & );
            if (_t _q_method = &DirWatcher::FolderRenamed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *DirWatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DirWatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDirWatcherENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DirWatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DirWatcher::FileModified(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DirWatcher::FileAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DirWatcher::FolderAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DirWatcher::FileRemoved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DirWatcher::FolderRemoved(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DirWatcher::FileRenamed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DirWatcher::FolderRenamed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
