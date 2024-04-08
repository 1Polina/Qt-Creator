#include "widget.h"
#include "ui_widget.h"
#include "cmath"

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

bool Widget::correct(){
    bool okk=true;
    bool ok1;
    int kol=ui->tabl->rowCount();
    for(int k=0; k<kol;k++){
        for(int l=0;l<2;l++){
            QTableWidgetItem *item=ui->tabl->item(k,l);
            if(item!=nullptr){
                QString m=item->text();
                m.toDouble(&ok1);
                if(ok1){
                    item->setBackground(Qt::white);
                }
                else{
                    okk=false;
                    item->setBackground(Qt::red);
                    ui->pl->clear();
                    ui->per->clear();
                }
            }
            else {
                item=new QTableWidgetItem;
                ui->tabl->setItem(k,l,item);
                item->setBackground(Qt::red);
                okk = false;
            }
        }
    }
    if (okk == false) {
        ui->mist->setText("введите числа");
    }
    else{
        ui->mist->clear();
    }
    return okk;
}
double Widget::per(double pr,double x2, double x1, double y2, double y1){
    double v1=x2-x1;
    double v2=y2-y1;
    double vs=pr+sqrt(v1*v1+v2*v2);
    return vs;
}

double Widget::pl(int op)
{
    double form;
    double pl=0;
    bool d = correct();
    if(d){
        double x[op];
        double y[op];
        for(int k=0;k<op;k++){
            for(int l=0;l<2;l++){
                double h=ui->tabl->item(k,l)->text().toDouble();
                if(l==0){
                    x[k]=h;
                }
                else{
                    y[k]=h;
                }
            }
        }
        for(int i=0;i<op-1;i++){
            form=x[i]*y[i+1]-y[i]*x[i+1];
            pl=pl+form;
        }
        form=x[op-1]*y[0]-x[0]*y[op-1];
        pl=abs((pl+form)/2);

    }
    return pl;
}
bool Widget::peres(double x1a, double y1a, double x1b, double y1b, double x2a, double y2a,double x2b, double y2b){
    bool y=true;
    double odin=(((x2b-x2a)*(y1a-y2a)-(x1a-x2a)*(y2b-y2a)))/((y2b-y2a)*(x1b-x1a)-(x2b-x2a)*(y1b-y1a));
    double dva=(((x1b-x1a)*(y1a-y2a)-(x1a-x2a)*(y1b-y1a))/((y2b-y1a)*(x1b-x1a)-(x2b-x2a)*(x1b-x1a)));
    if(odin>0 && odin<1 && dva>0 && dva<1)
    {

        y=false;
    }
    return y;
}

void Widget::on_kn_clicked()
{
    red.setColor(QPalette::Base,Qt::red);
    white.setColor(QPalette::Base,Qt::white);
    int kol=ui->tabl->rowCount();
    double x[kol];
    double y[kol];
    bool p=correct();
    bool q = true, t = true;
    if(p){
        for(int i=0; i<kol; i++){
            for(int j=0;j<2;j++){
                double w=ui->tabl->item(i,j)->text().toDouble();
                if(j==0){
                    x[i]=w;
                }
                else{
                    y[i]=w;
                }
            }
        }
        for(int i=0; i<kol-2; i++){
            for(int j=i+2;j<kol;j++){
                if(i == 0 and j == kol-1){
                    continue;
                }
                if (j != kol-1) {
                    q=peres(x[i],y[i],x[i+1], y[i+1],x[j],y[j],x[j+1],y[j+1]);
                }
                else {
                    q=peres(x[i],y[i],x[i+1], y[i+1],x[j],y[j],x[0],y[0]);
                }
                if (!q) {
                    t = false;
                }
            }
        }


        if (t) {
            double hh=pl(kol);
            ui->pl->setText(QString::number(hh));
            if(hh==0){
            ui->mist->setText("есть пересечение");
            ui->pl->clear();}
        }
        else {
            ui->mist->setText("есть пересечение");
        }
        double so=0;
        for(int s=0;s<kol-1;s++){
            so=per(so,x[s+1],x[s],y[s+1], y[s]);
        }
        so=per(so,x[0],x[kol-1],y[0],y[kol-1]);
        ui->per->setText(QString::number(so));
    }
    else {
        ui->pl->clear();
        ui->per->clear();
    }


}


void Widget::on_spinBox_valueChanged(int arg1)
{
    ui->tabl->setRowCount(arg1);
}


//                    if(!ok1){
//                        okk=false;
//                        item->setBackground(Qt::red);
//                        ui->pl->clear();
//                        ui->per->clear();
//                    }
