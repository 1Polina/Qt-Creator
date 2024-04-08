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

void Widget::on_spinBox_valueChanged(int arg1)
{
    ui->tabl->setRowCount(arg1);
}

bool Widget::correct(QTableWidget *table, int kol){ //cheking for correctness
    int *mas = new int[ui->tabl->rowCount()];
    bool okk=true;
    bool ok1=true;
    for(int k=0; k<kol;k++){
        QTableWidgetItem *item=ui->tabl->item(k,0);
        if(item!=nullptr){
            table->item(k,0)->text().toDouble(&okk);
            if(okk){
                mas[k]=table->item(k,0)->text().toDouble();
                table->item(k,0)->setBackground(Qt::white);
            }
            else{
                ok1=false;
                table->item(k,0)->setBackground(Qt::red);
            }
        }
        else{
            item=new QTableWidgetItem;
            table->setItem(k,0,item);
            table->item(k,0)->setBackground(Qt::red);
            ok1=false;
        }
    }
    if(!ok1){
        ui->mist->setText("enter numbers");
    }
    else {
        ui->mist->clear();
    }
    return ok1;
}
void Widget::on_kn_clicked()
{
    bool s=correct(ui->tabl,ui->tabl->rowCount());
    if(s){
        double *mas = new double[ui->tabl->rowCount()];
        double p=ui->tabl->rowCount();
        for (int i = 0; i < p; i++) {
            mas[i] = ui->tabl->item(i,0)->text().toInt();
        }
        int max = -1000000000;
        for (int i = 0; i < p; i++) {
            if (mas[i] < 0) {
                if (mas[i] > max) {
                    max = mas[i];
                }
            }
        }
        ui->lineEdit->setText(QString::number(max));
    }

}
