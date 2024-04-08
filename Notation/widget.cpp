#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->hide();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked() //Обработка нажатия
{
    QPalette error, norm;
    error.setColor(QPalette::Base, Qt::red);
    ui->label->hide();
    ui->vvod->setPalette(norm);
    QString s = ui->vvod->text();
    bool ok;
    int d = s.toInt(&ok, 2);
    if (ok) {
        ui->rez->setText(QString::number(d, 16));
    }
    else {
        ui->label->show();
        ui->vvod->setPalette(error);
        ui->rez->clear();
    }
}
