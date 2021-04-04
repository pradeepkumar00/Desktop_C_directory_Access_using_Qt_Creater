#ifndef FORM_H
#define FORM_H

#include <QDialog>

namespace Ui {
class form;
}

class form : public QDialog
{
    Q_OBJECT

public:
    explicit form(QWidget *parent = nullptr);
    ~form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::form *ui;
};

#endif // FORM_H
