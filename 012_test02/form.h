#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    int getNum();
    void setNum(int);


private:
    Ui::Form *ui;
};

#endif // FORM_H
