#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QWidget>
#include <QMessageBox>
#include <QRandomGenerator>
#include <time.h>
#include <QTime>
#include <QElapsedTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    int kolvo=0;
    double* mas=nullptr;

private slots:
    void ochist();
    void puz(int kol);
    void on_spinBox_valueChanged(int arg1);
    void rash(int kol);
    void gn(int kol);
    void bistr(double *mas, int kl);
    bool manky(int kol);
    void on_kn_clicked();
    bool correct(QTableWidget *table, int kol);
    bool otsor(int kol);

    bool otsor2(int kl);

    void vozr(QTableWidget *table, int kol);

    void on_sr_clicked();

    void on_max_clicked();

    void on_min_clicked();

    void on_random_clicked();
    void on_kn2_clicked();
    void vpididina(int r, int l);

    void ud (int &old, int newkl);

void bstr(double *mas, int kl);

    void on_dub_clicked();

private:
    QPalette red;
    Ui::Widget *ui;
};

#endif // WIDGET_H
