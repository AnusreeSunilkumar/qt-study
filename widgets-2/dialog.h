#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QDateTime>

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
    void doStuff();

    void on_btnEditor_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
