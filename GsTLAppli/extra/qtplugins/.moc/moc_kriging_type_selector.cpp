/****************************************************************************
** Meta object code from reading C++ file 'kriging_type_selector.h'
**
** Created: Sun Nov 1 20:45:01 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../kriging_type_selector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kriging_type_selector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrendComponents[] = {

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

static const char qt_meta_stringdata_TrendComponents[] = {
    "TrendComponents\0"
};

const QMetaObject TrendComponents::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrendComponents,
      qt_meta_data_TrendComponents, 0 }
};

const QMetaObject *TrendComponents::metaObject() const
{
    return &staticMetaObject;
}

void *TrendComponents::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrendComponents))
        return static_cast<void*>(const_cast< TrendComponents*>(this));
    return QWidget::qt_metacast(_clname);
}

int TrendComponents::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_KrigingTypeSelector[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x05,
      49,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   76,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_KrigingTypeSelector[] = {
    "KrigingTypeSelector\0\0krigingTypeChanged(QString)\0"
    "krigingParametersChanged()\0id\0"
    "promptForParameters(int)\0"
};

const QMetaObject KrigingTypeSelector::staticMetaObject = {
    { &Kriging_type_selector_base::staticMetaObject, qt_meta_stringdata_KrigingTypeSelector,
      qt_meta_data_KrigingTypeSelector, 0 }
};

const QMetaObject *KrigingTypeSelector::metaObject() const
{
    return &staticMetaObject;
}

void *KrigingTypeSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KrigingTypeSelector))
        return static_cast<void*>(const_cast< KrigingTypeSelector*>(this));
    return Kriging_type_selector_base::qt_metacast(_clname);
}

int KrigingTypeSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Kriging_type_selector_base::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: krigingTypeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: krigingParametersChanged(); break;
        case 2: promptForParameters((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KrigingTypeSelector::krigingTypeChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KrigingTypeSelector::krigingParametersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
