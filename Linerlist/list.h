#ifndef LIST_H
#define LIST_H

#include <string>
#include <vector>
template<class T>
class List{
public:
    virtual bool Insert(T x, T y)=0;
    virtual bool Remove(T x)=0;
    virtual int Size()=0;
    virtual void Insert_last(T &x)=0;
    virtual void Reverse()=0;
};


#endif  //LIST_H
