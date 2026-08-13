#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <Qfile>
#include <QTextStream>
#include <QMessageBox>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog() override;

private slots:
    void on_btnNew_clicked();

    void on_btnOpen_clicked();

    void on_btnSave_clicked();

    void on_plainTextEdit_textChanged();

    void acceptMe();

private:
    Ui::Dialog *ui;

    bool m_saved;
    void load();
    void save();

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};
#endif // DIALOG_H
