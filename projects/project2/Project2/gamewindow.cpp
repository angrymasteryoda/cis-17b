#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <QDebug>


GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GameWindow) {
    ui->setupUi(this);
}

GameWindow::~GameWindow() {
    delete ui;
}

/**
 * back to main menu button action
 * @brief GameWindow::on_mainMenu_clicked
 */
void GameWindow::on_backButton_clicked() {
    MainWindow *main = new MainWindow;
    main->show();
    this->close();
}


//because i screwed something up and cant fix it
//void GameWindow::on_mainMenu_clicked(){return;}
//void GameWindow::on_mainMenuButton_clicked(){return;}
