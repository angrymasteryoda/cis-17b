/********************************************************************************
** Form generated from reading UI file 'newgame.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME_H
#define UI_NEWGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGame
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *difficultyCombo;

    void setupUi(QDialog *NewGame)
    {
        if (NewGame->objectName().isEmpty())
            NewGame->setObjectName(QString::fromUtf8("NewGame"));
        NewGame->resize(211, 115);
        buttonBox = new QDialogButtonBox(NewGame);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 50, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(NewGame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 151, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        difficultyCombo = new QComboBox(layoutWidget);
        difficultyCombo->setObjectName(QString::fromUtf8("difficultyCombo"));

        horizontalLayout->addWidget(difficultyCombo);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(difficultyCombo);
#endif // QT_NO_SHORTCUT

        retranslateUi(NewGame);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewGame, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewGame, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewGame);
    } // setupUi

    void retranslateUi(QDialog *NewGame)
    {
        NewGame->setWindowTitle(QApplication::translate("NewGame", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewGame", "Difficulty", 0, QApplication::UnicodeUTF8));
        difficultyCombo->clear();
        difficultyCombo->insertItems(0, QStringList()
         << QApplication::translate("NewGame", "Easy", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewGame", "Medium", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewGame", "Hard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NewGame", "Insane", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class NewGame: public Ui_NewGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
