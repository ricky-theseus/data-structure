#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
#include <string>
#include "list.h"
#include"ListSetting.h"
using namespace ListSetting;


template<class T>
class Seqlist: public List<T> {
private:
    int last = 0;
    int maxsize = Seqmaxsize;

    //列表请使用如下的指针定义
    T* data;
    //--------------------

    void extend();
public:

    //-------该部分为需实现的函数----------
    Seqlist();
    Seqlist(int x);

    bool Insert(T x, T y) ;//在值为x的元素后插入一个值为y的元素（bFlag=0单插,bFlag=1多插，建议设一个默认参数）
    bool Remove(T x) ;//删除值为x的节点，务必delete释放内存（bFlag=0单删,bFlag=1多删，建议设一个默认参数）
    void Reverse();//逆置list
    void Insert_last(T &x);//在list的末尾添加一个值为x的元素
    int Size();//返回当前list中的元素个数
    int Capacity();//返回当前list中最大可加入元素个数
    T* Begin();//返回第一个元素的指针
    
    //---------------------------------


    T& operator[](int x);
};




#endif // SEQLIST_H
