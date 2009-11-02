/****************************************************************************
** Meta object code from reading C++ file 'filechooser.h'
**
** Created: Sun Nov 1 20:45:02 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../filechooser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filechooser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FileChooser[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       2,   32, // properties
       1,   38, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   38,   12,   12, 0x0a,
      64,   62,   12,   12, 0x0a,
      78,   12,   12,   12, 0x08,

 // properties: name, type, flags
      96,   91, 0x0009510b,
     109,  101, 0x0a095103,

 // enums: name, flags, count, data
      91, 0x0,    3,   42,

 // enum data: key, value
     118, uint(FileChooser::Any),
     122, uint(FileChooser::File),
     127, uint(FileChooser::Directory),

       0        // eod
};

static const char qt_meta_stringdata_FileChooser[] = {
    "FileChooser\0\0fileNameChanged(QString)\0"
    "fn\0setFileName(QString)\0m\0setMode(Mode)\0"
    "chooseFile()\0Mode\0mode\0QString\0fileName\0"
    "Any\0File\0Directory\0"
};

const QMetaObject FileChooser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FileChooser,
      qt_meta_data_FileChooser, 0 }
};

const QMetaObject *FileChooser::metaObject() const
{
    return &staticMetaObject;
}

void *FileChooser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FileChooser))
        return static_cast<void*>(const_cast< FileChooser*>(this));
    return QWidget::qt_metacast(_clname);
}

int FileChooser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: setFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 3: chooseFile(); break;
        default: ;
        }
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Mode*>(_v) = mode(); break;
        case 1: *reinterpret_cast< QString*>(_v) = fileName(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMode(*reinterpret_cast< Mode*>(_v)); break;
        case 1: setFileName(*reinterpret_cast< QString*>(_v)); break;
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

// SIGNAL 0
void FileChooser::fileNameChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
