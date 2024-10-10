#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QPushButton>
#include <QStackedWidget>

#include "Linkwidget.h"
#include "Seqwidget.h"
#include "infowidget.h"
#include "Linklist.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *btn_info,*btn_seq,*btn_list;
    QDockWidget *Sidebar;
    QStackedWidget *CenteralWidget;

    InfoWidget *wid_info;
    LinkWidget *wid_link;
    SeqWidget *wid_seq;

    Linklist<int> *link;
    Seqlist<int> *seq;
};
#endif // MAINWINDOW_H
