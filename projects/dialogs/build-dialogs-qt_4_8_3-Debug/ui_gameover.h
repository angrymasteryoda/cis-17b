/********************************************************************************
** Form generated from reading UI file 'gameover.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEOVER_H
#define UI_GAMEOVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameOver
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *messageLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *retryButton;
    QPushButton *playAgianButton;

    void setupUi(QDialog *GameOver)
    {
        if (GameOver->objectName().isEmpty())
            GameOver->setObjectName(QString::fromUtf8("GameOver"));
        GameOver->resize(391, 291);
        verticalLayoutWidget = new QWidget(GameOver);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 371, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messageLabel = new QLabel(verticalLayoutWidget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setAlignment(Qt::AlignCenter);
        messageLabel->setMargin(0);

        verticalLayout->addWidget(messageLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        retryButton = new QPushButton(verticalLayoutWidget);
        retryButton->setObjectName(QString::fromUtf8("retryButton"));

        horizontalLayout->addWidget(retryButton);

        playAgianButton = new QPushButton(verticalLayoutWidget);
        playAgianButton->setObjectName(QString::fromUtf8("playAgianButton"));

        horizontalLayout->addWidget(playAgianButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GameOver);

        QMetaObject::connectSlotsByName(GameOver);
    } // setupUi

    void retranslateUi(QDialog *GameOver)
    {
        GameOver->setWindowTitle(QApplication::translate("GameOver", "Game Over", 0, QApplication::UnicodeUTF8));
        messageLabel->setText(QApplication::translate("GameOver", "<html>\n"
"<body style=\"padding: 0;margin:0;\">\n"
"<div style=\"background:green; text-align: center; line-height: 30px; font-family: cursive; font-size: 14pt; font-weight: 800;\">\n"
"You Won!\n"
"</div>\n"
"<div style=\"background:red; text-align: center; line-height: 30px; font-family: cursive; font-size: 14pt; font-weight: 800;\">\n"
"You Lost\n"
"</div>\n"
"<div style=\"background:white; text-align: center; line-height: 30px; font-family: cursive; font-size: 12pt;\">\n"
"With a time of 00:00\n"
"</div>\n"
"</body>\n"
"\n"
"</html>", 0, QApplication::UnicodeUTF8));
        retryButton->setText(QApplication::translate("GameOver", "Retry", 0, QApplication::UnicodeUTF8));
        playAgianButton->setText(QApplication::translate("GameOver", "Play Agian", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameOver: public Ui_GameOver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEOVER_H
