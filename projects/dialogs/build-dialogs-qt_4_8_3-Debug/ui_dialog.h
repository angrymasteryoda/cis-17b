/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *dockWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *diffButton;
    QPushButton *gameOverButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDockWidget *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(211, 199);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayoutWidget = new QWidget(dockWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 191, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        diffButton = new QPushButton(gridLayoutWidget);
        diffButton->setObjectName(QString::fromUtf8("diffButton"));

        gridLayout->addWidget(diffButton, 0, 0, 1, 1);

        gameOverButton = new QPushButton(gridLayoutWidget);
        gameOverButton->setObjectName(QString::fromUtf8("gameOverButton"));

        gridLayout->addWidget(gameOverButton, 1, 0, 1, 1);

        saveButton = new QPushButton(gridLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 0, 1, 1, 1);

        cancelButton = new QPushButton(gridLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 1, 1, 1, 1);

        Dialog->setWidget(dockWidgetContents);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDockWidget *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialogs", 0, QApplication::UnicodeUTF8));
        diffButton->setText(QApplication::translate("Dialog", "Difficulty", 0, QApplication::UnicodeUTF8));
        gameOverButton->setText(QApplication::translate("Dialog", "Game Over", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Dialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
