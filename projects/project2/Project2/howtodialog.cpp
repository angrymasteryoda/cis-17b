#include "howtodialog.h"
#include "ui_howtodialog.h"

HowToDialog::HowToDialog(QWidget *parent) :  QDialog(parent), ui(new Ui::HowToDialog) {
    ui->setupUi(this);
}

HowToDialog::~HowToDialog() {
    delete ui;
}

void HowToDialog::on_closeButton_clicked() {
    this->close();
}
