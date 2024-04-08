#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>

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
    void on_kn_clicked();
    bool correct(QTableWidget *table, int kol);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
