#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
    load();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::init()
{
    ui->comboBox->setEnabled(true);
    ui->buttonBox->addButton("Clear",QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton("Remove",QDialogButtonBox::ButtonRole::ActionRole);
}


void Dialog::load()
{
    QSettings setting("MyCompany","MyApp");

    //ui->comboBox->setCurrentText(settings.value("text","").toString());

    int combosize = setting.beginReadArray("combo");
    for (int i = 0;i < combosize; i++)
    {
        setting.setArrayIndex(i);
        ui->comboBox->addItem(setting.value("item","").toString());
    }
    setting.endArray();

    int listsize = setting.beginReadArray("list");
    for (int i = 0;i < listsize; i++)
    {
        setting.setArrayIndex(i);
        ui->listWidget->addItem(setting.value("item","").toString());
    }
    setting.endArray();
    ui->comboBox->setCurrentText(setting.value("text","").toString());
}

void Dialog::save()
{
    QSettings setting("MyCompany","MyApp");
    setting.clear();

    setting.setValue("text",ui->comboBox->currentText());

    setting.beginWriteArray("combo");
    for(int i = 0; i < ui->comboBox->count(); i++)
    {
        setting.setArrayIndex(i);
        setting.setValue("item", ui->comboBox->itemText(i));
    }
    setting.endArray();

    setting.beginWriteArray("list");
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        setting.setArrayIndex(i);
        setting.setValue("item", ui->listWidget->item(i)->text());
    }
    setting.endArray();
}

void Dialog::on_btnAdd_clicked()
{
    if(ui->comboBox->findText(ui->comboBox->currentText()) < 0)
    {
        ui->comboBox->addItem(ui->comboBox->currentText());
    }
    ui->listWidget->addItem(ui->comboBox->currentText());

}


void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    qDebug() << button->text();
    if(button->text().contains("OK"))
    {
        save();
        accept();
        return;
    }

    if(button->text().contains("Cancel"))
    {
        reject();
        return;
    }

    if(button->text().contains("Clear"))
    {
        ui->comboBox->clear();
        ui->listWidget->clear();
        return;
    }

    if(button->text().contains("Remove"))
    {
        QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
        foreach (QListWidgetItem* item, items)
        {
            ui->listWidget->removeItemWidget(item);
            delete item;
        }
    }
}


