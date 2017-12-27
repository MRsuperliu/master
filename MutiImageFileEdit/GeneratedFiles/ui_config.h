/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_sourceFolder;
    QLineEdit *lineEdit_destFolder;
    QPushButton *pushButton_browseSourceFolder;
    QPushButton *pushButton_browseDestFolder;

    void setupUi(QWidget *ConfigClass)
    {
        if (ConfigClass->objectName().isEmpty())
            ConfigClass->setObjectName(QString::fromUtf8("ConfigClass"));
        ConfigClass->resize(480, 300);
        label = new QLabel(ConfigClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 90, 20));
        label_2 = new QLabel(ConfigClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 90, 20));
        lineEdit_sourceFolder = new QLineEdit(ConfigClass);
        lineEdit_sourceFolder->setObjectName(QString::fromUtf8("lineEdit_sourceFolder"));
        lineEdit_sourceFolder->setGeometry(QRect(100, 20, 240, 20));
        lineEdit_destFolder = new QLineEdit(ConfigClass);
        lineEdit_destFolder->setObjectName(QString::fromUtf8("lineEdit_destFolder"));
        lineEdit_destFolder->setGeometry(QRect(100, 50, 240, 20));
        pushButton_browseSourceFolder = new QPushButton(ConfigClass);
        pushButton_browseSourceFolder->setObjectName(QString::fromUtf8("pushButton_browseSourceFolder"));
        pushButton_browseSourceFolder->setGeometry(QRect(350, 20, 75, 20));
        pushButton_browseDestFolder = new QPushButton(ConfigClass);
        pushButton_browseDestFolder->setObjectName(QString::fromUtf8("pushButton_browseDestFolder"));
        pushButton_browseDestFolder->setGeometry(QRect(350, 50, 75, 20));

        retranslateUi(ConfigClass);

        QMetaObject::connectSlotsByName(ConfigClass);
    } // setupUi

    void retranslateUi(QWidget *ConfigClass)
    {
        ConfigClass->setWindowTitle(QApplication::translate("ConfigClass", "Config", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigClass", "sourceFolder:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfigClass", "destFolder:", 0, QApplication::UnicodeUTF8));
        pushButton_browseSourceFolder->setText(QApplication::translate("ConfigClass", "Browse...", 0, QApplication::UnicodeUTF8));
        pushButton_browseDestFolder->setText(QApplication::translate("ConfigClass", "Browse...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigClass: public Ui_ConfigClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
