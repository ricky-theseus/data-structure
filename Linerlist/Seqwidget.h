#ifndef SEQWIDGET_H
#define SEQWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QString>
#include <QDialog>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>

#include <vector>
#include <string>

#include <Seqlist.h>


class SeqWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SeqWidget(QWidget *parent = nullptr);

    QLabel *title;
    QPushButton *btn_creat;
    QPushButton *btn_push;
//    QPushButton *btn_Ins_single;//Single Insert
    QPushButton *btn_Ins_multiple;//multiple Insert
    QPushButton *btn_Ins_wanted;
//    QPushButton *btn_Del_single;
    QPushButton *btn_Del_multiple;
    QPushButton *btn_Del_wanted;
    QPushButton *btn_reverse;

    QListWidget *widget;

    Seqlist<int> *ptr;

    void Setptr(Seqlist<int> *x);
    void connects();
    void setDia(QDialog *dia, QLabel *lab1, QPushButton *check, QLineEdit *edit, QString s_lab, QString title);
    void refresh();//刷新

    std::vector<int> getnum(std::string s) {//用提取字符串s中的整数
        int x = 0;
        std::vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                while (s[i] >= '0' && s[i] <= '9' && i < s.length()) x = x * 10 + s[i] - '0', i++;
                v.push_back(x);
                x = 0;
            }
        }
        return v;
    }
signals:

};

#endif // SEQWIDGET_H
