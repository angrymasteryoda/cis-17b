/********************************************************************************
** Form generated from reading UI file 'save.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_H
#define UI_SAVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Save
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *continueButton;
    QPushButton *exitButton;
    QLabel *label;

    void setupUi(QDialog *Save)
    {
        if (Save->objectName().isEmpty())
            Save->setObjectName(QString::fromUtf8("Save"));
        Save->resize(265, 101);
        horizontalLayoutWidget = new QWidget(Save);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 40, 241, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        continueButton = new QPushButton(horizontalLayoutWidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        horizontalLayout->addWidget(continueButton);

        exitButton = new QPushButton(horizontalLayoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout->addWidget(exitButton);

        label = new QLabel(Save);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 241, 20));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(Save);

        QMetaObject::connectSlotsByName(Save);
    } // setupUi

    void retranslateUi(QDialog *Save)
    {
        Save->setWindowTitle(QApplication::translate("Save", "Saved", 0, QApplication::UnicodeUTF8));
        continueButton->setText(QApplication::translate("Save", "Continue", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("Save", "Exit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Save", "Game was saved continue?", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Save: public Ui_Save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
