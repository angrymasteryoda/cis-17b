#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include "howtodialog.h"
#include "save.h"

#include <QDebug>
#include <cmath>
#include <QtCore>
#include <QtGui>


GameWindow::GameWindow( QWidget *parent, int level ) : QMainWindow( parent ), ui( new Ui::GameWindow ) {
    ui->setupUi(this);

    saveFile = "save.ini";
    timeLoad = 0;
    isLoadGame = false;
    connect( ui->actionExit, SIGNAL( triggered() ), this, SLOT( close() ) );
    connect( ui->actionHow_To_Play, SIGNAL( triggered() ), this, SLOT( showHelp() ) );
    connect( ui->actionNew_Game, SIGNAL( triggered() ), this, SLOT( newGame() ) );
    connect( ui->actionSave, SIGNAL( triggered() ), this, SLOT( save() ) );
    connect( ui->actionSave_and_Exit, SIGNAL( triggered() ), this, SLOT( saveExit() ) );

    //begin cell configs
    if( level == -1 ){
        //load
        isLoadGame = true;
        load();
        startTime.start();
        print();
    } else {
        this->level = level;
        gameMatrix = zeroFill( 81 );
        mask = zeroFill( 81 );
        initCells();
        initGame();
    }
}

GameWindow::~GameWindow() {
    delete ui;
    delete [] gameMatrix;
    delete [] mask;
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
 * @brief GameWindow::initCells
 */
void GameWindow::initCells(){
    ui->cell_0_0->setInputMask( "D" );
    connect( ui->cell_0_0, SIGNAL( editingFinished() ), this, SLOT( cell_0_0_blur() ) );
    ui->cell_0_1->setInputMask( "D" );
    connect( ui->cell_0_1, SIGNAL( editingFinished() ), this, SLOT( cell_0_1_blur() ) );
    ui->cell_0_2->setInputMask( "D" );
    connect( ui->cell_0_2, SIGNAL( editingFinished() ), this, SLOT( cell_0_2_blur() ) );
    ui->cell_0_3->setInputMask( "D" );
    connect( ui->cell_0_3, SIGNAL( editingFinished() ), this, SLOT( cell_0_3_blur() ) );
    ui->cell_0_4->setInputMask( "D" );
    connect( ui->cell_0_4, SIGNAL( editingFinished() ), this, SLOT( cell_0_4_blur() ) );
    ui->cell_0_5->setInputMask( "D" );
    connect( ui->cell_0_5, SIGNAL( editingFinished() ), this, SLOT( cell_0_5_blur() ) );
    ui->cell_0_6->setInputMask( "D" );
    connect( ui->cell_0_6, SIGNAL( editingFinished() ), this, SLOT( cell_0_6_blur() ) );
    ui->cell_0_7->setInputMask( "D" );
    connect( ui->cell_0_7, SIGNAL( editingFinished() ), this, SLOT( cell_0_7_blur() ) );
    ui->cell_0_8->setInputMask( "D" );
    connect( ui->cell_0_8, SIGNAL( editingFinished() ), this, SLOT( cell_0_8_blur() ) );
    ui->cell_1_0->setInputMask( "D" );
    connect( ui->cell_1_0, SIGNAL( editingFinished() ), this, SLOT( cell_1_0_blur() ) );
    ui->cell_1_1->setInputMask( "D" );
    connect( ui->cell_1_1, SIGNAL( editingFinished() ), this, SLOT( cell_1_1_blur() ) );
    ui->cell_1_2->setInputMask( "D" );
    connect( ui->cell_1_2, SIGNAL( editingFinished() ), this, SLOT( cell_1_2_blur() ) );
    ui->cell_1_3->setInputMask( "D" );
    connect( ui->cell_1_3, SIGNAL( editingFinished() ), this, SLOT( cell_1_3_blur() ) );
    ui->cell_1_4->setInputMask( "D" );
    connect( ui->cell_1_4, SIGNAL( editingFinished() ), this, SLOT( cell_1_4_blur() ) );
    ui->cell_1_5->setInputMask( "D" );
    connect( ui->cell_1_5, SIGNAL( editingFinished() ), this, SLOT( cell_1_5_blur() ) );
    ui->cell_1_6->setInputMask( "D" );
    connect( ui->cell_1_6, SIGNAL( editingFinished() ), this, SLOT( cell_1_6_blur() ) );
    ui->cell_1_7->setInputMask( "D" );
    connect( ui->cell_1_7, SIGNAL( editingFinished() ), this, SLOT( cell_1_7_blur() ) );
    ui->cell_1_8->setInputMask( "D" );
    connect( ui->cell_1_8, SIGNAL( editingFinished() ), this, SLOT( cell_1_8_blur() ) );
    ui->cell_2_0->setInputMask( "D" );
    connect( ui->cell_2_0, SIGNAL( editingFinished() ), this, SLOT( cell_2_0_blur() ) );
    ui->cell_2_1->setInputMask( "D" );
    connect( ui->cell_2_1, SIGNAL( editingFinished() ), this, SLOT( cell_2_1_blur() ) );
    ui->cell_2_2->setInputMask( "D" );
    connect( ui->cell_2_2, SIGNAL( editingFinished() ), this, SLOT( cell_2_2_blur() ) );
    ui->cell_2_3->setInputMask( "D" );
    connect( ui->cell_2_3, SIGNAL( editingFinished() ), this, SLOT( cell_2_3_blur() ) );
    ui->cell_2_4->setInputMask( "D" );
    connect( ui->cell_2_4, SIGNAL( editingFinished() ), this, SLOT( cell_2_4_blur() ) );
    ui->cell_2_5->setInputMask( "D" );
    connect( ui->cell_2_5, SIGNAL( editingFinished() ), this, SLOT( cell_2_5_blur() ) );
    ui->cell_2_6->setInputMask( "D" );
    connect( ui->cell_2_6, SIGNAL( editingFinished() ), this, SLOT( cell_2_6_blur() ) );
    ui->cell_2_7->setInputMask( "D" );
    connect( ui->cell_2_7, SIGNAL( editingFinished() ), this, SLOT( cell_2_7_blur() ) );
    ui->cell_2_8->setInputMask( "D" );
    connect( ui->cell_2_8, SIGNAL( editingFinished() ), this, SLOT( cell_2_8_blur() ) );
    ui->cell_3_0->setInputMask( "D" );
    connect( ui->cell_3_0, SIGNAL( editingFinished() ), this, SLOT( cell_3_0_blur() ) );
    ui->cell_3_1->setInputMask( "D" );
    connect( ui->cell_3_1, SIGNAL( editingFinished() ), this, SLOT( cell_3_1_blur() ) );
    ui->cell_3_2->setInputMask( "D" );
    connect( ui->cell_3_2, SIGNAL( editingFinished() ), this, SLOT( cell_3_2_blur() ) );
    ui->cell_3_3->setInputMask( "D" );
    connect( ui->cell_3_3, SIGNAL( editingFinished() ), this, SLOT( cell_3_3_blur() ) );
    ui->cell_3_4->setInputMask( "D" );
    connect( ui->cell_3_4, SIGNAL( editingFinished() ), this, SLOT( cell_3_4_blur() ) );
    ui->cell_3_5->setInputMask( "D" );
    connect( ui->cell_3_5, SIGNAL( editingFinished() ), this, SLOT( cell_3_5_blur() ) );
    ui->cell_3_6->setInputMask( "D" );
    connect( ui->cell_3_6, SIGNAL( editingFinished() ), this, SLOT( cell_3_6_blur() ) );
    ui->cell_3_7->setInputMask( "D" );
    connect( ui->cell_3_7, SIGNAL( editingFinished() ), this, SLOT( cell_3_7_blur() ) );
    ui->cell_3_8->setInputMask( "D" );
    connect( ui->cell_3_8, SIGNAL( editingFinished() ), this, SLOT( cell_3_8_blur() ) );
    ui->cell_4_0->setInputMask( "D" );
    connect( ui->cell_4_0, SIGNAL( editingFinished() ), this, SLOT( cell_4_0_blur() ) );
    ui->cell_4_1->setInputMask( "D" );
    connect( ui->cell_4_1, SIGNAL( editingFinished() ), this, SLOT( cell_4_1_blur() ) );
    ui->cell_4_2->setInputMask( "D" );
    connect( ui->cell_4_2, SIGNAL( editingFinished() ), this, SLOT( cell_4_2_blur() ) );
    ui->cell_4_3->setInputMask( "D" );
    connect( ui->cell_4_3, SIGNAL( editingFinished() ), this, SLOT( cell_4_3_blur() ) );
    ui->cell_4_4->setInputMask( "D" );
    connect( ui->cell_4_4, SIGNAL( editingFinished() ), this, SLOT( cell_4_4_blur() ) );
    ui->cell_4_5->setInputMask( "D" );
    connect( ui->cell_4_5, SIGNAL( editingFinished() ), this, SLOT( cell_4_5_blur() ) );
    ui->cell_4_6->setInputMask( "D" );
    connect( ui->cell_4_6, SIGNAL( editingFinished() ), this, SLOT( cell_4_6_blur() ) );
    ui->cell_4_7->setInputMask( "D" );
    connect( ui->cell_4_7, SIGNAL( editingFinished() ), this, SLOT( cell_4_7_blur() ) );
    ui->cell_4_8->setInputMask( "D" );
    connect( ui->cell_4_8, SIGNAL( editingFinished() ), this, SLOT( cell_4_8_blur() ) );
    ui->cell_5_0->setInputMask( "D" );
    connect( ui->cell_5_0, SIGNAL( editingFinished() ), this, SLOT( cell_5_0_blur() ) );
    ui->cell_5_1->setInputMask( "D" );
    connect( ui->cell_5_1, SIGNAL( editingFinished() ), this, SLOT( cell_5_1_blur() ) );
    ui->cell_5_2->setInputMask( "D" );
    connect( ui->cell_5_2, SIGNAL( editingFinished() ), this, SLOT( cell_5_2_blur() ) );
    ui->cell_5_3->setInputMask( "D" );
    connect( ui->cell_5_3, SIGNAL( editingFinished() ), this, SLOT( cell_5_3_blur() ) );
    ui->cell_5_4->setInputMask( "D" );
    connect( ui->cell_5_4, SIGNAL( editingFinished() ), this, SLOT( cell_5_4_blur() ) );
    ui->cell_5_5->setInputMask( "D" );
    connect( ui->cell_5_5, SIGNAL( editingFinished() ), this, SLOT( cell_5_5_blur() ) );
    ui->cell_5_6->setInputMask( "D" );
    connect( ui->cell_5_6, SIGNAL( editingFinished() ), this, SLOT( cell_5_6_blur() ) );
    ui->cell_5_7->setInputMask( "D" );
    connect( ui->cell_5_7, SIGNAL( editingFinished() ), this, SLOT( cell_5_7_blur() ) );
    ui->cell_5_8->setInputMask( "D" );
    connect( ui->cell_5_8, SIGNAL( editingFinished() ), this, SLOT( cell_5_8_blur() ) );
    ui->cell_6_0->setInputMask( "D" );
    connect( ui->cell_6_0, SIGNAL( editingFinished() ), this, SLOT( cell_6_0_blur() ) );
    ui->cell_6_1->setInputMask( "D" );
    connect( ui->cell_6_1, SIGNAL( editingFinished() ), this, SLOT( cell_6_1_blur() ) );
    ui->cell_6_2->setInputMask( "D" );
    connect( ui->cell_6_2, SIGNAL( editingFinished() ), this, SLOT( cell_6_2_blur() ) );
    ui->cell_6_3->setInputMask( "D" );
    connect( ui->cell_6_3, SIGNAL( editingFinished() ), this, SLOT( cell_6_3_blur() ) );
    ui->cell_6_4->setInputMask( "D" );
    connect( ui->cell_6_4, SIGNAL( editingFinished() ), this, SLOT( cell_6_4_blur() ) );
    ui->cell_6_5->setInputMask( "D" );
    connect( ui->cell_6_5, SIGNAL( editingFinished() ), this, SLOT( cell_6_5_blur() ) );
    ui->cell_6_6->setInputMask( "D" );
    connect( ui->cell_6_6, SIGNAL( editingFinished() ), this, SLOT( cell_6_6_blur() ) );
    ui->cell_6_7->setInputMask( "D" );
    connect( ui->cell_6_7, SIGNAL( editingFinished() ), this, SLOT( cell_6_7_blur() ) );
    ui->cell_6_8->setInputMask( "D" );
    connect( ui->cell_6_8, SIGNAL( editingFinished() ), this, SLOT( cell_6_8_blur() ) );
    ui->cell_7_0->setInputMask( "D" );
    connect( ui->cell_7_0, SIGNAL( editingFinished() ), this, SLOT( cell_7_0_blur() ) );
    ui->cell_7_1->setInputMask( "D" );
    connect( ui->cell_7_1, SIGNAL( editingFinished() ), this, SLOT( cell_7_1_blur() ) );
    ui->cell_7_2->setInputMask( "D" );
    connect( ui->cell_7_2, SIGNAL( editingFinished() ), this, SLOT( cell_7_2_blur() ) );
    ui->cell_7_3->setInputMask( "D" );
    connect( ui->cell_7_3, SIGNAL( editingFinished() ), this, SLOT( cell_7_3_blur() ) );
    ui->cell_7_4->setInputMask( "D" );
    connect( ui->cell_7_4, SIGNAL( editingFinished() ), this, SLOT( cell_7_4_blur() ) );
    ui->cell_7_5->setInputMask( "D" );
    connect( ui->cell_7_5, SIGNAL( editingFinished() ), this, SLOT( cell_7_5_blur() ) );
    ui->cell_7_6->setInputMask( "D" );
    connect( ui->cell_7_6, SIGNAL( editingFinished() ), this, SLOT( cell_7_6_blur() ) );
    ui->cell_7_7->setInputMask( "D" );
    connect( ui->cell_7_7, SIGNAL( editingFinished() ), this, SLOT( cell_7_7_blur() ) );
    ui->cell_7_8->setInputMask( "D" );
    connect( ui->cell_7_8, SIGNAL( editingFinished() ), this, SLOT( cell_7_8_blur() ) );
    ui->cell_8_0->setInputMask( "D" );
    connect( ui->cell_8_0, SIGNAL( editingFinished() ), this, SLOT( cell_8_0_blur() ) );
    ui->cell_8_1->setInputMask( "D" );
    connect( ui->cell_8_1, SIGNAL( editingFinished() ), this, SLOT( cell_8_1_blur() ) );
    ui->cell_8_2->setInputMask( "D" );
    connect( ui->cell_8_2, SIGNAL( editingFinished() ), this, SLOT( cell_8_2_blur() ) );
    ui->cell_8_3->setInputMask( "D" );
    connect( ui->cell_8_3, SIGNAL( editingFinished() ), this, SLOT( cell_8_3_blur() ) );
    ui->cell_8_4->setInputMask( "D" );
    connect( ui->cell_8_4, SIGNAL( editingFinished() ), this, SLOT( cell_8_4_blur() ) );
    ui->cell_8_5->setInputMask( "D" );
    connect( ui->cell_8_5, SIGNAL( editingFinished() ), this, SLOT( cell_8_5_blur() ) );
    ui->cell_8_6->setInputMask( "D" );
    connect( ui->cell_8_6, SIGNAL( editingFinished() ), this, SLOT( cell_8_6_blur() ) );
    ui->cell_8_7->setInputMask( "D" );
    connect( ui->cell_8_7, SIGNAL( editingFinished() ), this, SLOT( cell_8_7_blur() ) );
    ui->cell_8_8->setInputMask( "D" );
    connect( ui->cell_8_8, SIGNAL( editingFinished() ), this, SLOT( cell_8_8_blur() ) );
}

/**
 * init the game
 * @brief GameWindow::initGame
 */
void GameWindow::initGame(){
    startTime.start();
    if( !isLoadGame ){
        for ( int i = 0; i < 9; i++ ) {
            for ( int j = 0; j < 9; j++ ) {
                gameMatrix[i * 9 + j] = (int) ( i * 3 + floor( i / 3 ) + j ) % 9 + 1;
            }
        }

        shuffle();
        showNumbers();
    }
    print();
}

/**
 * shuffles the gameMatrix
 * @brief GameWindow::shuffle
 */
void GameWindow::shuffle(){
    for ( int i = 0; i < 42; i++ ) {
        int n1 = ( rand( ) % 9 ) + 1;
        int n2;
        do {
            n2 = ( rand( ) % 9 ) + 1;
        } while ( n1 == n2 );

        for ( int  row = 0; row < 9; row++ ) {
            for ( int col = 0; col < 9; col++ ) {
                if ( gameMatrix[row * 9 + col] == n1 )
                    gameMatrix[row * 9 + col] = n2;
                else if ( gameMatrix[row * 9 + col] == n2 )
                    gameMatrix[row * 9 + col] = n1;
            }
        }
    }

    for( int i = 0; i < 42; i++ ){
        int s1 = ( rand() % 3 );
        int s2 = ( rand() % 3 );

        for( int row = 0; row < 9; row++ ){
            int temp = gameMatrix[ row * 9 + ( s1 *3 + i % 3 )];
            gameMatrix[row * 9 + (s1 * 3 + i % 3)] = gameMatrix[row * 9 + (s2 * 3 + i % 3)];
            gameMatrix[row * 9 + (s2 * 3 + i % 3)] = temp;
        }
    }

    for( int i = 0; i < 42; i++ ){
        int c1 = ( rand() % 3 );
        int c2 = ( rand() % 3 );

        for( int row = 0; row < 9; row++ ){
            int temp = gameMatrix[row * 9 + (i % 3 * 3 + c1)];
            gameMatrix[row * 9 + (i % 3 * 3 + c1)] = gameMatrix[row * 9 + (i % 3 * 3 + c2)];
            gameMatrix[row * 9 + (i % 3 * 3 + c2)] = temp;
        }
    }

    for( int i = 0; i < 42; i++ ){
        int r1 = ( rand() % 3 );
        int r2 = ( rand() % 3 );

        for( int col = 0; col < 9; col++ ){
            int temp = gameMatrix[(i % 3 * 3 + r1) * 9 + col];
            gameMatrix[(i % 3 * 3 + r1) * 9 + col] = gameMatrix[(i % 3 * 3 + r2) * 9 + col];
            gameMatrix[(i % 3 * 3 + r2) * 9 + col] = temp;
        }
    }
}

/**
 * cover up the numbers so that the game can be played
 * @brief GameWindow::showNumbers
 */
void GameWindow::showNumbers(){
    for( int i = 0; i < 81; i++ ){
       mask[i] = gameMatrix[i];
    }

    if ( level != 0xff ){
        for( int i = 0; i < 3; i++){
            for( int j = 0; j < 3; j++ ){
                //for each 3x3 square hide 5 numbers
                int showamt = 5;
                if ( level == 1 ){
                    showamt = random( 6, 5 );
                }
                else if( level == 2 ){
                    showamt = random( 8, 6 );
                }
                else if( level == 3 ){
                    showamt = random( 8, 7 );
                }
                for( int k = 0; k < showamt; k++ ){
                    int c = 0;
                    do{
                        c = rand() % 9;
                    }
                    while( mask[ (int)( i * 3 + floor( c / 3 ) ) * 9 + j * 3 + c % 3 ] == 0 );

                    mask[ (int)( i * 3 + floor( c / 3 ) ) * 9 + j * 3 + c %3 ] = 0;
                }
            }
        }
    }
    mask[0] = 0;

    if( !isSolvable() ){
        qDebug() << "Made the problem to hard";
        showNumbers();
    }
}

/**
 * is the game solvable with the bumber of clues given
 * @brief GameWindow::isSolvable
 * @return
 */
bool GameWindow::isSolvable(){
    // according to
    // http://www.technologyreview.com/view/426554/mathematicians-solve-minimum-sudoku-problem/
    // there has to be 17 clue
    int clues = 0;
    for( int r = 0; r < 9; r++ ){
        for( int c = 0; c < 9; c++ ){
            if( mask[ r * 9 + c ] !=  0 ){
                clues++;
            }
        }
    }
    if( clues >= 17 && clues < 81 ){
        return true;
    }
    else {
        return false;
    }

}

/**
 * print the matrix to the game or debug it
 * @brief GameWindow::print
 */
void GameWindow::print( bool debug ){
    if( debug ){
        qDebug() << "gameMatrix" << endl;
        for ( int i = 0; i < 9; i++ ) {
            QString line = "";
            for ( int j = 0; j < 9; j++ ) {
                line.append( QString::number(gameMatrix[i * 9 + j] ) ).append( " " );
            }
            qDebug() << line;
        }

        qDebug() << "mask" << endl;
        for ( int i = 0; i < 9; i++ ) {
            QString line = "";
            for ( int j = 0; j < 9; j++ ) {
                line.append( QString::number( mask[i * 9 + j] ) ).append( " " );
            }
            qDebug() << line;
        }
    }
    else {
        for ( int i = 0; i < 9; i++ ) {
            for ( int j = 0; j < 9; j++ ) {
                if( mask[ i * 9 + j ] !=  0 ){
                    setReadOnly( i, j, true );
                }
                setCell( i, j, mask[i * 9 + j] );
            }
        }
    }
}

/**
 * sets the cell to a certain value using the coord( row, col)
 * @brief GameWindow::setCell
 * @param row
 * @param col
 * @param set
 */
void GameWindow::setCell( int row, int col, int set ){
    if( set == 0 ){
        return;
    } else if ( set == -1 ){
        setCell( row, col, "" );
    } else {
        setCell( row, col, QString::number( set ) );
    }
}

/**
 * sets the cell to a certain value using the coord( row, col)
 * @brief GameWindow::setCell
 * @param row
 * @param col
 * @param set
 */
void GameWindow::setCell( int row, int col, QString set ){
    //dont set them if 0
    if( row == 0 ){
        if( col == 0 ) { ui->cell_0_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_0_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_0_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_0_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_0_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_0_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_0_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_0_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_0_8->setText( set ) ; return;}
    }
    if( row == 1 ){
        if( col == 0 ) { ui->cell_1_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_1_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_1_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_1_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_1_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_1_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_1_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_1_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_1_8->setText( set ) ; return;}
    }
    if( row == 2 ){
        if( col == 0 ) { ui->cell_2_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_2_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_2_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_2_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_2_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_2_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_2_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_2_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_2_8->setText( set ) ; return;}
    }
    if( row == 3 ){
        if( col == 0 ) { ui->cell_3_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_3_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_3_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_3_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_3_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_3_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_3_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_3_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_3_8->setText( set ) ; return;}
    }
    if( row == 4 ){
        if( col == 0 ) { ui->cell_4_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_4_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_4_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_4_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_4_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_4_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_4_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_4_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_4_8->setText( set ) ; return;}
    }
    if( row == 5 ){
        if( col == 0 ) { ui->cell_5_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_5_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_5_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_5_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_5_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_5_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_5_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_5_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_5_8->setText( set ) ; return;}
    }
    if( row == 6 ){
        if( col == 0 ) { ui->cell_6_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_6_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_6_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_6_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_6_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_6_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_6_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_6_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_6_8->setText( set ) ; return;}
    }
    if( row == 7 ){
        if( col == 0 ) { ui->cell_7_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_7_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_7_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_7_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_7_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_7_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_7_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_7_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_7_8->setText( set ) ; return;}
    }
    if( row == 8 ){
        if( col == 0 ) { ui->cell_8_0->setText( set ) ; return;}
        if( col == 1 ) { ui->cell_8_1->setText( set ) ; return;}
        if( col == 2 ) { ui->cell_8_2->setText( set ) ; return;}
        if( col == 3 ) { ui->cell_8_3->setText( set ) ; return;}
        if( col == 4 ) { ui->cell_8_4->setText( set ) ; return;}
        if( col == 5 ) { ui->cell_8_5->setText( set ) ; return;}
        if( col == 6 ) { ui->cell_8_6->setText( set ) ; return;}
        if( col == 7 ) { ui->cell_8_7->setText( set ) ; return;}
        if( col == 8 ) { ui->cell_8_8->setText( set ) ; return;}
    }
}

/**
 * get the value of cells by coords ( row, col )
 * @brief GameWindow::getCell
 * @param row
 * @param col
 * @return qstring
 */
QString GameWindow::getCell( int row, int col ){
    if( row == 0 ){
        if( col == 0 ) { return ui->cell_0_0->text() ; }
        if( col == 1 ) { return ui->cell_0_1->text() ; }
        if( col == 2 ) { return ui->cell_0_2->text() ; }
        if( col == 3 ) { return ui->cell_0_3->text() ; }
        if( col == 4 ) { return ui->cell_0_4->text() ; }
        if( col == 5 ) { return ui->cell_0_5->text() ; }
        if( col == 6 ) { return ui->cell_0_6->text() ; }
        if( col == 7 ) { return ui->cell_0_7->text() ; }
        if( col == 8 ) { return ui->cell_0_8->text() ; }
    }
    if( row == 1 ){
        if( col == 0 ) { return ui->cell_1_0->text() ; }
        if( col == 1 ) { return ui->cell_1_1->text() ; }
        if( col == 2 ) { return ui->cell_1_2->text() ; }
        if( col == 3 ) { return ui->cell_1_3->text() ; }
        if( col == 4 ) { return ui->cell_1_4->text() ; }
        if( col == 5 ) { return ui->cell_1_5->text() ; }
        if( col == 6 ) { return ui->cell_1_6->text() ; }
        if( col == 7 ) { return ui->cell_1_7->text() ; }
        if( col == 8 ) { return ui->cell_1_8->text() ; }
    }
    if( row == 2 ){
        if( col == 0 ) { return ui->cell_2_0->text() ; }
        if( col == 1 ) { return ui->cell_2_1->text() ; }
        if( col == 2 ) { return ui->cell_2_2->text() ; }
        if( col == 3 ) { return ui->cell_2_3->text() ; }
        if( col == 4 ) { return ui->cell_2_4->text() ; }
        if( col == 5 ) { return ui->cell_2_5->text() ; }
        if( col == 6 ) { return ui->cell_2_6->text() ; }
        if( col == 7 ) { return ui->cell_2_7->text() ; }
        if( col == 8 ) { return ui->cell_2_8->text() ; }
    }
    if( row == 3 ){
        if( col == 0 ) { return ui->cell_3_0->text() ; }
        if( col == 1 ) { return ui->cell_3_1->text() ; }
        if( col == 2 ) { return ui->cell_3_2->text() ; }
        if( col == 3 ) { return ui->cell_3_3->text() ; }
        if( col == 4 ) { return ui->cell_3_4->text() ; }
        if( col == 5 ) { return ui->cell_3_5->text() ; }
        if( col == 6 ) { return ui->cell_3_6->text() ; }
        if( col == 7 ) { return ui->cell_3_7->text() ; }
        if( col == 8 ) { return ui->cell_3_8->text() ; }
    }
    if( row == 4 ){
        if( col == 0 ) { return ui->cell_4_0->text() ; }
        if( col == 1 ) { return ui->cell_4_1->text() ; }
        if( col == 2 ) { return ui->cell_4_2->text() ; }
        if( col == 3 ) { return ui->cell_4_3->text() ; }
        if( col == 4 ) { return ui->cell_4_4->text() ; }
        if( col == 5 ) { return ui->cell_4_5->text() ; }
        if( col == 6 ) { return ui->cell_4_6->text() ; }
        if( col == 7 ) { return ui->cell_4_7->text() ; }
        if( col == 8 ) { return ui->cell_4_8->text() ; }
    }
    if( row == 5 ){
        if( col == 0 ) { return ui->cell_5_0->text() ; }
        if( col == 1 ) { return ui->cell_5_1->text() ; }
        if( col == 2 ) { return ui->cell_5_2->text() ; }
        if( col == 3 ) { return ui->cell_5_3->text() ; }
        if( col == 4 ) { return ui->cell_5_4->text() ; }
        if( col == 5 ) { return ui->cell_5_5->text() ; }
        if( col == 6 ) { return ui->cell_5_6->text() ; }
        if( col == 7 ) { return ui->cell_5_7->text() ; }
        if( col == 8 ) { return ui->cell_5_8->text() ; }
    }
    if( row == 6 ){
        if( col == 0 ) { return ui->cell_6_0->text() ; }
        if( col == 1 ) { return ui->cell_6_1->text() ; }
        if( col == 2 ) { return ui->cell_6_2->text() ; }
        if( col == 3 ) { return ui->cell_6_3->text() ; }
        if( col == 4 ) { return ui->cell_6_4->text() ; }
        if( col == 5 ) { return ui->cell_6_5->text() ; }
        if( col == 6 ) { return ui->cell_6_6->text() ; }
        if( col == 7 ) { return ui->cell_6_7->text() ; }
        if( col == 8 ) { return ui->cell_6_8->text() ; }
    }
    if( row == 7 ){
        if( col == 0 ) { return ui->cell_7_0->text() ; }
        if( col == 1 ) { return ui->cell_7_1->text() ; }
        if( col == 2 ) { return ui->cell_7_2->text() ; }
        if( col == 3 ) { return ui->cell_7_3->text() ; }
        if( col == 4 ) { return ui->cell_7_4->text() ; }
        if( col == 5 ) { return ui->cell_7_5->text() ; }
        if( col == 6 ) { return ui->cell_7_6->text() ; }
        if( col == 7 ) { return ui->cell_7_7->text() ; }
        if( col == 8 ) { return ui->cell_7_8->text() ; }
    }
    if( row == 8 ){
        if( col == 0 ) { return ui->cell_8_0->text() ; }
        if( col == 1 ) { return ui->cell_8_1->text() ; }
        if( col == 2 ) { return ui->cell_8_2->text() ; }
        if( col == 3 ) { return ui->cell_8_3->text() ; }
        if( col == 4 ) { return ui->cell_8_4->text() ; }
        if( col == 5 ) { return ui->cell_8_5->text() ; }
        if( col == 6 ) { return ui->cell_8_6->text() ; }
        if( col == 7 ) { return ui->cell_8_7->text() ; }
        if( col == 8 ) { return ui->cell_8_8->text() ; }
    }
    return "";
}

/**
 * disconnect lineedits
 * @brief GameWindow::disconnectCell
 * @param row
 * @param col
 */
void GameWindow::disconnectCell( int row, int col ){
    if( row == 0 ){
        if( col == 0 ) { disconnect( ui->cell_0_0, SIGNAL( editingFinished() ), this, SLOT( cell_0_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_0_1, SIGNAL( editingFinished() ), this, SLOT( cell_0_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_0_2, SIGNAL( editingFinished() ), this, SLOT( cell_0_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_0_3, SIGNAL( editingFinished() ), this, SLOT( cell_0_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_0_4, SIGNAL( editingFinished() ), this, SLOT( cell_0_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_0_5, SIGNAL( editingFinished() ), this, SLOT( cell_0_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_0_6, SIGNAL( editingFinished() ), this, SLOT( cell_0_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_0_7, SIGNAL( editingFinished() ), this, SLOT( cell_0_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_0_8, SIGNAL( editingFinished() ), this, SLOT( cell_0_8_blur() ) ); }
    }
    if( row == 1 ){
        if( col == 0 ) { disconnect( ui->cell_1_0, SIGNAL( editingFinished() ), this, SLOT( cell_1_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_1_1, SIGNAL( editingFinished() ), this, SLOT( cell_1_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_1_2, SIGNAL( editingFinished() ), this, SLOT( cell_1_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_1_3, SIGNAL( editingFinished() ), this, SLOT( cell_1_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_1_4, SIGNAL( editingFinished() ), this, SLOT( cell_1_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_1_5, SIGNAL( editingFinished() ), this, SLOT( cell_1_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_1_6, SIGNAL( editingFinished() ), this, SLOT( cell_1_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_1_7, SIGNAL( editingFinished() ), this, SLOT( cell_1_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_1_8, SIGNAL( editingFinished() ), this, SLOT( cell_1_8_blur() ) ); }
    }
    if( row == 2 ){
        if( col == 0 ) { disconnect( ui->cell_2_0, SIGNAL( editingFinished() ), this, SLOT( cell_2_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_2_1, SIGNAL( editingFinished() ), this, SLOT( cell_2_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_2_2, SIGNAL( editingFinished() ), this, SLOT( cell_2_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_2_3, SIGNAL( editingFinished() ), this, SLOT( cell_2_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_2_4, SIGNAL( editingFinished() ), this, SLOT( cell_2_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_2_5, SIGNAL( editingFinished() ), this, SLOT( cell_2_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_2_6, SIGNAL( editingFinished() ), this, SLOT( cell_2_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_2_7, SIGNAL( editingFinished() ), this, SLOT( cell_2_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_2_8, SIGNAL( editingFinished() ), this, SLOT( cell_2_8_blur() ) ); }
    }
    if( row == 3 ){
        if( col == 0 ) { disconnect( ui->cell_3_0, SIGNAL( editingFinished() ), this, SLOT( cell_3_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_3_1, SIGNAL( editingFinished() ), this, SLOT( cell_3_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_3_2, SIGNAL( editingFinished() ), this, SLOT( cell_3_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_3_3, SIGNAL( editingFinished() ), this, SLOT( cell_3_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_3_4, SIGNAL( editingFinished() ), this, SLOT( cell_3_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_3_5, SIGNAL( editingFinished() ), this, SLOT( cell_3_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_3_6, SIGNAL( editingFinished() ), this, SLOT( cell_3_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_3_7, SIGNAL( editingFinished() ), this, SLOT( cell_3_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_3_8, SIGNAL( editingFinished() ), this, SLOT( cell_3_8_blur() ) ); }
    }
    if( row == 4 ){
        if( col == 0 ) { disconnect( ui->cell_4_0, SIGNAL( editingFinished() ), this, SLOT( cell_4_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_4_1, SIGNAL( editingFinished() ), this, SLOT( cell_4_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_4_2, SIGNAL( editingFinished() ), this, SLOT( cell_4_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_4_3, SIGNAL( editingFinished() ), this, SLOT( cell_4_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_4_4, SIGNAL( editingFinished() ), this, SLOT( cell_4_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_4_5, SIGNAL( editingFinished() ), this, SLOT( cell_4_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_4_6, SIGNAL( editingFinished() ), this, SLOT( cell_4_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_4_7, SIGNAL( editingFinished() ), this, SLOT( cell_4_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_4_8, SIGNAL( editingFinished() ), this, SLOT( cell_4_8_blur() ) ); }
    }
    if( row == 5 ){
        if( col == 0 ) { disconnect( ui->cell_5_0, SIGNAL( editingFinished() ), this, SLOT( cell_5_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_5_1, SIGNAL( editingFinished() ), this, SLOT( cell_5_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_5_2, SIGNAL( editingFinished() ), this, SLOT( cell_5_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_5_3, SIGNAL( editingFinished() ), this, SLOT( cell_5_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_5_4, SIGNAL( editingFinished() ), this, SLOT( cell_5_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_5_5, SIGNAL( editingFinished() ), this, SLOT( cell_5_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_5_6, SIGNAL( editingFinished() ), this, SLOT( cell_5_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_5_7, SIGNAL( editingFinished() ), this, SLOT( cell_5_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_5_8, SIGNAL( editingFinished() ), this, SLOT( cell_5_8_blur() ) ); }
    }
    if( row == 6 ){
        if( col == 0 ) { disconnect( ui->cell_6_0, SIGNAL( editingFinished() ), this, SLOT( cell_6_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_6_1, SIGNAL( editingFinished() ), this, SLOT( cell_6_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_6_2, SIGNAL( editingFinished() ), this, SLOT( cell_6_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_6_3, SIGNAL( editingFinished() ), this, SLOT( cell_6_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_6_4, SIGNAL( editingFinished() ), this, SLOT( cell_6_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_6_5, SIGNAL( editingFinished() ), this, SLOT( cell_6_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_6_6, SIGNAL( editingFinished() ), this, SLOT( cell_6_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_6_7, SIGNAL( editingFinished() ), this, SLOT( cell_6_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_6_8, SIGNAL( editingFinished() ), this, SLOT( cell_6_8_blur() ) ); }
    }
    if( row == 7 ){
        if( col == 0 ) { disconnect( ui->cell_7_0, SIGNAL( editingFinished() ), this, SLOT( cell_7_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_7_1, SIGNAL( editingFinished() ), this, SLOT( cell_7_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_7_2, SIGNAL( editingFinished() ), this, SLOT( cell_7_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_7_3, SIGNAL( editingFinished() ), this, SLOT( cell_7_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_7_4, SIGNAL( editingFinished() ), this, SLOT( cell_7_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_7_5, SIGNAL( editingFinished() ), this, SLOT( cell_7_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_7_6, SIGNAL( editingFinished() ), this, SLOT( cell_7_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_7_7, SIGNAL( editingFinished() ), this, SLOT( cell_7_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_7_8, SIGNAL( editingFinished() ), this, SLOT( cell_7_8_blur() ) ); }
    }
    if( row == 8 ){
        if( col == 0 ) { disconnect( ui->cell_8_0, SIGNAL( editingFinished() ), this, SLOT( cell_8_0_blur() ) ); }
        if( col == 1 ) { disconnect( ui->cell_8_1, SIGNAL( editingFinished() ), this, SLOT( cell_8_1_blur() ) ); }
        if( col == 2 ) { disconnect( ui->cell_8_2, SIGNAL( editingFinished() ), this, SLOT( cell_8_2_blur() ) ); }
        if( col == 3 ) { disconnect( ui->cell_8_3, SIGNAL( editingFinished() ), this, SLOT( cell_8_3_blur() ) ); }
        if( col == 4 ) { disconnect( ui->cell_8_4, SIGNAL( editingFinished() ), this, SLOT( cell_8_4_blur() ) ); }
        if( col == 5 ) { disconnect( ui->cell_8_5, SIGNAL( editingFinished() ), this, SLOT( cell_8_5_blur() ) ); }
        if( col == 6 ) { disconnect( ui->cell_8_6, SIGNAL( editingFinished() ), this, SLOT( cell_8_6_blur() ) ); }
        if( col == 7 ) { disconnect( ui->cell_8_7, SIGNAL( editingFinished() ), this, SLOT( cell_8_7_blur() ) ); }
        if( col == 8 ) { disconnect( ui->cell_8_8, SIGNAL( editingFinished() ), this, SLOT( cell_8_8_blur() ) ); }
    }
}

/**
 * set the readonly state on the cell
 * @brief GameWindow::setReadOnly
 * @param row
 * @param col
 * @param flag
 */
void GameWindow::setReadOnly( int row, int col, bool flag ){
    if( row == 0 ){
        if( col == 0 ) { ui->cell_0_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_0_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_0_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_0_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_0_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_0_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_0_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_0_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_0_8->setReadOnly( flag ); return; }
    }
    if( row == 1 ){
        if( col == 0 ) { ui->cell_1_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_1_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_1_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_1_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_1_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_1_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_1_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_1_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_1_8->setReadOnly( flag ); return; }
    }
    if( row == 2 ){
        if( col == 0 ) { ui->cell_2_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_2_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_2_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_2_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_2_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_2_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_2_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_2_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_2_8->setReadOnly( flag ); return; }
    }
    if( row == 3 ){
        if( col == 0 ) { ui->cell_3_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_3_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_3_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_3_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_3_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_3_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_3_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_3_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_3_8->setReadOnly( flag ); return; }
    }
    if( row == 4 ){
        if( col == 0 ) { ui->cell_4_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_4_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_4_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_4_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_4_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_4_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_4_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_4_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_4_8->setReadOnly( flag ); return; }
    }
    if( row == 5 ){
        if( col == 0 ) { ui->cell_5_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_5_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_5_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_5_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_5_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_5_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_5_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_5_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_5_8->setReadOnly( flag ); return; }
    }
    if( row == 6 ){
        if( col == 0 ) { ui->cell_6_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_6_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_6_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_6_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_6_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_6_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_6_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_6_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_6_8->setReadOnly( flag ); return; }
    }
    if( row == 7 ){
        if( col == 0 ) { ui->cell_7_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_7_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_7_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_7_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_7_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_7_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_7_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_7_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_7_8->setReadOnly( flag ); return; }
    }
    if( row == 8 ){
        if( col == 0 ) { ui->cell_8_0->setReadOnly( flag ); return; }
        if( col == 1 ) { ui->cell_8_1->setReadOnly( flag ); return; }
        if( col == 2 ) { ui->cell_8_2->setReadOnly( flag ); return; }
        if( col == 3 ) { ui->cell_8_3->setReadOnly( flag ); return; }
        if( col == 4 ) { ui->cell_8_4->setReadOnly( flag ); return; }
        if( col == 5 ) { ui->cell_8_5->setReadOnly( flag ); return; }
        if( col == 6 ) { ui->cell_8_6->setReadOnly( flag ); return; }
        if( col == 7 ) { ui->cell_8_7->setReadOnly( flag ); return; }
        if( col == 8 ) { ui->cell_8_8->setReadOnly( flag ); return; }
    }
}

/**
 * fill an array with zeros
 * @brief GameWindow::zeroFill
 * @param size
 * @return int*
 */
int *GameWindow::zeroFill( int size ){
    int* res = new int[ size ];
    for( int i = 0; i < size; i++ ){
        res[i] = 0;
    }
    return res;
}

/**
 * returns a range of [min, max] min defaulted to 0
 * @brief random
 * @param max
 * @param min
 * @return
 */
int GameWindow::random( int max, int min ){
    return  min + ( rand() % ( max - min + 1 ) );
}

/**
 * show help dialog
 * @brief GameWindow::showHelp
 */
void GameWindow::showHelp(){
    HowToDialog *how = new HowToDialog;
    how->show();
}

/**
 * create a new game
 * @brief GameWindow::newGame
 */
void GameWindow::newGame(){
    QStringList items;
    items << tr("Easy") << tr( "Medium" ) << tr( "Hard" ) << tr( "Insane") << tr( "Debug" );;

    bool ok;
    QString text = QInputDialog::getItem( this, tr( "New Game" ),
                                         tr( "Difficulty" ),  items, 0,
                                         false, &ok );
    if ( ok && !text.isEmpty() ){
        text = text.toLower();
        if( text == "easy" ) {// .compare( "easy" ) ){
            reset( 0 );
        }
        else if ( text == "medium" ){
            reset( 1 );
        }
        else if ( text == "hard" ){
            reset( 2 );
        }
        else if ( text == "insane" ){
            reset( 3 );
        }
        else{
            reset( 0xff );
        }
    }
}

/**
 * reset the board to play a new game
 * @brief GameWindow::reset
 * @param level
 */
void GameWindow::reset( int level ){
    isLoadGame = false;
    timeLoad = 0;
    for( int r = 0; r < 9; r++ ){
        for( int c = 0; c < 9; c++ ){
            disconnectCell( r, c );
            setReadOnly( r, c, false );
            setCell( r, c, "" );
        }
    }
    clear( this->mask );
    clear( this->gameMatrix );
    this->level = level;
    initCells();
    initGame();
}

/**
 * zero out an array assuming the length is 81
 * @brief clear
 * @param arr
 */
void GameWindow::clear( int* arr ){
    for( int i = 0; i < 81; i++ ){
        arr[i] = 0;
    }
}

/**
 * should be what happens when all line edits blur
 * @brief GameWindow::blur
 * @param row
 * @param col
 */
void GameWindow::blur( int row, int col ){
    QString got = getCell( row, col );
    int gotI = got.toInt();
    setMask( row, col, gotI );
    isSolved();
}

/**
 * set the mask array at (row, col)
 * @brief setMask
 * @param row
 * @param col
 * @param set
 */
void GameWindow::setMask( int row, int col, int set ){
    mask[ row * 9 + col ] = set;
}

/**
 * is the game solved?
 * @brief GameWindow::isSolved
 * @return
 */
void GameWindow::isSolved(){
    bool isOver = true;
    for( int r = 0; r < 9; r++ ){
        for( int c = 0; c < 9; c++ ){
            if( mask[r * 9 + c] != gameMatrix[r * 9 + c] ){
                isOver = false;
            }
        }
    }

    if( isOver ){
        //you won
        for( int r = 0; r < 9; r++ ){
            for( int c = 0; c < 9; c++ ){
                disconnectCell( r, c );
            }
        }
        gameOver();
    }
}

/**
 * prints the you won dialog and opens the newgame dialog after you
 * @brief GameWindow::gameOver
 */
void GameWindow::gameOver(){
    QMessageBox::StandardButton reply;
    int time = ( ( timeLoad + startTime.elapsed() ) / 1000 ) / 60;
    QString msg = QString("You Won! It took you %1 minutes to finish. Start a new game?").arg( time );
    reply = QMessageBox::question(this, tr("You Won!"), msg, QMessageBox::Yes | QMessageBox::No );
    if (reply == QMessageBox::Yes) {
        newGame();
    }
}

/**
 * saves the game to save.ini
 * @brief GameWindow::save
 */
void GameWindow::save(){
    Settings settings( saveFile, true );
    settings.load();
    if( settings.getIsLoaded() ){
        int time = ( startTime.elapsed() );
        settings.saveSetting( "mask", arrayToJson( mask ) );
        settings.saveSetting( "board", arrayToJson( gameMatrix ) );
        settings.saveSetting( "time", QString::number( time ) );
        settings.saveSetting( "level", QString::number( level ) );
    }
}

/**
 * transforms a int array into a json string
 * @brief GameWindow::arrayToJson
 * @param array
 * @return
 */
QString GameWindow::arrayToJson( int *array ){
    int boardSize = 81;
    QString str = "[";
    for( int i = 0; i < boardSize; i++ ){
        str.append( QString::number( array[i] ) );
        if( i < boardSize - 1 ){
            str += ",";
        }
    }
    str.append( "]" );
    return str;
}

/**
 * returns an int array from a json string
 * @brief Save::jsonToArray
 * @param str
 * @return
 */
int* GameWindow::jsonToArray( QString str ){
    str = str.replace( QRegExp( "\\[([0-9,]+)\\]" ), "\\1" );
    QStringList list = str.split( "," );
    int* res = new int[ list.size() ];
    for( int i = 0; i < list.size(); i++ ){
        res[i] = list[i].toInt();
    }
    return res;
}

/**
 * load the game from file if one exists no error checking it MUST be right in the file
 * @brief GameWindow::load
 */
void GameWindow::load(){
    Settings settings( saveFile );
    settings.load();
    if( settings.getIsLoaded() ){
        gameMatrix = jsonToArray( settings.getSetting( "board" ) );
        mask = jsonToArray( settings.getSetting( "mask" ) );
        level = settings.getSetting( "level" ).toInt();
        timeLoad = settings.getSetting( "time" ).toInt();
    }
}

void GameWindow::saveExit(){
    save();
    exit(0);
}

//being lineedit slots
void GameWindow::cell_0_0_blur(){ blur( 0, 0); }
void GameWindow::cell_0_1_blur(){ blur( 0, 1); }
void GameWindow::cell_0_2_blur(){ blur( 0, 2); }
void GameWindow::cell_0_3_blur(){ blur( 0, 3); }
void GameWindow::cell_0_4_blur(){ blur( 0, 4); }
void GameWindow::cell_0_5_blur(){ blur( 0, 5); }
void GameWindow::cell_0_6_blur(){ blur( 0, 6); }
void GameWindow::cell_0_7_blur(){ blur( 0, 7); }
void GameWindow::cell_0_8_blur(){ blur( 0, 8); }
void GameWindow::cell_1_0_blur(){ blur( 1, 0); }
void GameWindow::cell_1_1_blur(){ blur( 1, 1); }
void GameWindow::cell_1_2_blur(){ blur( 1, 2); }
void GameWindow::cell_1_3_blur(){ blur( 1, 3); }
void GameWindow::cell_1_4_blur(){ blur( 1, 4); }
void GameWindow::cell_1_5_blur(){ blur( 1, 5); }
void GameWindow::cell_1_6_blur(){ blur( 1, 6); }
void GameWindow::cell_1_7_blur(){ blur( 1, 7); }
void GameWindow::cell_1_8_blur(){ blur( 1, 8); }
void GameWindow::cell_2_0_blur(){ blur( 2, 0); }
void GameWindow::cell_2_1_blur(){ blur( 2, 1); }
void GameWindow::cell_2_2_blur(){ blur( 2, 2); }
void GameWindow::cell_2_3_blur(){ blur( 2, 3); }
void GameWindow::cell_2_4_blur(){ blur( 2, 4); }
void GameWindow::cell_2_5_blur(){ blur( 2, 5); }
void GameWindow::cell_2_6_blur(){ blur( 2, 6); }
void GameWindow::cell_2_7_blur(){ blur( 2, 7); }
void GameWindow::cell_2_8_blur(){ blur( 2, 8); }
void GameWindow::cell_3_0_blur(){ blur( 3, 0); }
void GameWindow::cell_3_1_blur(){ blur( 3, 1); }
void GameWindow::cell_3_2_blur(){ blur( 3, 2); }
void GameWindow::cell_3_3_blur(){ blur( 3, 3); }
void GameWindow::cell_3_4_blur(){ blur( 3, 4); }
void GameWindow::cell_3_5_blur(){ blur( 3, 5); }
void GameWindow::cell_3_6_blur(){ blur( 3, 6); }
void GameWindow::cell_3_7_blur(){ blur( 3, 7); }
void GameWindow::cell_3_8_blur(){ blur( 3, 8); }
void GameWindow::cell_4_0_blur(){ blur( 4, 0); }
void GameWindow::cell_4_1_blur(){ blur( 4, 1); }
void GameWindow::cell_4_2_blur(){ blur( 4, 2); }
void GameWindow::cell_4_3_blur(){ blur( 4, 3); }
void GameWindow::cell_4_4_blur(){ blur( 4, 4); }
void GameWindow::cell_4_5_blur(){ blur( 4, 5); }
void GameWindow::cell_4_6_blur(){ blur( 4, 6); }
void GameWindow::cell_4_7_blur(){ blur( 4, 7); }
void GameWindow::cell_4_8_blur(){ blur( 4, 8); }
void GameWindow::cell_5_0_blur(){ blur( 5, 0); }
void GameWindow::cell_5_1_blur(){ blur( 5, 1); }
void GameWindow::cell_5_2_blur(){ blur( 5, 2); }
void GameWindow::cell_5_3_blur(){ blur( 5, 3); }
void GameWindow::cell_5_4_blur(){ blur( 5, 4); }
void GameWindow::cell_5_5_blur(){ blur( 5, 5); }
void GameWindow::cell_5_6_blur(){ blur( 5, 6); }
void GameWindow::cell_5_7_blur(){ blur( 5, 7); }
void GameWindow::cell_5_8_blur(){ blur( 5, 8); }
void GameWindow::cell_6_0_blur(){ blur( 6, 0); }
void GameWindow::cell_6_1_blur(){ blur( 6, 1); }
void GameWindow::cell_6_2_blur(){ blur( 6, 2); }
void GameWindow::cell_6_3_blur(){ blur( 6, 3); }
void GameWindow::cell_6_4_blur(){ blur( 6, 4); }
void GameWindow::cell_6_5_blur(){ blur( 6, 5); }
void GameWindow::cell_6_6_blur(){ blur( 6, 6); }
void GameWindow::cell_6_7_blur(){ blur( 6, 7); }
void GameWindow::cell_6_8_blur(){ blur( 6, 8); }
void GameWindow::cell_7_0_blur(){ blur( 7, 0); }
void GameWindow::cell_7_1_blur(){ blur( 7, 1); }
void GameWindow::cell_7_2_blur(){ blur( 7, 2); }
void GameWindow::cell_7_3_blur(){ blur( 7, 3); }
void GameWindow::cell_7_4_blur(){ blur( 7, 4); }
void GameWindow::cell_7_5_blur(){ blur( 7, 5); }
void GameWindow::cell_7_6_blur(){ blur( 7, 6); }
void GameWindow::cell_7_7_blur(){ blur( 7, 7); }
void GameWindow::cell_7_8_blur(){ blur( 7, 8); }
void GameWindow::cell_8_0_blur(){ blur( 8, 0); }
void GameWindow::cell_8_1_blur(){ blur( 8, 1); }
void GameWindow::cell_8_2_blur(){ blur( 8, 2); }
void GameWindow::cell_8_3_blur(){ blur( 8, 3); }
void GameWindow::cell_8_4_blur(){ blur( 8, 4); }
void GameWindow::cell_8_5_blur(){ blur( 8, 5); }
void GameWindow::cell_8_6_blur(){ blur( 8, 6); }
void GameWindow::cell_8_7_blur(){ blur( 8, 7); }
void GameWindow::cell_8_8_blur(){ blur( 8, 8); }
//end lineedit slots
