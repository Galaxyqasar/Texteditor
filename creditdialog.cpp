#include "creditdialog.h"
#include "ui_creditdialog.h"

CreditDialog::CreditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditDialog)
{
    ui->setupUi(this);
}

CreditDialog::~CreditDialog()
{
    delete ui;
}

void CreditDialog::on_pushButton_clicked()
{
    done(1);
}