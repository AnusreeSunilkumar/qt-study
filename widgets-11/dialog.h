#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMEssageBox>
#include <QFile>
#include <QString>
#include <QDataStream>

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
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Dialog *ui;

    void load();
    void save();
};
#endif // DIALOG_H
