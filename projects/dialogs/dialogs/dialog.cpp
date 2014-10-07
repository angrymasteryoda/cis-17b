#include "dialog.h"
#include "ui_dialog.h"
#include "gameover.h"
#include "difficulty.h"
#include "save.h"

Dialog::Dialog( QWidget *parent ) :
    QDockWidget( parent ),
    ui( new Ui::Dialog ) {
        ui->setupUi(this);
    }

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_gameOverButton_clicked() {
    GameOver *window = new GameOver;
    window->show();
}

void Dialog::on_diffButton_clicked() {
    Difficulty *window = new Difficulty;
    window->show();
}

void Dialog::on_saveButton_clicked() {
    Save *window = new Save;
    window->show();
}

void Dialog::on_cancelButton_clicked() {
    //TODO exit the program is it just exit(0);
    //exit(0);
}
