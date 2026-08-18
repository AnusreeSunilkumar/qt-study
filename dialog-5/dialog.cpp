#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_commandLinkButton_clicked()
{
    selectOption(sender());
}


void Dialog::on_commandLinkButton_2_clicked()
{
    selectOption(sender());
}


void Dialog::on_commandLinkButton_3_clicked()
{
    selectOption(sender());
}


void Dialog::on_buttonBox_accepted()
{
    QMessageBox::information(this, "Ok","Closing");
}


void Dialog::on_buttonBox_rejected()
{
    QMessageBox::critical(this, "Cancel","Closing");
}


void Dialog::on_buttonBox_helpRequested()
{
    QMessageBox::question(this, "HELP","Help me");
}

void Dialog::selectOption(QObject *sender)
{
    QCommandLinkButton* btn = qobject_cast<QCommandLinkButton*> (sender);
    if(!btn) return;

    ui->lblSelected->setText(btn->text());
    QMessageBox::information(this, btn->text(),btn->description());

}

