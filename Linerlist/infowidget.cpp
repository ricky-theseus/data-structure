#include "infowidget.h"

InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent)
{


    Introduction = new QLabel(this);
    link_creat_time = new QLabel(this);
    link_Ins_time = new QLabel(this);
    link_Del_time = new QLabel(this);

    seq_creat_time = new QLabel(this);
    seq_Ins_time = new QLabel(this);
    seq_Del_time = new QLabel(this);
    Introduction->setText("测试数据元素个数为20000,运行时间为10次测试运行时间的总和。\n运行时间过长将标红。");

    std::srand(std::time(NULL));
    int t1, x;

    int n = 20000, tt = 10;//n表示测试元素个数，tt表示测试次数
    int a[6] = {0, 0, 0, 0, 0, 0};
    while (tt--) {
        seq = new Seqlist<int>();
        link = new Linklist<int>();

        x = (std::rand() + RAND_MAX * std::rand() % 20000) % 20000;

        t1 = std::clock();
        for (int i = 0; i < n; i++) seq->Insert_last(x);
        t1 = std::clock() - t1;
        a[0] += t1;

        t1 = std::clock();
        seq->Insert(x, x);
        t1 = std::clock() - t1;
        a[1] += t1;

        t1 = std::clock();
        seq->Remove(x);
        t1 = std::clock() - t1;
        a[2] += t1;

        t1 = std::clock();
        for (int i = 0; i < n; i++) link->Insert_last(x);
        t1 = std::clock() - t1;
        a[3] += t1;

        t1 = std::clock();
        link->Insert(x, x);
        t1 = std::clock() - t1;
        a[4] += t1;

        t1 = std::clock();
        link->Remove(x);
        t1 = std::clock() - t1;
        a[5] += t1;

        delete seq;
        delete link;
    }
    seq_creat_time->setText("顺序表构造时间: " + QString::number(a[0]) + " ms");
    if (a[0] > 600) Red(seq_creat_time);
    seq_creat_time->move(0, 30 + 20);

    seq_Ins_time->setText("顺序表多插时间: " + QString::number(a[1]) + " ms");
    if (a[1] > 600) Red(seq_Ins_time);
    seq_Ins_time->move(0, 60 + 20);

    seq_Del_time->setText("顺序表多删时间: " + QString::number(a[2]) + " ms");
    if (a[2] > 600) Red(seq_Del_time);
    seq_Del_time->move(0, 90 + 20);

    link_creat_time->setText("链表构造时间: " + QString::number(a[3]) + " ms");
    if (a[3] > 600) Red(link_creat_time);
    link_creat_time->move(200, 30 + 20);

    link_Ins_time->setText("链表多插时间: " + QString::number(a[4]) + " ms");
    if (a[4] > 600) Red(link_Ins_time);
    link_Ins_time->move(200, 60 + 20);

    link_Del_time->setText("链表多删时间: " + QString::number(a[5]) + " ms");
    if (a[5] > 600) Red(link_Del_time);
    link_Del_time->move(200, 90 + 20);
}

void InfoWidget::Red(QLabel *ptr)
{
    QPalette pe;
    pe.setColor(QPalette::WindowText, Qt::red);
    ptr->setPalette(pe);
}
