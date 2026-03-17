#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QDateTime>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //1.使用SIGNAL/SLOT的方式连接信号和槽（QT4）
    connect(ui->btnMax,SIGNAL(clicked()),this,SLOT(showMaximized()));//编译不会检查错误

    //2.使用函数地址的方式（QT5）
    connect(ui->btnNormal,&QPushButton::clicked,this,&QWidget::showNormal);//没办法指定参数，可以用QOverload解决

    //a.演示lambda表达式

    //a.1 匿名函数的定义
#if 0
    []()
    {
        qDebug() << "lambda...";
    };
#endif

    //a.2 匿名函数的调用
#if 0
    []()
    {
        qDebug() << "lambda...";
    }();
#endif

    int a = 10;
    //a.3 不捕获任何变量
#if 0
    []()
    {
        qDebug() << a;
    }();
#endif

    //a.4 按引用捕获
#if 0
    [&]()
    {
        qDebug() << a++;
    }();
    qDebug() << a;
#endif

    //a.5 按值捕获
   //按值捕获的变量，只读
#if 0
    [=]()
    {
        qDebug() << a++;
    }();
#endif

    //a.6 按值捕获 + mutable 选项
    //添加mutable选项，就可以在lambda内修改捕获的变量了
    //并且=这种方式，是按值传递的，里面的修改，不会影响到外面
#if 0
    [=]()mutable
    {
        qDebug() << a++;
    }();
    qDebug() << a; //10
#endif

    //a.7 参数
#if 0
    [](int x, int y)
    {
        qDebug() << x+y;
    }(1,2);
#endif

    //a.8 返回值
#if 0
    int sum = [](int x,int y) -> int
    {
        return x + y;
    }(1,2);
    qDebug() << sum;
#endif


    //3.设计师界面
    //4.设计师界面

    //5.lamdba表达式做槽函数
    connect(ui->btnModify,&QPushButton::clicked,this,
            [this]()
            {
                QString title = QDateTime::currentDateTime().toString("yyyy-MM-dd:hh:mm:ss");
                this->setWindowTitle(title);
            });

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_btnMin_clicked()
{
    this->showMinimized();
}

