#include "widget.h"
#include "ui_widget.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <time.h>
#include <QTime>
#include <QElapsedTimer>



void Widget::ud (int &old, int newkl)
{
    if(old!=newkl){
        if(old>0){
            delete[] mas;
            mas=nullptr;
        }
        if(newkl>0){
            mas=new double[newkl];
        }
        old=newkl;
    }
}

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

void Widget::ochist()
{
    ui->sr1->clear();
    ui->max1->clear();
    ui->min1->clear();
    ui->po->clear();
    ui->ch->clear();
    ui->chsl->clear();
    ui->tip->clear();
}
void Widget::on_spinBox_valueChanged(int arg1)
{
    ui->tabl->setRowCount(arg1);

}
bool Widget::correct(QTableWidget *table, int kol){//проверка на корректность
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
        ui->mist->setText("введите числа");}
    else {
        ui->mist->clear();
    }
    return ok1;
}
void Widget::vozr(QTableWidget *table, int kol)//заполняет таблицу
{
    for(int i=0;i<kol;i++){
        double a=mas[i];
        table->item(i,0)->setText(QString::number(a));
    }
}
bool Widget::otsor(int kol)//проверяет отсортирован ли массив по возрастанию
{
    bool ots= true;
    for(int j=0;j<kol-1;j++){
        if(mas[j]>mas[j+1]){
            ots=false;
        }
    }
    return ots;
}

bool Widget::otsor2(int kl)//проверяет отсортирован ли массив по убыванию
{
    bool ots = true;
    for(int j=0;j<kl-1;j++){
        if(mas[j]<mas[j+1]){
            ots=false;
        }
    }
    return ots;
}

void Widget::gn(int kol)//сортирует гномья сортировка
{
    QElapsedTimer t;
    t.start();
    int n=0;
    double z;
    while(n<kol){
        if(n==0 or mas[n-1]<=mas[n]){
            n=n+1;
        }
        else{
            z=mas[n];
            mas[n]=mas[n-1];
            mas[n-1]=z;
            n=n-1;
        }
    }
    double a=t.nsecsElapsed();
    ui->vrem->setText(QString::number(a));
}
void Widget::puz(int kol)//сортировка пузырьком
{
    QElapsedTimer t;
    t.start();
    double z;
    for(int i=0; i<kol; i++){
        for(int j=0;j<kol-1;j++){
            if(mas[j]>mas[j+1]){
                z=mas[j];
                mas[j]=mas[j+1];
                mas[j+1]=z;
            }
        }
    }
    double a=t.nsecsElapsed();
    ui->vrem->setText(QString::number(a));}

void Widget::rash(int kol)//сортировка расчёсткой
{
    QElapsedTimer t;
    t.start();
    int o=kol;
    //bool h=true;
    while(o>1){
        if(o>1){
            o=o/1.247;
        }
        int i=0;
        while((i+o)<kol){
            if(mas[i]>mas[i+o]){
                double z=mas[i];
                mas[i]=mas[i+o];
                mas[i+o]=z;
            }
            i=i+1;
        }
    }
    double a=t.nsecsElapsed();
    ui->vrem->setText(QString::number(a));
}

//void Widget::vpididina(int r, int l) {
//    QElapsedTimer t;
//    t.start();
//    bistr(mas,ui->tabl->rowCount());
//    double s=t.nsecsElapsed();
//    ui->vrem->setText(QString::number(s));
//}

void Widget::bistr(double *mas, int kl)//быстрая сортировка
{
    int l=0;
    int r=kl-1;
    double sr=mas[kl/2];
    do{
        while(mas[l]<sr){
            l++;
        }
        while (mas[r] > sr) {
            r--;
        }
        if(l<=r){
            double vr=mas[l];
            mas[l]=mas[r];
            mas[r]=vr;
            l++;
            r--;
        }
    } while(l<=r);
    if(r>0){
        bistr(mas,r+1);
    }
    if(l<kl){
        bistr(&mas[l], kl-l);
    }

//    double z;
//    int m2=m;
//    int n2=n;
//    double a=mas[m];
//    while(n<m){
//        while(mas[n]<=a and n<m){
//            n++;
//        }
//        while(mas[m]>a and n<m){
//            m--;
//        }
//        if(n<m){
//            z=mas[n];
//            mas[n]=mas[m];
//            mas[m]=z;
//        }
//    }
//    if(m-n2>1){
//        bistr(m-1,n2);
//    }
//    if(m2-m+1>1){
//        bistr(m2,m);
//    }
    //double s=t.nsecsElapsed();
    //ui->vrem->setText(QString::number(s));
}
bool Widget::manky(int kol)//обезьянья сортировка
{
    QElapsedTimer t;
    t.start();
    bool ots=false;
    bool h = true;
    while(!ots){
        int i=0;
        while(i<kol){
            int a=QRandomGenerator::global()->bounded(0,kol);
            double z=mas[i];
            mas[i]=mas[a];
            mas[a]=z;
            i++;
            double two = t.nsecsElapsed();
            if(two>12000000000){
                QMessageBox::about(this,"большое число","сортировка остановлена");
                h = false;
                break;
            }

            if (otsor(kol)) {
                ots = true;
                break;
            }
        }
        if (!h) {
            break;
        }
    }
    if (h) {
        double a=t.nsecsElapsed();
        ui->vrem->setText(QString::number(a));
    }
    return h;
}
void Widget::on_kn_clicked()
{
    ochist();
    red.setColor(QPalette::Base,Qt::red);
    ud(kolvo, ui->tabl->rowCount());
    bool okey=correct(ui->tabl,ui->tabl->rowCount());
    bool m=ui->manky->isChecked();
    bool r=ui->rach->isChecked();
    bool b=ui->bistr->isChecked();
    bool g=ui->gn->isChecked();
    bool p=ui->puz->isChecked();
//    if(!g and !p and !b and !m and !r){
//        ui->vrem->setText("не выбрана сортировка");
//        ui->vrem->setPalette(red);
//    }
    if(okey){
        if(g){
            if (ui->tabl->rowCount() > 100000) {
                QMessageBox::StandardButton kn = QMessageBox::question(this, "", "Это может занять слишком много времени. Выберите другой метод сортировки");
                if (kn == QMessageBox::No) {
                    gn(ui->tabl->rowCount());
                    vozr(ui->tabl,ui->tabl->rowCount());
                }
            }
            else {
                gn(ui->tabl->rowCount());
                vozr(ui->tabl,ui->tabl->rowCount());
            }

            gn(ui->tabl->rowCount());
            vozr(ui->tabl,ui->tabl->rowCount());
        }
        else if(p){
            if (ui->tabl->rowCount() > 80000) {
                QMessageBox::StandardButton kn = QMessageBox::question(this, "", "Это может занять слишком много времени. Выберите другой метод сортировки");
                if (kn == QMessageBox::No) {
                    puz(ui->tabl->rowCount());
                    vozr(ui->tabl,ui->tabl->rowCount());
                }
            }
            else {
                puz(ui->tabl->rowCount());
                vozr(ui->tabl,ui->tabl->rowCount());
            }
        }
        else if(b){
            QElapsedTimer t;
            t.start();
            bistr(mas,ui->tabl->rowCount());
            double s=t.nsecsElapsed();
            ui->vrem->setText(QString::number(s));
            vozr(ui->tabl,ui->tabl->rowCount());
        }
        else if(m){
            bool f = manky(ui->tabl->rowCount());
            if (f) {
                vozr(ui->tabl,ui->tabl->rowCount());
            }
        }
        else if(r){
            rash(ui->tabl->rowCount());
            vozr(ui->tabl,ui->tabl->rowCount());
        }
    }
}

void Widget::on_sr_clicked()//нахождение среднего значения
{
    ui->po->clear();
    ui->ch->clear();
    ui->chsl->clear();
    ui->tip->clear();
    int kol=ui->tabl->rowCount();
    ud(kolvo,kol);
    bool okey=correct(ui->tabl, ui->tabl->rowCount());
    double sum=0;
    double sr;
    if(okey){
        for( int i=0;i<kol;i++){
            sum=sum+mas[i];
        }
        sr=sum/kol;
        ui->sr1->setText(QString::number(sr));
    }
}

void Widget::on_max_clicked()//поиск максимального значения
{
    ui->po->clear();
    ui->ch->clear();
    ui->chsl->clear();
    ui->tip->clear();
    int kol=ui->tabl->rowCount();
    ud(kolvo,kol);
    bool okey=correct(ui->tabl, ui->tabl->rowCount());
    if(okey){
        double max=mas[0];
        for(int i=1; i<ui->tabl->rowCount();i++){
            if(mas[i]>max){
                max=mas[i];
            }
        }
        ui->max1->setText(QString::number(max));
    }
}

void Widget::on_min_clicked()//поиск минимального значения
{
    ui->po->clear();
    ui->ch->clear();
    ui->chsl->clear();
    ui->tip->clear();
    int kol=ui->tabl->rowCount();
    ud(kolvo,kol);
    bool okey=correct(ui->tabl, ui->tabl->rowCount());
    if(okey){
        double min=mas[0];
        for(int i=1; i<ui->tabl->rowCount();i++){
            if(mas[i]<min){
                min=mas[i];
            }
        }
        ui->min1->setText(QString::number(min));
    }
}

void Widget::on_random_clicked()//рандом
{
    ui->max1->clear();
    ui->min1->clear();
    ui->sr1->clear();
    for(int i=0;i<ui->tabl->rowCount();i++){
        int a=QRandomGenerator::global()->bounded(0,201);
        QTableWidgetItem *item=new QTableWidgetItem;
        item->setText(QString::number(a));
        ui->tabl->setItem(i,0,item);
    }

}

void Widget::on_kn2_clicked()//поиск
{
    ui->sr1->clear();
    ui->max1->clear();
    ui->min1->clear();
    QPalette cvet;
    cvet.setColor(QPalette::Background, Qt::blue);
    int kl=ui->tabl->rowCount();
    ud(kolvo, kl);
    bool ok;
    QString s=ui->ch->text();
    double po=s.toDouble(&ok);
    if(!ok){
        ui->mist->setPalette(red);
        ui->mist->setText("введите числа");
    }
    bool okey=correct(ui->tabl, kl);
    int l=0;
    int r=kl-1;
    int sr=0;
    if(okey){
        bool sor=otsor(kl);
        bool sor2=otsor2(kl);
        int ch=0;
        if(sor or sor2){
            int od=0, dv=0;
            QElapsedTimer t;
            t.start();
            while(l<=r){
                sr=(r+l)/2;
                if(mas[sr]>po){
                    if (sor) {
                        r=sr-1;
                    }
                    else {
                        l=sr+1;
                    }
                }
                else if(mas[sr]<po){
                    if (sor) {
                        l=sr+1;
                    }
                    else {
                        r=sr-1;
                    }
                }
                else{
                    ch++;//количество найденных значений увеличивается на 1
                    break;
                }
            }
            int sr2=sr;
            int vr1,vr2;
            while(true){
                vr1=(sr+l)/2;
                vr2=(sr2+r)/2;
                if(abs(mas[vr1] - po) < 0.000001){
                    sr=vr1;
                }
                else{
                    l=vr1;
                }
                if(abs(mas[vr2] - po) < 0.000001){
                    sr2=vr2;
                }
                else{
                    r=vr2;
                }
                if(sr-l<=1 and r-sr2<=1){
                    if(abs(mas[l] - po) < 0.000001){
                        od=l;
                    }
                    else if(abs(mas[sr] - po) < 0.000001){
                        od=sr;
                    }
                    else{
                        od=vr1;
                    }
                    if(abs(mas[r] - po) < 0.000001){
                        dv=r;
                    }
                    else if(abs(mas[sr2] - po) < 0.000001){
                        dv=sr2;
                    }
                    else{
                        dv=vr2;
                    }
                    break;
                }
            }
            if (ch != 0) {
                ch=dv-od+1;
            }
//            QString s=ui->chsl->text();
//            if(s==0){
//                double po1=ch+1;
//                double po2=ch-1;
//                ui->po->setText(QString::number(po1,po2));
//            }
            double z=t.nsecsElapsed();
            ui->vrem->setText(QString::number(z));
            QString f;
            if(ch!=0){
                for(int d=od;d<dv+1;d++){
                    f=f+(QString::number(d+1)+"; ");
                    ui->tabl->item(d,0)->setBackground(Qt::gray);
                }
                ui->po->setText(f);
            }
            ui->tip->setText("бинарный");
        }
        else {
            QString f;
            for(int i=0; i<kl;i++){
                if(abs(mas[i] - po) < 0.0000001){
                    ch++;
                    f = f + QString::number(i+1) + "; ";
                    ui->tabl->item(i,0)->setBackground(Qt::gray);
                }
            }
            ui->po->setText(f);
            ui->tip->setText("линейный");
        }
        ui->chsl->setText(QString::number(ch));


    }
}

void Widget::on_dub_clicked()//удаление дубликатов
{
    ochist();
    QElapsedTimer t;
    int kol=ui->tabl->rowCount();
    ud(kolvo,kol);
    bool okey=correct(ui->tabl,kol);
    bool sor=otsor(kol);
    int ch=0;
    int er=0;
    if(okey){
        if(sor){
            t.start();
            for(int i=0;i<kol-1;i++){
                if(abs(mas[i] - mas[i+1]) > 0.0000001){
                    mas[ch]=mas[i];
                    ch++;

                    if(mas[ch]<mas[ch+1]){
                        mas[ch]=mas[er];
                        er++;
                }
             }
          }
//            mas[ch]=mas[kol-1];
            double y=t.nsecsElapsed();
            ui->vrem->setText(QString::number(y));
            ui->spinBox->setValue(ch+1);
            vozr(ui->tabl, ch+1);
        }

        else{
            ui->mist->setText("отсортируйте массив");
        }
    }
}
