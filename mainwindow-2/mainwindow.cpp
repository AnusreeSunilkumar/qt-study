#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::openFile);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveFile);
    connect(ui->actionSave_As, &QAction::triggered, this, &MainWindow::saveFileAs);
    connect(ui->actionEXIT, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionCopy, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::copy);
    connect(ui->actionCut, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::cut);
    connect(ui->actionPaste, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::paste);
    connect(ui->actionSelect_All, &QAction::triggered, ui->plainTextEdit, &QPlainTextEdit::selectAll);
    connect(ui->actionSelect_None, &QAction::triggered, this, &MainWindow::selectNone);


    this->setCentralWidget(ui->splitter);
    setUpStatusBar();

    newFile();
    m_saved = true;

    for(int i=0; i<100; i++)
    {
        QString title = "Item number " + QString::number(i);
        ui->listWidget->addItem(title);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    ui->plainTextEdit->clear();
    m_file.clear();
    m_saved = false;
    // ui->statusbar->showMessage("New file");
    updateStatus("New File");
}

void MainWindow::openFile()
{
    QString temp = QFileDialog::getOpenFileName(this, "Open File", QString(), "Text Files (*.txt);; All Files (*.*)");

    if(temp.isEmpty()) return;

    m_file = temp;
    QFile file(m_file);
    if(!file.open(QIODevice::ReadOnly))
    {
        newFile();
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->plainTextEdit->setPlainText(stream.readAll());
    file.close();

    m_saved = true;
    // ui->statusbar->showMessage(m_file);
    updateStatus(m_file);

}

void MainWindow::saveFile()
{
    if(m_file.isEmpty())
    {
        saveFileAs();
        return;
    }

    QFile file(m_file);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->plainTextEdit->toPlainText();
    file.close();

    m_saved=true;
    // ui->statusbar->showMessage(m_file);
    updateStatus(m_file);
}

void MainWindow::saveFileAs()
{
    QString temp = QFileDialog::getSaveFileName(this, "Save File", QString(), "Text Files (*.txt);; All Files (*.*)");
    if(temp.isEmpty()) return;
    m_file = temp;
    saveFile();

}

void MainWindow::selectNone()
{
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    int pos = cursor.position();
    cursor.clearSelection();
    cursor.setPosition(pos, QTextCursor::MoveMode::KeepAnchor);
    ui->plainTextEdit->setTextCursor(cursor);
}

void MainWindow::on_actionToolbar_top_triggered()
{
    addToolBar(Qt::ToolBarArea::TopToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_bottom_triggered()
{
    addToolBar(Qt::ToolBarArea::BottomToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_left_triggered()
{
    addToolBar(Qt::ToolBarArea::LeftToolBarArea, ui->toolBar);
}


void MainWindow::on_actionToolbar_right_triggered()
{
    addToolBar(Qt::ToolBarArea::RightToolBarArea, ui->toolBar);
}



void MainWindow::on_actionToolbar_floatable_toggled(bool arg1)
{
    ui->toolBar->setFloatable(arg1);
}


void MainWindow::on_actionToolbar_movable_toggled(bool arg1)
{
    ui->toolBar->setMovable(arg1);
}

void MainWindow::setUpStatusBar()
{
    QLabel *lblIcon = new QLabel(this);
    lblIcon->setObjectName("lblIcon");
    lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
    ui->statusbar->addWidget(lblIcon);

    QLabel *lblStatus = new QLabel(this);
    lblStatus->setObjectName("lblStatus");
    lblStatus->setText("Not Saved");
    ui->statusbar->addWidget(lblStatus);

    QLabel *lblFile = new QLabel(this);
    lblFile->setObjectName("lblFile");
    lblFile->setText("New");
    ui->statusbar->addWidget(lblFile);
}

void MainWindow::updateStatus(QString message)
{
    QLabel *lblIcon =
        ui->statusbar->findChild<QLabel*>("lblIcon");

    QLabel *lblStatus =
        ui->statusbar->findChild<QLabel*>("lblStatus");

    QLabel *lblFile =
        ui->statusbar->findChild<QLabel*>("lblFile");

    if(!lblIcon || !lblStatus || !lblFile)
    {
        qDebug() << "Status bar labels not found";
        return;
    }

    if(m_saved)
    {
        lblIcon->setPixmap(QPixmap(":/files/images/save.png"));
        lblStatus->setText("Saved");
    }
    else
    {
        lblIcon->setPixmap(QPixmap(":/files/images/new.png"));
        lblStatus->setText("Not Saved");
    }

    lblFile->setText(message);
}


void MainWindow::on_plainTextEdit_textChanged()
{
    m_saved = false;
    if(m_file.isEmpty())
    {
        updateStatus("New file");
    }
    else
    {
        updateStatus(m_file);
    }
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    ui->plainTextEdit->appendPlainText(item->text());
}


void MainWindow::on_actionAnimals_triggered()
{
    QStringList options;
    options << "Cats" << "Dog" << "Bird" << "Fish";

    QScopedPointer<Dialog> dlg(new Dialog());
    dlg.data()->setList(options);
    dlg.data()->exec();

    ui->plainTextEdit->insertPlainText(dlg.data()->selected());
}


void MainWindow::on_actionShapes_triggered()
{
    QStringList options;
    options << "Circle" << "Triangle" << "Square" << "Freehand";

    QScopedPointer<Dialog> dlg(new Dialog());
    dlg.data()->setList(options);
    dlg.data()->exec();

    ui->plainTextEdit->insertPlainText(dlg.data()->selected());
}


void MainWindow::on_actionFood_triggered()
{
    QStringList options;
    options << "Pizza" << "Burgers" << "Steak" << "Shawarma";

    QScopedPointer<Dialog> dlg(new Dialog());
    dlg.data()->setList(options);
    dlg.data()->exec();

    ui->plainTextEdit->insertPlainText(dlg.data()->selected());
}

