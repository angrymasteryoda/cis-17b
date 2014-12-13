#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include "howtodialog.h"
#include "settings.h"
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow( QWidget *parent ) : QMainWindow( parent ), ui( new Ui::MainWindow ) {
    ui->setupUi(this);
    connect( ui->actionExit, SIGNAL( triggered() ), this, SLOT( close() ) );
    connect( ui->actionLoad, SIGNAL( triggered() ), this, SLOT( on_pushButton_clicked() ) );
    connect( ui->actionHow_to_play, SIGNAL( triggered() ), this, SLOT( on_howtoButton_clicked() ) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newButton_clicked() {
    int level = ui->difficultyCombo->currentIndex() == 4 ? 0xff : ui->difficultyCombo->currentIndex();
    GameWindow *game = new GameWindow( 0, level );
    game->show();
    this->close();
}

void MainWindow::on_howtoButton_clicked()
{
    HowToDialog *how = new HowToDialog;
    how->show();
}

void MainWindow::on_actionNew_Game_triggered() {
    int level;
    QStringList items;
    items << tr("Easy") << tr( "Medium" ) << tr( "Hard" ) << tr( "Insane" ) << tr( "Debug" );

    bool ok;
    QString text = QInputDialog::getItem( this, tr( "New Game" ),
                                         tr( "Difficulty" ),  items, 0,
                                         false, &ok );
    if (ok && !text.isEmpty() ){
        text = text.toLower();
        if( text == "easy" ) {
            level = 0;
        }
        else if ( text == "medium" ){
            level = 1;
        }
        else if ( text == "hard" ){
            level = 2;
        }
        else if ( text == "insane" ){
            level = 3;
        }
        else{
            level = 0xff;
        }

        GameWindow *game = new GameWindow( 0, level );
        game->show();
        this->close();
    }

    //on_newButton_clicked();
}

void MainWindow::on_pushButton_clicked() {
    Settings settings( "save.ini" );
    if( settings.load() ){
        GameWindow *game = new GameWindow( 0, -1 );
        game->show();
        this->close();
    }
    else{
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this, tr("No Save Game"), "You have no save game to load from.");
    }
}
