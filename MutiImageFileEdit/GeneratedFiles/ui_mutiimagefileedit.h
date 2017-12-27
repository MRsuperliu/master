/********************************************************************************
** Form generated from reading UI file 'mutiimagefileedit.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUTIIMAGEFILEEDIT_H
#define UI_MUTIIMAGEFILEEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolBox>

QT_BEGIN_NAMESPACE

class Ui_MutiImageFileEditClass
{
public:
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox_function;
    QStackedWidget *stackedWidget_function;

    void setupUi(QDialog *MutiImageFileEditClass)
    {
        if (MutiImageFileEditClass->objectName().isEmpty())
            MutiImageFileEditClass->setObjectName(QString::fromUtf8("MutiImageFileEditClass"));
        MutiImageFileEditClass->resize(600, 400);
        MutiImageFileEditClass->setMinimumSize(QSize(600, 400));
        MutiImageFileEditClass->setMaximumSize(QSize(664, 418));
        horizontalLayout = new QHBoxLayout(MutiImageFileEditClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolBox_function = new QToolBox(MutiImageFileEditClass);
        toolBox_function->setObjectName(QString::fromUtf8("toolBox_function"));
        toolBox_function->setMinimumSize(QSize(100, 0));
        toolBox_function->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(toolBox_function);

        stackedWidget_function = new QStackedWidget(MutiImageFileEditClass);
        stackedWidget_function->setObjectName(QString::fromUtf8("stackedWidget_function"));
        stackedWidget_function->setMinimumSize(QSize(540, 400));
        stackedWidget_function->setMaximumSize(QSize(540, 400));

        horizontalLayout->addWidget(stackedWidget_function);


        retranslateUi(MutiImageFileEditClass);

        toolBox_function->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MutiImageFileEditClass);
    } // setupUi

    void retranslateUi(QDialog *MutiImageFileEditClass)
    {
        MutiImageFileEditClass->setWindowTitle(QApplication::translate("MutiImageFileEditClass", "MutiImageFileEdit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MutiImageFileEditClass: public Ui_MutiImageFileEditClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUTIIMAGEFILEEDIT_H
