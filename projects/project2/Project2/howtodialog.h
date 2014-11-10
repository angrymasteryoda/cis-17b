#ifndef HOWTODIALOG_H
#define HOWTODIALOG_H

#include <QDialog>

namespace Ui {
class HowToDialog;
}

class HowToDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HowToDialog(QWidget *parent = 0);
    ~HowToDialog();

private slots:
    void on_closeButton_clicked();

private:
    Ui::HowToDialog *ui;
};

#endif // HOWTODIALOG_H
