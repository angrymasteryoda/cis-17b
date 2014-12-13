/********************************************************************************
** Form generated from reading UI file 'howtodialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTODIALOG_H
#define UI_HOWTODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HowToDialog
{
public:
    QPushButton *closeButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *HowToDialog)
    {
        if (HowToDialog->objectName().isEmpty())
            HowToDialog->setObjectName(QString::fromUtf8("HowToDialog"));
        HowToDialog->resize(218, 291);
        closeButton = new QPushButton(HowToDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(70, 250, 75, 23));
        label = new QLabel(HowToDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 181, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Broadway BT"));
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(HowToDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 181, 191));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setWordWrap(true);
        label->raise();
        label_2->raise();
        closeButton->raise();

        retranslateUi(HowToDialog);

        QMetaObject::connectSlotsByName(HowToDialog);
    } // setupUi

    void retranslateUi(QDialog *HowToDialog)
    {
        HowToDialog->setWindowTitle(QApplication::translate("HowToDialog", "How to Play", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("HowToDialog", "Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HowToDialog", "Sudoku", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HowToDialog", "<ul class=\"gameRules\">\n"
"		<li><b>Goal of the game</b></li>\n"
"		<li>1. No duplicates of the numbers 1-9 horizontally.</li>\n"
"		<li>2. No duplicates of the numbers 1-9 vertically</li>\n"
"		<li>3. No duplicates of the numbers 1-9 in the 3x3 cell groups</li>\n"
"	</ul>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HowToDialog: public Ui_HowToDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTODIALOG_H
