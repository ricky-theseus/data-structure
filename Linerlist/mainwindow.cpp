#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Linearlist");
    resize(600,500);

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

//    Sidebar=new QDockWidget(this);
//    Sidebar->setFeatures(0);
//    Sidebar->setAllowedAreas(Qt::LeftDockWidgetArea);
//    Sidebar->setTitleBarWidget(new QWidget());
//    Sidebar->setMinimumWidth(90);
//    Sidebar->setMaximumWidth(90);
////    Sidebar->resize(100,height());
//    addDockWidget(Qt::LeftDockWidgetArea,Sidebar);
    link=new Linklist<int>();
    seq=new Seqlist<int>();

    wid_info=new InfoWidget(this);
    wid_link=new LinkWidget(this);wid_link->Setptr(link);
    wid_seq=new SeqWidget(this);wid_seq->Setptr(seq);

    CenteralWidget=new QStackedWidget(this);
    CenteralWidget->resize(500,500);
    CenteralWidget->move(100,0);
    CenteralWidget->addWidget(wid_info);
    CenteralWidget->addWidget(wid_seq);
    CenteralWidget->addWidget(wid_link);





    btn_info=new QPushButton(this);
    btn_info->setText("测试信息");
    btn_info->resize(100,30);
    btn_info->move(0,0);

    btn_seq=new QPushButton(this);
    btn_seq->setText("顺序表");
    btn_seq->resize(100,30);
    btn_seq->move(0,30);

    btn_list=new QPushButton(this);
    btn_list->setText("链表");
    btn_list->resize(100,30);
    btn_list->move(0,60);

    connect(btn_info,&QPushButton::clicked,this,[=](){
        CenteralWidget->setCurrentIndex(0);
    });
    connect(btn_seq,&QPushButton::clicked,this,[=](){
        CenteralWidget->setCurrentIndex(1);
    });
    connect(btn_list,&QPushButton::clicked,this,[=](){
        CenteralWidget->setCurrentIndex(2);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

