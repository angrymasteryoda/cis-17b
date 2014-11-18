#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "gamewindow.h"
#include "howtodialog.h"
#include <QtCore>
#include <QtGui>

MainWindow::MainWindow( QWidget *parent ) : QMainWindow( parent ), ui( new Ui::MainWindow ) {
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newButton_clicked() {
    GameWindow *game = new GameWindow( 0, ui->difficultyCombo->currentIndex() );
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
    items << tr("Easy") << tr( "Medium" ) << tr( "Hard" ) << tr( "Insane");

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
        else {
            level = 3;
        }
    }

    GameWindow *game = new GameWindow( 0, level );
    game->show();
    this->close();
    //on_newButton_clicked();
}
