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

void Widget::kr(QLineEdit *edit)
{
    QPalette error, norm;
    error.setColor(QPalette::Base, Qt::red);
    bool ok = true;
    QString s  = edit->text();
    s.toDouble(&ok);
    edit->setPalette(ok ? norm : error);
    if (!ok) {
        ui->lineEdit_9->setPalette(red);
        ui->lineEdit_9->setText("Введите числа");
    }

}

double Widget::per(double o, double t, double f, double fo){
    double odin=f-o;
    double dva=fo-t;
    double tri=sqrt(odin*odin+dva*dva);
    return tri;
}
void Widget::clearness(){
    ui->Ax->clear();
    ui->Ay->clear();
    ui->Bx->clear();
    ui->By->clear();
    ui->Cx->clear();
    ui->Cy->clear();
    ui->pr->clear();
    ui->pl->clear();
}

void Widget::on_kn_clicked()
{   ui->lineEdit_9->clear();
    kr(ui->Ax);
    kr(ui->Ay);
    kr(ui->Bx);
    kr(ui->By);
    kr(ui->Cx);
    kr(ui->Cy);
    red.setColor(QPalette::Base,Qt::red);
    white.setColor(QPalette::Base,Qt::white);


    QString q=ui->Ax->text();
    QString w=ui->Ay->text();
    QString e=ui->Bx->text();
    QString r=ui->By->text();
    QString t=ui->Cx->text();
    QString y=ui->Cy->text();
    bool ok1, ok2, ok3, ok4, ok5, ok6;
    double a=q.toDouble(&ok1);
    double s=w.toDouble(&ok2);
    double d=e.toDouble(&ok3);
    double f=r.toDouble(&ok4);
    double g=t.toDouble(&ok5);
    double h=y.toDouble(&ok6);

    if(!ok1 or !ok2 or !ok3 or !ok4 or !ok5 or !ok6){
        ui->pl->clear();
        ui->pr->clear();
        return;
    }

    double vect1=per(a,s,d,f);
    double vect2=per(d,f,g,h);
    double vect3=per(a,s,g,h);

//    if((((a+s)+(d+f))<(g+h)) or (((d+f)+(g+h))<a+s) or ((g+h)+(a+s)<d+f)){
//        ui->pl->clear();
//        ui->pr->clear();
//        ui->lineEdit_9->setText("несуществует");
//        ui->lineEdit_9->setPalette(red);
//    }

    double pr=vect1+vect2+vect3;
    ui->pr->setText(QString::number(pr));

    double ppr=pr/2;
    double pl;
       if(ppr*(ppr-vect1)*(ppr-vect2)*(ppr-vect3)<0){
        pl=0;
       }
       else if (sqrt(ppr*(ppr-vect1)*(ppr-vect2)*(ppr-vect3))<0.01) {
           pl = 0;
       }
       else{
        pl=sqrt(ppr*(ppr-vect1)*(ppr-vect2)*(ppr-vect3));
        ui->pl->setText(QString::number(pl));}

       if(ui->Ax->text()=="" or ui->Ay->text()=="" or ui->Bx->text()=="" or ui->By->text()=="" or ui->Cx->text()=="" or ui->Cy->text()=="" ){
           clearness();
           ui->lineEdit_9->setText("заполните все ячейки");
           ui->lineEdit_9->setPalette(red);}
       else{
           ui->lineEdit_9->setPalette(white);}
       if (ok1 and ok2 and ok3 and ok4 and ok5 and ok6) {
           if((a==d and s==f) or (a==g and s==h) or (d==g and f==h)){
               ui->lineEdit_9->setText("числа совпадают");
               ui->lineEdit_9->setPalette(red);
           }
       }

//       if(a>10000 or s>10000 or d>10000 or f>10000 or g>10000 or h>10000){
//           ui->pl->setText("нельзя брать большие числа");
//           ui->pr->setText("нельзя брать большие числа");}

       if(qIsInf(pr)){
           ui->pl->setText("нельзя брать большие числа");
           ui->pr->setText("нельзя брать большие числа");
       }
       if(qIsInf(pl)){
           ui->pl->setText("нельзя брать большие числа");
           ui->pr->setText("нельзя брать большие числа");}

}
