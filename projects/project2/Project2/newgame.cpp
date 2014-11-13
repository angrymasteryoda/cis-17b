#include "newgame.h"
#include "ui_newgame.h"

NewGame::NewGame(QWidget *parent) : QDialog(parent), ui(new Ui::NewGame) {
    ui->setupUi(this);

    connect( ui->buttonBox, SIGNAL( accepted() ), this, SLOT( accept()) );
    connect( ui->buttonBox, SIGNAL( rejected() ), this, SLOT( rejected()) );
}

NewGame::~NewGame() {
    delete ui;
}
