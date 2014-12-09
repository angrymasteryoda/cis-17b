#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDomDocument>
#include <QDomElement>
#include <QListWidget>

#include "ui_NewsPage.h"
class NewsPage : public QWidget
{

    Q_OBJECT
public:
    NewsPage(QWidget *parent = 0);
private:
    Ui::NewsPage *ui;
    QGraphicsScene *scene;
    //QListWidget *contentsWidget;

};

#endif // TESTWIDGET_H
