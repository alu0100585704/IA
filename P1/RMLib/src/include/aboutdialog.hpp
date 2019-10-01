#pragma once
#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::AboutDialog *ui;
};

