#include <aboutdialog.hpp>
#include <ui_aboutdialog.h>
#include <QAbstractButton>

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}


void AboutDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    close();
}
