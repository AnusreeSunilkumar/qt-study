#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDateTime>
#include <QMessageBox>

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
    void on_timeEdit_userTimeChanged(const QTime &time);

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
