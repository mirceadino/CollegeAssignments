/****************************************************************************
** Meta object code from reading C++ file 'ProgrammerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ProgrammerWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ProgrammerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProgrammerWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      27,   17,   17,   17, 0x08,
      33,   17,   17,   17, 0x08,
      41,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProgrammerWindow[] = {
    "ProgrammerWindow\0\0remove()\0add()\0"
    "start()\0finish()\0"
};

void ProgrammerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProgrammerWindow *_t = static_cast<ProgrammerWindow *>(_o);
        switch (_id) {
        case 0: _t->remove(); break;
        case 1: _t->add(); break;
        case 2: _t->start(); break;
        case 3: _t->finish(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ProgrammerWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProgrammerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProgrammerWindow,
      qt_meta_data_ProgrammerWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProgrammerWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProgrammerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProgrammerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProgrammerWindow))
        return static_cast<void*>(const_cast< ProgrammerWindow*>(this));
    if (!strcmp(_clname, "Observer"))
        return static_cast< Observer*>(const_cast< ProgrammerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProgrammerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
