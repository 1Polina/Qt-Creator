#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_spinBox_valueChanged(int arg1);

    bool prov(int kl, int *mas);

    void on_pushButton_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
