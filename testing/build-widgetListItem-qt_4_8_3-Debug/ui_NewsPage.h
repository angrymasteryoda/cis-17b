/********************************************************************************
** Form generated from reading UI file 'NewsPage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSPAGE_H
#define UI_NEWSPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewsPage
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *NewsPage)
    {
        if (NewsPage->objectName().isEmpty())
            NewsPage->setObjectName(QString::fromUtf8("NewsPage"));
        NewsPage->resize(1024, 768);
        listWidget = new QListWidget(NewsPage);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(0, 0, 1024, 768));

        retranslateUi(NewsPage);

        QMetaObject::connectSlotsByName(NewsPage);
    } // setupUi

    void retranslateUi(QWidget *NewsPage)
    {
        NewsPage->setWindowTitle(QApplication::translate("NewsPage", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewsPage: public Ui_NewsPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSPAGE_H
