/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *Spacer1;
    QPushButton *btnMax;
    QPushButton *btnNormal;
    QPushButton *btnMin;
    QPushButton *btnClose;
    QPushButton *btnModify;
    QSpacerItem *Spacer2;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName("MyWidget");
        MyWidget->resize(800, 600);
        MyWidget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	text-align:left;\n"
"	font-size:20px;\n"
"	padding:10px;\n"
"}"));
        verticalLayout = new QVBoxLayout(MyWidget);
        verticalLayout->setObjectName("verticalLayout");
        Spacer1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(Spacer1);

        btnMax = new QPushButton(MyWidget);
        btnMax->setObjectName("btnMax");

        verticalLayout->addWidget(btnMax);

        btnNormal = new QPushButton(MyWidget);
        btnNormal->setObjectName("btnNormal");

        verticalLayout->addWidget(btnNormal);

        btnMin = new QPushButton(MyWidget);
        btnMin->setObjectName("btnMin");

        verticalLayout->addWidget(btnMin);

        btnClose = new QPushButton(MyWidget);
        btnClose->setObjectName("btnClose");

        verticalLayout->addWidget(btnClose);

        btnModify = new QPushButton(MyWidget);
        btnModify->setObjectName("btnModify");

        verticalLayout->addWidget(btnModify);

        Spacer2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(Spacer2);


        retranslateUi(MyWidget);
        QObject::connect(btnClose, &QPushButton::clicked, MyWidget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "\344\277\241\345\217\267\346\247\275\347\232\204\345\244\232\347\247\215\350\277\236\346\216\245\346\226\271\345\274\217", nullptr));
        btnMax->setText(QCoreApplication::translate("MyWidget", "1.\346\234\200\345\244\247\345\214\226\346\230\276\347\244\272\357\274\210SignalSlot\357\274\211", nullptr));
        btnNormal->setText(QCoreApplication::translate("MyWidget", "2.\346\255\243\345\270\270\346\230\276\347\244\272\357\274\210\345\207\275\346\225\260\345\234\260\345\235\200\357\274\211", nullptr));
        btnMin->setText(QCoreApplication::translate("MyWidget", "3.\346\234\200\345\260\217\345\214\226\346\230\276\347\244\272\357\274\210\350\256\276\350\256\241\345\270\210\347\225\214\351\235\242-\350\275\254\345\210\260\346\247\275\357\274\211", nullptr));
        btnClose->setText(QCoreApplication::translate("MyWidget", "4.\345\205\263\351\227\255\347\252\227\345\217\243\357\274\210\350\256\276\350\256\241\345\270\210\347\225\214\351\235\242-\344\277\241\345\217\267\346\247\275\347\274\226\350\276\221\345\231\250\357\274\211", nullptr));
        btnModify->setText(QCoreApplication::translate("MyWidget", "5.\344\277\256\346\224\271\347\252\227\345\217\243\346\240\207\351\242\230\357\274\210Lambda\350\241\250\350\276\276\345\274\217\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
