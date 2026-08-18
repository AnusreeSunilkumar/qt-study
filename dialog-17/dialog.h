#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include "editor.h"
#include "music.h"


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

    Music music() const;
    void setMusic(const Music &newMusic);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_edit();

private:
    Ui::Dialog *ui;

    Music m_music;
    void load();
};
#endif // DIALOG_H
