#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include <QDebug>
#include <cmath>


GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GameWindow) {
    ui->setupUi(this);
    initGame();
}

GameWindow::~GameWindow() {
    delete ui;
    delete [] gameMatrix;
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


/**
 * init the game
 * @brief GameWindow::initGame
 */
void GameWindow::initGame(){
    gameMatrix = new int[81];
    for ( int i = 0; i < 9; i++ ) {
        for ( int j = 0; j < 9; j++ ) {
            gameMatrix[i * 9 + j] = (int) ( i * 3 + floor( i / 3 ) + j ) % 9 + 1;
        }
    }
    print();
}

/**
 * print the matrix to debug it
 * @brief GameWindow::print
 */
void GameWindow::print(){
    qDebug() << endl;
    for ( int i = 0; i < 9; i++ ) {
        QString line = "";
        for ( int j = 0; j < 9; j++ ) {
            line.append( QString::number(gameMatrix[i * 9 + j] ) ).append( " " );
        }
        qDebug() << line;
    }
}
