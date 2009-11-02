/****************************************************************************
** Meta object code from reading C++ file 'non_param_cdf_input.h'
**
** Created: Sun Nov 1 20:45:01 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../non_param_cdf_input.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'non_param_cdf_input.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TailCdfInput[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x0a,
      47,   14,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TailCdfInput[] = {
    "TailCdfInput\0\0index\0setExtremeBoxEnabbled(int)\0"
    "setOmegaBoxEnabbled(int)\0"
};

const QMetaObject TailCdfInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TailCdfInput,
      qt_meta_data_TailCdfInput, 0 }
};

const QMetaObject *TailCdfInput::metaObject() const
{
    return &staticMetaObject;
}

void *TailCdfInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TailCdfInput))
        return static_cast<void*>(const_cast< TailCdfInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int TailCdfInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setExtremeBoxEnabbled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setOmegaBoxEnabbled((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
static const uint qt_meta_data_LowerTailCdfInput[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_LowerTailCdfInput[] = {
    "LowerTailCdfInput\0"
};

const QMetaObject LowerTailCdfInput::staticMetaObject = {
    { &TailCdfInput::staticMetaObject, qt_meta_stringdata_LowerTailCdfInput,
      qt_meta_data_LowerTailCdfInput, 0 }
};

const QMetaObject *LowerTailCdfInput::metaObject() const
{
    return &staticMetaObject;
}

void *LowerTailCdfInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LowerTailCdfInput))
        return static_cast<void*>(const_cast< LowerTailCdfInput*>(this));
    return TailCdfInput::qt_metacast(_clname);
}

int LowerTailCdfInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TailCdfInput::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_UpperTailCdfInput[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_UpperTailCdfInput[] = {
    "UpperTailCdfInput\0"
};

const QMetaObject UpperTailCdfInput::staticMetaObject = {
    { &TailCdfInput::staticMetaObject, qt_meta_stringdata_UpperTailCdfInput,
      qt_meta_data_UpperTailCdfInput, 0 }
};

const QMetaObject *UpperTailCdfInput::metaObject() const
{
    return &staticMetaObject;
}

void *UpperTailCdfInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UpperTailCdfInput))
        return static_cast<void*>(const_cast< UpperTailCdfInput*>(this));
    return TailCdfInput::qt_metacast(_clname);
}

int UpperTailCdfInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TailCdfInput::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_NonParamCdfInput[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      28,   18,   17,   17, 0x0a,
      64,   54,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NonParamCdfInput[] = {
    "NonParamCdfInput\0\0grid_name\0"
    "setReferenceGrid(QString)\0prop_name\0"
    "setReferenceProperty(QString)\0"
};

const QMetaObject NonParamCdfInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NonParamCdfInput,
      qt_meta_data_NonParamCdfInput, 0 }
};

const QMetaObject *NonParamCdfInput::metaObject() const
{
    return &staticMetaObject;
}

void *NonParamCdfInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NonParamCdfInput))
        return static_cast<void*>(const_cast< NonParamCdfInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int NonParamCdfInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setReferenceGrid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: setReferenceProperty((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
