#include "Linkwidget.h"

//ui界面，无需填入代码

LinkWidget::LinkWidget(QWidget *parent) : QWidget(parent) {
//    lab=new QLabel(this);
//    lab->setText("3");
    title = new QLabel(this);
    title->setText("链表");
    title->setFont(QFont( "Microsoft YaHei", 15, 60));
    resize(400, 450);
    widget = new QListWidget(this);
    widget->resize(300, height() - 10);
    widget->move(0, 30);

    btn_creat = new QPushButton(this); btn_creat->setText("创建表");
    btn_creat->move(310, 10); btn_creat->resize(180, 40);

    btn_push = new QPushButton(this); btn_push->setText("添加元素");
    btn_push->move(310, 60); btn_push->resize(180, 40);

    btn_Ins_multiple = new QPushButton(this); btn_Ins_multiple->setText("在指定数据后插入元素");
    btn_Ins_multiple->move(310, 110); btn_Ins_multiple->resize(180, 40);

    btn_Del_multiple = new QPushButton(this); btn_Del_multiple->setText("删除所有指定值元素");
    btn_Del_multiple->move(310, 160); btn_Del_multiple->resize(180, 40);

    btn_reverse = new QPushButton(this); btn_reverse->setText("元素逆置");
    btn_reverse->move(310, 210); btn_reverse->resize(180, 40);
    connects();
}
void LinkWidget::setDia(QDialog *dia, QLabel *lab, QPushButton *check, QLineEdit *edit, QString s_lab, QString title) {
    lab->resize(400, 30);
    lab->setText(s_lab);

    check->setText("确定"); check->move(85, 80); check->resize(80, 30);

    edit->move(0, 50); edit->resize(250, 20);
    dia->setWindowTitle(title); dia->resize(250, 120);
    dia->show();
}

void LinkWidget::refresh()
{
    widget->clear();
    Linknode<int>* tmp = ptr->Begin();
    int n = ptr->Size();
    for (int i = 0; i < n; i++, tmp = tmp->next) {
        widget->addItem(QString::fromStdString(std::to_string(tmp->val)));
    }

}

void LinkWidget::connects() {
    connect(btn_creat, &QPushButton::clicked, this, [ = ]() {
        QDialog *dia = new QDialog(this);
        QLabel *lab = new QLabel(dia);
        QPushButton *check = new QPushButton(dia);
        QLineEdit *edit = new QLineEdit(dia);
        setDia(dia, lab, check, edit, "请输入需要创建的序列（使用空格相隔）", "创建表");

        connect(check, &QPushButton::clicked, dia, [ = ]() {
            std::string s = edit->text().toStdString();
            std::vector<int> tmp = getnum(s);
            delete ptr;
            ptr = new Linklist<int>();
            for (int i = 0; i < tmp.size(); i++) ptr->Insert_last(tmp[i]);
            refresh();
            dia->close();
        });
    });

    connect(btn_push, &QPushButton::clicked, this, [ = ]() {
        QDialog *dia = new QDialog(this);
        QLabel *lab = new QLabel(dia);
        QPushButton *check = new QPushButton(dia);
        QLineEdit *edit = new QLineEdit(dia);
        setDia(dia, lab, check, edit, "请输入插入元素的值", "插入元素");

        connect(check, &QPushButton::clicked, dia, [ = ]() {
            std::string s = edit->text().toStdString();
            std::vector<int> tmp = getnum(s);
            if (tmp.size() == 1) {
                ptr->Insert_last(tmp[0]);
                refresh();
                dia->close();
            }
        });
    });

    connect(btn_Ins_multiple, &QPushButton::clicked, this, [ = ]() {
        QDialog *dia = new QDialog(this);
        QLabel *lab = new QLabel(dia);
        QPushButton *check = new QPushButton(dia);
        QLineEdit *edit = new QLineEdit(dia);
        setDia(dia, lab, check, edit, "请输入指定数据X及插入元素值Y（用空格隔开）", "在指定数据后插入元素");

        connect(check, &QPushButton::clicked, dia, [ = ]() {
            std::string s = edit->text().toStdString();
            std::vector<int> tmp = getnum(s);
            if (tmp.size() == 2) {
                ptr->Insert(tmp[0], tmp[1]);		//s获取输入的string字符串，tmp数组获取s中的两个数据，ui传递输入的第一，第二个值进入函数
                refresh();
                dia->close();
            }
        });
    });

    connect(btn_Del_multiple, &QPushButton::clicked, this, [ = ]() {
        QDialog *dia = new QDialog(this);
        QLabel *lab = new QLabel(dia);
        QPushButton *check = new QPushButton(dia);
        QLineEdit *edit = new QLineEdit(dia);
        setDia(dia, lab, check, edit, "请输入指定删除元素值", "删除所有指定值元素");

        connect(check, &QPushButton::clicked, dia, [ = ]() {
            std::string s = edit->text().toStdString();
            std::vector<int> tmp = getnum(s);
            if (tmp.size() == 1) {
                ptr->Remove(tmp[0]);		//s获取输入的string字符串，tmp数组获取s中的数据，ui传递输入的值进入函数
                refresh();
                dia->close();
            }
        });
    });

    connect(btn_reverse, &QPushButton::clicked, this, [ = ]() {
        ptr->Reverse();
        refresh();
    });

}

void LinkWidget::Setptr(Linklist<int> *x) {
    ptr = x;
}





