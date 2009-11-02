/****************************************************************************
** Meta object code from reading C++ file 'variogram_input.h'
**
** Created: Mon Nov 2 10:30:46 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../variogram_input.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'variogram_input.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VariogramInput[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x0a,
      40,   36,   15,   15, 0x0a,
      69,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VariogramInput[] = {
    "VariogramInput\0\0f\0set_nugget(float)\0"
    "val\0update_structures_count(int)\0"
    "load_model()\0"
};

const QMetaObject VariogramInput::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VariogramInput,
      qt_meta_data_VariogramInput, 0 }
};

const QMetaObject *VariogramInput::metaObject() const
{
    return &staticMetaObject;
}

void *VariogramInput::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VariogramInput))
        return static_cast<void*>(const_cast< VariogramInput*>(this));
    if (!strcmp(_clname, "Ui::Variogram_input_base"))
        return static_cast< Ui::Variogram_input_base*>(const_cast< VariogramInput*>(this));
    return QWidget::qt_metacast(_clname);
}

int VariogramInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: set_nugget((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: update_structures_count((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: load_model(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_Variogram_structure_input[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      27,   26,   26,   26, 0x05,
      54,   26,   26,   26, 0x05,
      86,   26,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
     116,  114,   26,   26, 0x0a,
     145,  140,   26,   26, 0x0a,
     188,  173,   26,   26, 0x0a,
     220,  218,   26,   26, 0x0a,
     237,  218,   26,   26, 0x0a,
     257,  218,   26,   26, 0x0a,
     280,  274,   26,   26, 0x0a,
     310,  218,   26,   26, 0x0a,
     325,  218,   26,   26, 0x0a,
     340,  218,   26,   26, 0x0a,
     355,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Variogram_structure_input[] = {
    "Variogram_structure_input\0\0"
    "anisotropy_value_changed()\0"
    "variogram_type_changed(QString)\0"
    "contribution_changed(float)\0c\0"
    "set_contribution(float)\0type\0"
    "set_variogram_type(QString)\0max,medium,min\0"
    "set_ranges(float,float,float)\0a\0"
    "max_range(float)\0medium_range(float)\0"
    "min_range(float)\0x,y,z\0"
    "set_angles(float,float,float)\0"
    "x_angle(float)\0y_angle(float)\0"
    "z_angle(float)\0contribution_change_slot(QString)\0"
};

const QMetaObject Variogram_structure_input::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Variogram_structure_input,
      qt_meta_data_Variogram_structure_input, 0 }
};

const QMetaObject *Variogram_structure_input::metaObject() const
{
    return &staticMetaObject;
}

void *Variogram_structure_input::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Variogram_structure_input))
        return static_cast<void*>(const_cast< Variogram_structure_input*>(this));
    if (!strcmp(_clname, "Ui::Variogram_structure_base"))
        return static_cast< Ui::Variogram_structure_base*>(const_cast< Variogram_structure_input*>(this));
    return QWidget::qt_metacast(_clname);
}

int Variogram_structure_input::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: anisotropy_value_changed(); break;
        case 1: variogram_type_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: contribution_changed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: set_contribution((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: set_variogram_type((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: set_ranges((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 6: max_range((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: medium_range((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 8: min_range((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 9: set_angles((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 10: x_angle((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: y_angle((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: z_angle((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: contribution_change_slot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Variogram_structure_input::anisotropy_value_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Variogram_structure_input::variogram_type_changed(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Variogram_structure_input::contribution_changed(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
static const uint qt_meta_data_Line_separator[] = {

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

static const char qt_meta_stringdata_Line_separator[] = {
    "Line_separator\0"
};

const QMetaObject Line_separator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Line_separator,
      qt_meta_data_Line_separator, 0 }
};

const QMetaObject *Line_separator::metaObject() const
{
    return &staticMetaObject;
}

void *Line_separator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Line_separator))
        return static_cast<void*>(const_cast< Line_separator*>(this));
    return QWidget::qt_metacast(_clname);
}

int Line_separator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
