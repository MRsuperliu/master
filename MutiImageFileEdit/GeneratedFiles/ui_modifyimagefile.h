/********************************************************************************
** Form generated from reading UI file 'modifyimagefile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYIMAGEFILE_H
#define UI_MODIFYIMAGEFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModifyImageFileClass
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QCheckBox *checkBox_modifyFileFormat;
    QCheckBox *checkBox_modifyFileSize;
    QLabel *label_2;
    QLineEdit *lineEdit_destFolder;
    QPushButton *pushButton_sourceFolder;
    QPushButton *pushButton_destFolder;
    QLineEdit *lineEdit_sourceFolder;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QPushButton *pushButton_execute;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_left;
    QLineEdit *lineEdit_right;
    QLineEdit *lineEdit_width;
    QLineEdit *lineEdit_height;
    QComboBox *comboBox_sourceFileFormat;
    QComboBox *comboBox_destFileFormat;
    QProgressBar *progressBar;

    void setupUi(QDialog *ModifyImageFileClass)
    {
        if (ModifyImageFileClass->objectName().isEmpty())
            ModifyImageFileClass->setObjectName(QString::fromUtf8("ModifyImageFileClass"));
        ModifyImageFileClass->resize(480, 300);
        ModifyImageFileClass->setMinimumSize(QSize(480, 300));
        ModifyImageFileClass->setMaximumSize(QSize(480, 300));
        verticalLayout = new QVBoxLayout(ModifyImageFileClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(ModifyImageFileClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        checkBox_modifyFileFormat = new QCheckBox(groupBox);
        checkBox_modifyFileFormat->setObjectName(QString::fromUtf8("checkBox_modifyFileFormat"));
        checkBox_modifyFileFormat->setGeometry(QRect(20, 90, 130, 20));
        checkBox_modifyFileSize = new QCheckBox(groupBox);
        checkBox_modifyFileSize->setObjectName(QString::fromUtf8("checkBox_modifyFileSize"));
        checkBox_modifyFileSize->setGeometry(QRect(20, 180, 130, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 90, 20));
        lineEdit_destFolder = new QLineEdit(groupBox);
        lineEdit_destFolder->setObjectName(QString::fromUtf8("lineEdit_destFolder"));
        lineEdit_destFolder->setGeometry(QRect(110, 60, 250, 20));
        pushButton_sourceFolder = new QPushButton(groupBox);
        pushButton_sourceFolder->setObjectName(QString::fromUtf8("pushButton_sourceFolder"));
        pushButton_sourceFolder->setGeometry(QRect(370, 30, 75, 20));
        pushButton_destFolder = new QPushButton(groupBox);
        pushButton_destFolder->setObjectName(QString::fromUtf8("pushButton_destFolder"));
        pushButton_destFolder->setGeometry(QRect(370, 60, 75, 20));
        lineEdit_sourceFolder = new QLineEdit(groupBox);
        lineEdit_sourceFolder->setObjectName(QString::fromUtf8("lineEdit_sourceFolder"));
        lineEdit_sourceFolder->setGeometry(QRect(110, 30, 250, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 90, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 150, 110, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 110, 20));
        pushButton_execute = new QPushButton(groupBox);
        pushButton_execute->setObjectName(QString::fromUtf8("pushButton_execute"));
        pushButton_execute->setGeometry(QRect(350, 240, 75, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 210, 40, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 210, 40, 20));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 210, 40, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(270, 210, 40, 20));
        lineEdit_left = new QLineEdit(groupBox);
        lineEdit_left->setObjectName(QString::fromUtf8("lineEdit_left"));
        lineEdit_left->setGeometry(QRect(60, 210, 30, 20));
        lineEdit_right = new QLineEdit(groupBox);
        lineEdit_right->setObjectName(QString::fromUtf8("lineEdit_right"));
        lineEdit_right->setGeometry(QRect(150, 210, 30, 20));
        lineEdit_width = new QLineEdit(groupBox);
        lineEdit_width->setObjectName(QString::fromUtf8("lineEdit_width"));
        lineEdit_width->setGeometry(QRect(230, 210, 30, 20));
        lineEdit_height = new QLineEdit(groupBox);
        lineEdit_height->setObjectName(QString::fromUtf8("lineEdit_height"));
        lineEdit_height->setGeometry(QRect(310, 210, 30, 20));
        comboBox_sourceFileFormat = new QComboBox(groupBox);
        comboBox_sourceFileFormat->setObjectName(QString::fromUtf8("comboBox_sourceFileFormat"));
        comboBox_sourceFileFormat->setGeometry(QRect(140, 120, 220, 20));
        comboBox_destFileFormat = new QComboBox(groupBox);
        comboBox_destFileFormat->setObjectName(QString::fromUtf8("comboBox_destFileFormat"));
        comboBox_destFileFormat->setGeometry(QRect(140, 150, 220, 20));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 240, 300, 20));
        progressBar->setValue(24);

        verticalLayout->addWidget(groupBox);


        retranslateUi(ModifyImageFileClass);

        QMetaObject::connectSlotsByName(ModifyImageFileClass);
    } // setupUi

    void retranslateUi(QDialog *ModifyImageFileClass)
    {
        ModifyImageFileClass->setWindowTitle(QApplication::translate("ModifyImageFileClass", "ModifyImageFile", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ModifyImageFileClass", "ModifyImageFile", 0, QApplication::UnicodeUTF8));
        checkBox_modifyFileFormat->setText(QApplication::translate("ModifyImageFileClass", "Modify File Format", 0, QApplication::UnicodeUTF8));
        checkBox_modifyFileSize->setText(QApplication::translate("ModifyImageFileClass", "Modify file size", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModifyImageFileClass", "Dest Folder:", 0, QApplication::UnicodeUTF8));
        pushButton_sourceFolder->setText(QApplication::translate("ModifyImageFileClass", "Browser...", 0, QApplication::UnicodeUTF8));
        pushButton_destFolder->setText(QApplication::translate("ModifyImageFileClass", "Browser...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModifyImageFileClass", "Source Folder:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ModifyImageFileClass", "Dest File Format:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModifyImageFileClass", "Source File Format:", 0, QApplication::UnicodeUTF8));
        pushButton_execute->setText(QApplication::translate("ModifyImageFileClass", "Execute", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ModifyImageFileClass", "left:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ModifyImageFileClass", "top:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ModifyImageFileClass", "width:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ModifyImageFileClass", "height:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModifyImageFileClass: public Ui_ModifyImageFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYIMAGEFILE_H
