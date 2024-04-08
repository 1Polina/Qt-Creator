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
        ui->lineEdit_2->setText("empty line");
    }
    else if (s.toInt()) {
        ui->lineEdit_2->setText("int");
    }
    else if (s.toDouble()) {
        ui->lineEdit_2->setText("double");
    }
    else {
        ui->lineEdit_2->setText("string");
    }
}
