#ifndef DIALOG_H
#define DIALOG_H

#include <QDockWidget>

namespace Ui {
class Dialog;
}

class Dialog : public QDockWidget {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_gameOverButton_clicked();

    void on_diffButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
