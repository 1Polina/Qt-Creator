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
    void on_kn_clicked();
    bool correct();
    double pl(int op);
    double per(double pr,double x2, double x1, double y2, double y1);
    void on_spinBox_valueChanged(int arg1);
    bool peres(double x1a, double y1a, double x1b, double y1b, double x2a, double y2a,double x2b, double y2b);
private:
    QPalette red, white;
    Ui::Widget *ui;
};

#endif // WIDGET_H
