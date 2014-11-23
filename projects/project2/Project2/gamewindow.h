#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QTime>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0, int level = 0 );
    ~GameWindow();

private slots:
    void on_backButton_clicked();

    void cell_0_0_blur();
    void cell_0_1_blur();
    void cell_0_2_blur();
    void cell_0_3_blur();
    void cell_0_4_blur();
    void cell_0_5_blur();
    void cell_0_6_blur();
    void cell_0_7_blur();
    void cell_0_8_blur();
    void cell_1_0_blur();
    void cell_1_1_blur();
    void cell_1_2_blur();
    void cell_1_3_blur();
    void cell_1_4_blur();
    void cell_1_5_blur();
    void cell_1_6_blur();
    void cell_1_7_blur();
    void cell_1_8_blur();
    void cell_2_0_blur();
    void cell_2_1_blur();
    void cell_2_2_blur();
    void cell_2_3_blur();
    void cell_2_4_blur();
    void cell_2_5_blur();
    void cell_2_6_blur();
    void cell_2_7_blur();
    void cell_2_8_blur();
    void cell_3_0_blur();
    void cell_3_1_blur();
    void cell_3_2_blur();
    void cell_3_3_blur();
    void cell_3_4_blur();
    void cell_3_5_blur();
    void cell_3_6_blur();
    void cell_3_7_blur();
    void cell_3_8_blur();
    void cell_4_0_blur();
    void cell_4_1_blur();
    void cell_4_2_blur();
    void cell_4_3_blur();
    void cell_4_4_blur();
    void cell_4_5_blur();
    void cell_4_6_blur();
    void cell_4_7_blur();
    void cell_4_8_blur();
    void cell_5_0_blur();
    void cell_5_1_blur();
    void cell_5_2_blur();
    void cell_5_3_blur();
    void cell_5_4_blur();
    void cell_5_5_blur();
    void cell_5_6_blur();
    void cell_5_7_blur();
    void cell_5_8_blur();
    void cell_6_0_blur();
    void cell_6_1_blur();
    void cell_6_2_blur();
    void cell_6_3_blur();
    void cell_6_4_blur();
    void cell_6_5_blur();
    void cell_6_6_blur();
    void cell_6_7_blur();
    void cell_6_8_blur();
    void cell_7_0_blur();
    void cell_7_1_blur();
    void cell_7_2_blur();
    void cell_7_3_blur();
    void cell_7_4_blur();
    void cell_7_5_blur();
    void cell_7_6_blur();
    void cell_7_7_blur();
    void cell_7_8_blur();
    void cell_8_0_blur();
    void cell_8_1_blur();
    void cell_8_2_blur();
    void cell_8_3_blur();
    void cell_8_4_blur();
    void cell_8_5_blur();
    void cell_8_6_blur();
    void cell_8_7_blur();
    void cell_8_8_blur();
    void showHelp();
    void newGame();

private:
    int level;
    int *gameMatrix;
    int *mask;
    int random( int max, int min = 0 );
    int *zeroFill( int );

    bool isSolvable();
    bool save();

    void gameOver();
    void disconnectCell( int row, int col );
    void blur( int row, int col );
    void setMask( int row, int col, int set );
    void initGame();
    void initCells();
    void print( bool debug = false );
    void setCell( int row, int col, int set );
    void setCell( int row, int col, QString set );
    void shuffle();
    void showNumbers();
    void setReadOnly( int row, int col, bool flag );
    void reset( int level );
    void clear( int* arr );
    void isSolved();

    QString getCell( int row, int col );

    QTime startTime;

    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
