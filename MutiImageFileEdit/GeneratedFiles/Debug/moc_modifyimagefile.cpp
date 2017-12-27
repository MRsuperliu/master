/****************************************************************************
** Meta object code from reading C++ file 'modifyimagefile.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../modifyimagefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifyimagefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModifyImageFile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   17,   16,   16, 0x0a,
      72,   61,   16,   16, 0x0a,
     107,  101,   16,   16, 0x0a,
     138,  101,   16,   16, 0x0a,
     172,  167,   16,   16, 0x0a,
     199,  195,   16,   16, 0x0a,
     227,  221,   16,   16, 0x0a,
     258,  251,   16,   16, 0x0a,
     283,   16,   16,   16, 0x0a,
     304,   16,   16,   16, 0x0a,
     325,   16,   16,   16, 0x0a,
     346,   16,   16,   16, 0x0a,
     365,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ModifyImageFile[] = {
    "ModifyImageFile\0\0sourceFolder\0"
    "onSourceFolderChanged(QString)\0"
    "DestFolser\0onDestFolderChanged(QString)\0"
    "index\0onSourceFileFormatChanged(int)\0"
    "onDestFileFormatChanged(int)\0left\0"
    "onLeftChanged(QString)\0top\0"
    "onTopChanged(QString)\0width\0"
    "onWidthChanged(QString)\0height\0"
    "onHeightChanged(QString)\0onBrowseSourFolder()\0"
    "onBrowseDestFolder()\0onModifyFileFormat()\0"
    "onModifyFileSize()\0onExecute()\0"
};

void ModifyImageFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ModifyImageFile *_t = static_cast<ModifyImageFile *>(_o);
        switch (_id) {
        case 0: _t->onSourceFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onDestFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onSourceFileFormatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onDestFileFormatChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onLeftChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onTopChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onWidthChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onHeightChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onBrowseSourFolder(); break;
        case 9: _t->onBrowseDestFolder(); break;
        case 10: _t->onModifyFileFormat(); break;
        case 11: _t->onModifyFileSize(); break;
        case 12: _t->onExecute(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ModifyImageFile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ModifyImageFile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ModifyImageFile,
      qt_meta_data_ModifyImageFile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModifyImageFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModifyImageFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModifyImageFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModifyImageFile))
        return static_cast<void*>(const_cast< ModifyImageFile*>(this));
    return QDialog::qt_metacast(_clname);
}

int ModifyImageFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
