/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionNew_Game;
    QAction *actionSave;
    QAction *actionSave_2;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QToolTip{border:1px solid #000;background-color:#ffa02f;padding:1px;border-radius:3px;opacity:100}QWidget{color:#b1b1b1;background-color:#323232}QWidget:item:hover{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #ffa02f,stop:1 #ca0619);color:#000}QWidget:item:selected{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #ffa02f,stop:1 #d7801a)}QMenuBar::item{background:0 0}QMenuBar::item:selected{background:0 0;border:1px solid #fa0}QMenuBar::item:pressed{background:#444;border:1px solid #000;background:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:1 #212121,stop:.4 #343434);margin-bottom:-1px;padding-bottom:1px}QMenu{border:1px solid #000}QMenu::item{padding:2px 20px}QMenu::item:selected{color:#000}QWidget:disabled{color:#404040;background-color:#323232}QAbstractItemView{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #4d4d4d,stop:.1 #646464,stop:1 #5d5d5d)}QLineEdit{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #4d4d4d,stop:0 #646464,stop:1 #5d5d5d);padding:1px;border:"
                        "1px solid #1e1e1e;border-radius:5}QPushButton{color:#b1b1b1;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #565656,stop:.1 #525252,stop:.5 #4e4e4e,stop:.9 #4a4a4a,stop:1 #464646);border-width:1px;border-color:#1e1e1e;border-style:solid;border-radius:6;padding:3px 5px;font-size:12px}QPushButton:pressed{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #2d2d2d,stop:.1 #2b2b2b,stop:.5 #292929,stop:.9 #282828,stop:1 #252525)}QComboBox{selection-background-color:#fa0;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #565656,stop:.1 #525252,stop:.5 #4e4e4e,stop:.9 #4a4a4a,stop:1 #464646);border:1px solid #1e1e1e;border-radius:5}QComboBox:hover,QPushButton:hover{border:2px solid}QComboBox:on{padding-top:3px;padding-left:4px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #2d2d2d,stop:.1 #2b2b2b,stop:.5 #292929,stop:.9 #282828,stop:1 #252525);selection-background-color:#fa0}QComboBox QAbstractItemView{border:2px solid #a9a9a9;selection-background-color:QLinearGradient(x1:0,"
                        "y1:0,x2:0,y2:1,stop:0 #ffa02f,stop:1 #d7801a)}QComboBox::drop-down{subcontrol-origin:padding;subcontrol-position:top right;width:15px;border-left-width:0;border-left-color:#a9a9a9;border-left-style:solid;border-top-right-radius:3px;border-bottom-right-radius:3px}QComboBox::down-arrow{image:url(:/down_arrow.png)}QGroupBox:focus,QTextEdit:focus{border:2px solid}QScrollBar:horizontal{border:1px solid #222;background:0 0;height:7px;margin:0 16px}QScrollBar::handle:horizontal{background:0 0;min-height:20px;border-radius:2px}QScrollBar::add-line:horizontal{border:1px solid #1b1b19;border-radius:2px;background:0 0;width:14px;subcontrol-position:right;subcontrol-origin:margin}QScrollBar::sub-line:horizontal{border:1px solid #1b1b19;border-radius:2px;background:0 0;width:14px;subcontrol-position:left;subcontrol-origin:margin}QScrollBar::left-arrow:horizontal,QScrollBar::right-arrow:horizontal{border:1px solid #000;width:1px;height:1px;background:#fff}QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{backg"
                        "round:0 0}QScrollBar:vertical{background:0 0;width:7px;margin:16px 0;border:1px solid #222}QScrollBar::handle:vertical{background:0 0;min-height:20px;border-radius:2px}QScrollBar::add-line:vertical{border:1px solid #1b1b19;border-radius:2px;background:0 0;height:14px;subcontrol-position:bottom;subcontrol-origin:margin}QScrollBar::sub-line:vertical{border:1px solid #1b1b19;border-radius:2px;background:0 0;height:14px;subcontrol-position:top;subcontrol-origin:margin}QScrollBar::down-arrow:vertical,QScrollBar::up-arrow:vertical{border:1px solid #000;width:1px;height:1px;background:#fff}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:0 0}QPlainTextEdit,QTextEdit{background-color:#242424}QHeaderView::section{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #616161,stop:.5 #505050,stop:.6 #434343,stop:1 #656565);color:#fff;padding-left:4px;border:1px solid #6c6c6c}QCheckBox:disabled{color:#414141}QDockWidget::title{text-align:center;spacing:3px;background-color:QLinearGradient(x1:0,"
                        "y1:0,x2:0,y2:1,stop:0 #323232,stop:.5 #242424,stop:1 #323232)}QDockWidget::close-button,QDockWidget::float-button{text-align:center;spacing:1px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #323232,stop:.5 #242424,stop:1 #323232)}QDockWidget::close-button:hover,QDockWidget::float-button:hover{background:#242424}QDockWidget::close-button:pressed,QDockWidget::float-button:pressed{padding:1px -1px -1px 1px}QMainWindow::separator{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #161616,stop:.5 #151515,stop:.6 #212121,stop:1 #343434);color:#fff;padding-left:4px;border:1px solid #4c4c4c;spacing:3px}QMainWindow::separator:hover{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #d7801a,stop:.5 #b56c17 stop:1 #ffa02f);color:#fff;padding-left:4px;border:1px solid #6c6c6c;spacing:3px}QToolBar::handle{spacing:3px;background:url(:/images/handle.png)}QMenu::separator{height:2px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #161616,stop:.5 #151515,stop:.6 #212121,stop:1 #34343"
                        "4);color:#fff;padding-left:4px;margin-left:10px;margin-right:5px}QProgressBar{border:2px solid grey;border-radius:5px;text-align:center}QProgressBar::chunk{background-color:#d7801a;width:2.15px;margin:.5px}QTabBar::tab{color:#b1b1b1;border:1px solid #444;border-bottom-style:none;background-color:#323232;padding:3px 10px 2px;margin-right:-1px}QTabWidget::pane{border:1px solid #444;top:1px}QTabBar::tab:last{margin-right:0;border-top-right-radius:3px}QTabBar::tab:first:!selected{margin-left:0;border-top-left-radius:3px}QTabBar::tab:!selected{color:#b1b1b1;border-bottom-style:solid;margin-top:3px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:1 #212121,stop:.4 #343434)}QTabBar::tab:selected{border-top-left-radius:3px;border-top-right-radius:3px;margin-bottom:0}QTabBar::tab:!selected:hover{border-top-left-radius:3px;border-top-right-radius:3px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:1 #212121,stop:.4 #343434,stop:.2 #343434,stop:.1 #fa0)}QRadioButton::indicator:checked,QRadioButton::ind"
                        "icator:unchecked{color:#b1b1b1;background-color:#323232;border:1px solid #b1b1b1;border-radius:6px}QRadioButton::indicator:checked{background-color:qradialgradient(cx:.5,cy:.5,fx:.5,fy:.5,radius:1,stop:.25 #fa0,stop:.3 #323232)}QCheckBox::indicator{color:#b1b1b1;background-color:#323232;border:1px solid #b1b1b1;width:9px;height:9px}QRadioButton::indicator{border-radius:6px}QCheckBox::indicator:hover,QRadioButton::indicator:hover{border:1px solid #fa0}QCheckBox::indicator:checked{image:url(:/images/checkbox.png)}QCheckBox::indicator:disabled,QRadioButton::indicator:disabled{border:1px solid #444}"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QString::fromUtf8("actionSave_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Game);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
