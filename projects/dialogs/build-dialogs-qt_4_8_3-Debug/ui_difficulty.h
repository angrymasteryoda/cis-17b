/********************************************************************************
** Form generated from reading UI file 'difficulty.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTY_H
#define UI_DIFFICULTY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Difficulty
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *difficultyLabel;
    QComboBox *difficultyComboBox;
    QPushButton *okButton;

    void setupUi(QDialog *Difficulty)
    {
        if (Difficulty->objectName().isEmpty())
            Difficulty->setObjectName(QString::fromUtf8("Difficulty"));
        Difficulty->resize(231, 169);
        horizontalLayoutWidget = new QWidget(Difficulty);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 211, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        difficultyLabel = new QLabel(horizontalLayoutWidget);
        difficultyLabel->setObjectName(QString::fromUtf8("difficultyLabel"));

        horizontalLayout->addWidget(difficultyLabel);

        difficultyComboBox = new QComboBox(horizontalLayoutWidget);
        difficultyComboBox->setObjectName(QString::fromUtf8("difficultyComboBox"));

        horizontalLayout->addWidget(difficultyComboBox);

        okButton = new QPushButton(Difficulty);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(70, 110, 75, 23));

        retranslateUi(Difficulty);

        QMetaObject::connectSlotsByName(Difficulty);
    } // setupUi

    void retranslateUi(QDialog *Difficulty)
    {
        Difficulty->setWindowTitle(QApplication::translate("Difficulty", "Set difficulty", 0, QApplication::UnicodeUTF8));
        difficultyLabel->setText(QApplication::translate("Difficulty", "Difficulty", 0, QApplication::UnicodeUTF8));
        difficultyComboBox->clear();
        difficultyComboBox->insertItems(0, QStringList()
         << QApplication::translate("Difficulty", "Easy", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Difficulty", "Medium", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Difficulty", "Hard", 0, QApplication::UnicodeUTF8)
        );
        okButton->setText(QApplication::translate("Difficulty", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Difficulty: public Ui_Difficulty {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTY_H
