#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString s = ui->lineEdit->text();
    if (s == "") {
        ui->lineEdit_2->setText("Пустая строка");
    }
    else if (s.toInt()) {
        ui->lineEdit_2->setText("Целое число");
    }
    else if (s.toDouble()) {
        ui->lineEdit_2->setText("Дробное число");
    }
    else {
        ui->lineEdit_2->setText("Строка");
    }
}
