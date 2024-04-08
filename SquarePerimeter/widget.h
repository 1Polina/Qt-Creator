#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>

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
    void clearness();
    void kr (QLineEdit *edit);

private:
    QPalette white, red, green, yellow;
    Ui::Widget *ui;
    double per(double o, double t, double f, double fo);
};

#endif // WIDGET_H
