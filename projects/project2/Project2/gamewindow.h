#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private slots:
    void on_backButton_clicked();

private:
    int *gameMatrix;

    void initGame();
    void print();

    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
