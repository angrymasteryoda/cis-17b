#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gamewindow.h"
#include "howtodialog.h"

MainWindow::MainWindow( QWidget *parent ) : QMainWindow( parent ), ui( new Ui::MainWindow ) {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newButton_clicked() {
    GameWindow *game = new GameWindow;
    game->show();
    this->close();
}

void MainWindow::on_howtoButton_clicked()
{
    HowToDialog *how = new HowToDialog;
    how->show();
}

void MainWindow::on_actionNew_Game_triggered() {
    on_newButton_clicked();
}
