#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <string>
#include "list.h"
#include <vector>

template<class T>
class Linknode {
public:
    Linknode<T> *next; //指向下一个节点的
    T val; //数据域
    Linknode(T x): next(nullptr), val(x) {} //构造函数，创建一个值为x的节点
    Linknode(Linknode<T>* _next, T x): next(_next), val(x) {}
};

//链表实现节点请使用Linknode类
template<class T>
class Linklist:public List<T>{
private:
    Linknode<T> *begin, *end, *last; //开始，结束，最后
    int size = 0;
public:
    //-------该部分为需实现的函数----------
    Linklist();
    ~Linklist() ;
    bool Insert(T x, T y) ;//在值为x的元素后插入一个值为y的元素（bFlag=0单插,bFlag=1多插，建议设一个默认参数）
    bool Remove(T x) ;//删除值为x的节点，务必delete释放内存（bFlag=0单删,bFlag=1多删，建议设一个默认参数）
    void Reverse() ;//逆置list
    void Insert_last(T &x);//在list的末尾添加一个值为x的元素
    void Insert_begin(T &x);//在list的头部添加一个值为x的元素
    int Size() ;//返回表长
    Linknode<T> *Begin() ;//返回第一个元素的指针
    //---------------------------------

    Linknode<T>* remove(Linknode<T> *ptr) ;
};




#endif // LINKLIST_H
