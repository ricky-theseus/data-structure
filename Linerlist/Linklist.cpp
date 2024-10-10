#include "Linklist.h"
#include <QDebug>
#include"ListSetting.h"
using namespace ListSetting;
template class Linklist<int>;//模板显式实例化

/*
使用的模板类后，函数实现需与类同源。若将函数实现直接置于相应的cpp文件中，将出现编译错误。
可以通过使用export关键字和模板显式实例化解决这一问题。
因为Qt不支持export关键字，所以在本代码中使用的是模板显式实例化。
*/
template <class T>
Linklist<T>::Linklist() {
    //write your code here：实现构造函数
    begin =new Linknode<T>(0);
    end=begin;
    last=begin;
    size=0;
}

template<class T>
Linklist<T>::~Linklist() {
    //write your code here：实现析构函数
    //啊啊啊啊啊啊感觉没用上析构函数，大完蛋
    //后面虽然用上了，但还是傻傻分不清楚
    Linknode<T>*temp;
    while(begin!=nullptr){
        temp=begin;
        begin=temp->next;
         //qDebug() << "删除节点值: " << temp->val;//测试代码
        delete temp;
    }
}

template<class T>
bool Linklist<T>::Insert(T x, T y) {
    //write your code here：在值为x的元素后插入一个值为y的元素
    if(bFlag==1){//多插
        Linknode<T>*temp=begin;//temp为寻找x的指针
        bool found=false;//标记是否找到x
        //寻找值为x的节点
        while(temp!=nullptr){
            if(temp->val==x){
                //找到val为x的节点，在后面插入y
                Linknode<T>*newNode=new Linknode<T>(y);
                newNode->next=temp->next;
                temp->next=newNode;
                //插入位置为末端的时候，更新end
                if(temp==end){
                    end=newNode;
                }
                //每次插入后都要更新大小
                size++;
                found=true;//标记为真
                temp=newNode->next;//更新temp指针，跳过新插入的节点，避免无限循环
            }else{
                temp=temp->next;//没找到就正常往后遍历
            }
        }
        return found;//找到至少一个x，则返回true
    }
    else if(bFlag==0){//单插
        Linknode<T>* temp = begin;//从头开始
        while (temp != nullptr) {
            if (temp->val == x) {
                //找到val为x的节点，在后面插入y
                Linknode<T>* newNode = new Linknode<T>(y);
                newNode->next = temp->next;
                temp->next = newNode;
                //插入位置为末端的时候，更新end
                if (temp == end) {
                    end = newNode;
                }
                size++;//插入后更新大小
                return true;//插入成功，返回真
            }
            temp = temp->next;//向后遍历
        }
        return false;;
    }
}

template<class T>
bool Linklist<T>::Remove(T x) {
    //write your code here：删除值为x的节点，务必delete释放内存
    if(bFlag==1){
        Linknode<T>*temp=begin;//temp为寻找x的指针
        Linknode<T>*prev=nullptr;//薄脆前一个节点的指针
        bool found=false;//标记是否找到x
        //寻找值为x的节点
        while(temp!=nullptr){
            if(temp->val==x){
                //找到val为x的节点，删除
                Linknode<T>*toDelete=temp;
                if(prev==nullptr){//如果前一个节点为空，那么temp就是begin
                    begin=temp->next;//此时要删除begin，所有要往后移动一格
                }else{
                    prev->next=temp->next;//其他情况前一个节点的next指向temp后的节点
                }
                if(temp==end){//如果temp为结束节点
                    end=prev;//那么此时要删除end，prev就成为end
                }
                temp=temp->next;//往后移动
                delete toDelete;
                size--;//减少链表长度
                found=true;//标记为真
            }else{
                prev=temp;
                temp=temp->next;//向后移动
            }
        }
        return found;//找到至少一个x，则返回true
    }else if(bFlag==0){
        Linknode<T>* temp = begin;
        Linknode<T>* prev = nullptr;
        while (temp != nullptr) {
            if (temp->val == x) {
                if (temp == begin) {
                    begin = temp->next;
                } else {
                    prev->next = temp->next;
                }
                if (temp == end) {
                    end = prev;
                }
                delete temp;
                size--;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }
}

template<class T>
void Linklist<T>::Reverse() {
    //write your code here：逆置list
    Linknode<T> *prev=nullptr;//当前指针的前节点
    Linknode<T>*temp=begin->next;//当前节点指向头节点的下一个节点，因为这里的头节点是作为哑节点不算进去
    Linknode<T>*nextOne=nullptr;//当前节点后节点

    while(temp!=nullptr){
        nextOne=temp->next;//保存下节点
        temp->next=prev;//颠倒顺序
        prev=temp;//前节点向后移
        temp=nextOne;//当前节点也后移
    }
    //交换begin和end
    Linknode<T>*t=begin->next;
    begin->next=end;
    end=t;
}

template<class T>
void Linklist<T>::Insert_last(T &x) {
    //write your code here：在list的末尾添加一个值为x的节点,尾插为构造表的必需函数
    Linknode<T>* newNode = new Linknode<T>(x);//创建新节点
    end->next = newNode;//尾部指向新节点
    end = newNode;//更新end为新节点
    size++;//长度++
}

template<class T>
void Linklist<T>::Insert_begin(T &x)
{
    Linknode<T>* newNode =new Linknode<T>(x);
    newNode=begin->next;
    begin->next=newNode;
    size++;
}

template<class T>
int Linklist<T>::Size() {
    return size;
}
template<class T>
Linknode<T> *Linklist<T>::Begin() {
    return begin->next;
}

