#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QString>

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
    void on_btnCheckable_clicked();

    void on_btnAutoRepeat_clicked();

    void on_btnDefault_clicked();

    void on_btnIsChecked_clicked();

    void on_btnToggleAuto_clicked();

    void on_btnToggleDefault_clicked();

    void on_btnQuit_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
