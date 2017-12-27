#ifndef COMMOMHEADER_H
#define COMMOMHEADER_H

#include <QDirIterator>
#include <QFile>
#include <QFileDialog>
#include <QImage>
#include <qimagewriter.h>
#include <QMessageBox>
#include "config.h"

#define CSTRING_TO_QSTRING(str) QString::fromUtf8(str)
#define QSTRING_TO_CSTRING(str) str.toLocal8Bit().data()
#define EXIT_CODE_REBOOT		773

#endif // COMMOMHEADER_H