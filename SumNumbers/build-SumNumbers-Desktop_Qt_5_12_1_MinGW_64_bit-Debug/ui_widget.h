/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *lineEdit;
    QLineEdit *mist;
    QPushButton *kn;
    QSpinBox *spinBox;
    QTableWidget *tabl;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(806, 542);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 220, 131, 25));
        lineEdit->setReadOnly(true);
        mist = new QLineEdit(Widget);
        mist->setObjectName(QString::fromUtf8("mist"));
        mist->setGeometry(QRect(290, 40, 113, 25));
        mist->setReadOnly(true);
        kn = new QPushButton(Widget);
        kn->setObjectName(QString::fromUtf8("kn"));
        kn->setGeometry(QRect(20, 220, 112, 34));
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 100, 111, 81));
        tabl = new QTableWidget(Widget);
        if (tabl->columnCount() < 1)
            tabl->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tabl->rowCount() < 1)
            tabl->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabl->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tabl->setObjectName(QString::fromUtf8("tabl"));
        tabl->setGeometry(QRect(20, 20, 256, 192));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 20, 55, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 80, 121, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        kn->setText(QApplication::translate("Widget", "Result", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabl->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "1", nullptr));
        label->setText(QApplication::translate("Widget", "Error", nullptr));
        label_2->setText(QApplication::translate("Widget", "Amount of numbers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
