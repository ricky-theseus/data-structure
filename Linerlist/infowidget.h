#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QLabel>
#include "Linklist.h"
#include "Seqlist.h"
#include <ctime>
#include <cstdlib>
#include <QPalette>

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfoWidget(QWidget *parent = nullptr);
    QLabel *Introduction;

    QLabel *link_creat_time;
    QLabel *link_Ins_time;
    QLabel *link_Del_time;

    QLabel *seq_creat_time;
    QLabel *seq_Ins_time;
    QLabel *seq_Del_time;

    Seqlist<int> *seq;
    Linklist<int> *link;
    void Red(QLabel* ptr);
signals:

};

#endif // INFOWIDGET_H
