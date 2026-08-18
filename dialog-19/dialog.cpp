#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    accept();
}

void Dialog::hrClicked()
{
    QMessageBox::information(this, "HR", "Info sent to HR");
}

void Dialog::legalClicked()
{
    QMessageBox::information(this, "Legal", "Info sent to Legal");
}

void Dialog::nextClicked()
{
    int tab = ui->tabWidget->currentIndex();
    int max = ui->tabWidget->count() - 1;
    tab++;
    if(tab>max) tab=max;
    ui->tabWidget->setCurrentIndex(tab);
}

void Dialog::backClicked()
{
    int tab = ui->tabWidget->currentIndex();
    int min = 0;
    tab--;
    if(tab<min) tab=min;
    ui->tabWidget->setCurrentIndex(tab);
}

void Dialog::init()
{
    QPushButton *btnBack = new QPushButton("Back", this);
    QPushButton *btnNext = new QPushButton("Next", this);
    connect(btnNext, &QPushButton::clicked, this, &Dialog::nextClicked);
    connect(btnBack, &QPushButton::clicked, this, &Dialog::backClicked);

    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);


    ui->tabWidget->setTabText(0, "Profile");
    ui->tabWidget->setTabText(1, "Notes");

    QWidget *widget = new QWidget(this);
    ui->tabWidget->addTab(widget, "Send");
    QPushButton *btnHr = new QPushButton("Send to Human Resources", this);
    QPushButton *btnLegal = new QPushButton("Send to Legal", this);

    connect(btnHr, &QPushButton::clicked, this, &Dialog::hrClicked);
    connect(btnLegal, &QPushButton::clicked, this, &Dialog::legalClicked);

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(btnHr);
    layout->addWidget(btnLegal);

    widget->setLayout(layout);

}

