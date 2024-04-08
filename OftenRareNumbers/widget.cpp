#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spinBox_valueChanged(int a)
{
    ui->tableWidget->setRowCount(a);
}

bool Widget::prov(int kl, int *mas)
{
    bool ok;
    bool ok2 = true;
    for (int i = 0; i < kl; i++) {
        if (ui->tableWidget->item(i,0) != nullptr) {
            ui->tableWidget->item(i,0)->setBackground(Qt::white);
            int a = ui->tableWidget->item(i,0)->text().toInt(&ok);
            if (ok) {
                ui->tableWidget->item(i,0)->setBackground(Qt::white);
                mas[i] = a;
            }
            else {
                ui->tableWidget->item(i,0)->setBackground(Qt::red);
                ok2 = false;
            }
        }
        else {
            QTableWidgetItem *item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,item);
            ui->tableWidget->item(i,0)->setBackground(Qt::red);
            ok2 = false;
        }
    }
    return ok2;
}
void Widget::on_pushButton_clicked()
{
    int *sverchmassiv = new int[ui->tableWidget->rowCount()];
    bool a = prov(ui->tableWidget->rowCount(), sverchmassiv);
    QString s;
    if (a) {
        int min = -1000000;
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            int ch = 0;
            for (int j = 0; j < ui->tableWidget->rowCount(); j++) {
                if (sverchmassiv[i] == sverchmassiv[j]) {
                    ch++;
                }
            }
            if (ch > min) {
                min = ch;
            }
        }
        for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
            int ch = 0;
            for (int j = 0; j < ui->tableWidget->rowCount(); j++) {
                if (sverchmassiv[i] == sverchmassiv[j]) {
                    ch++;
                }
            }
            bool t;
            if (ch == min) {
                t = true;
                for (int r = i; r >= 0; r--) {
                    if (sverchmassiv[i] == sverchmassiv[r] and i != r) {
                        t = false;
                    }
                }
                if (t) {
                    s = s + QString::number(sverchmassiv[i]) + "; ";
                }
            }
        }
            ui->textEdit->setText(s);
        }
        delete [] sverchmassiv;
    }
