#include "Seqlist.h"
#include <QDebug>
template class Seqlist<int>;//模板显式实例化
/*
使用的模板类后，函数实现需与类同源。若将函数实现直接置于相应的cpp文件中，将出现编译错误。
可以通过使用export关键字和模板显式实例化解决这一问题。
因为Qt不支持export关键字，所以在本代码中使用的是模板显式实例化。
*/
template <class T>
void Seqlist<T>::extend() {
    T *tmp = new T[maxsize *= 2];//扩充顺序表大小
    for (int i = 0; i < last; i++) tmp[i] = data[i];//复制顺序表的值
    delete data;
    data = tmp;
    tmp = nullptr;
}

//普通的构造函数
template<class T>
Seqlist<T>::Seqlist() {
    //write your code here：实现构造函数
    data=new T[maxsize];
}

//可以设置最大容量的构造函数
template<class T>
Seqlist<T>::Seqlist(int x) {
    //write your code here：实现析构函数
    maxsize=x;
    data=new T[maxsize];
}

template<class T>
bool Seqlist<T>::Insert(T x, T y) {
    //write your code here：在值为x的元素后插入一个值为y的元素
    if(bFlag==1) {//多插
        //这里空间换时间，不用移动原数组的方法而是直接把新插入的元素和数组放到新的数组中
        // for (int i = 0; i < last; i++)
        // {
        //     if(data[i]==x)
        //     {
        //         last++;
        //         if (last >= maxsize) extend();
        //     }
        // }
        // T *tmp = new T[maxsize *= 2];//新数组
        // int j=0;
        // for (int i = 0; i < last; i++)
        // {
        //     if(data[i]==x)
        //     {
        //         tmp[j]=data[i];
        //         tmp[j+1]=y;
        //         j+=2;//插入新元素时j+2
        //     }else {
        //         tmp[j]=data[i];
        //         j++;//不插入新元素时，只+1
        //     }
        // }
        // delete data;//删除原数组
        // data = tmp;//data指向新数组
        // tmp = nullptr; // 将tmp指针设置为nullptr，避免悬挂指针
        // return true;

        // int count = 0;  // 计数器，用于记录值为x的元素的数量
        // for (int i = 0; i < last; i++) {  // 遍历数组，计算值为x的元素的数量
        //     if (data[i] == x) {
        //         count++;
        //     }
        // }
        // if (count == 0) {  // 如果没有找到值为x的元素，直接返回false
        //     return false;
        // }
        // if (last + count > maxsize) {  // 如果数组的大小不足以容纳新的元素，就调用extend函数扩大数组的大小
        //     extend();
        // }
        // for (int i = last - 1; i >= 0; i--) {  // 从数组的末尾开始，向后移动元素以创建插入新元素的空间
        //     data[i + count] = data[i];  // 将当前元素向后移动count个位置
        //     if (data[i] == x) {  // 如果当前元素的值为x，那么在当前位置插入新元素y，并将计数器减1
        //         data[i+1] = y;
        //         count--;
        //     }
        // }
        // last += count;  // 更新数组的大小
        // return true;  // 如果至少有一个元素的值为x，函数返回true，否则返回false

        int count = 0;  // 计数器，用于记录值为x的元素的数量
        int end=last-1;//保留初始尾坐标
        for (int i = last - 1; i >= 0; i--) {  // 从后向前遍历数组，计算值为x的元素的数量
            if (data[i] == x) {
                last++;//找到x的同时扩大last
                count++;
            }
        }
        if (count == 0) {  // 如果没有找到值为x的元素，直接返回false
            return false;
        }
        if (last > maxsize) {  // 如果数组的大小不足以容纳新的元素，就扩大数组的大小
            extend();
        }
        for (int i = last - 1; end >= 0; i--) {  // 从数组的末尾开始，向后移动元素以创建插入新元素的空间
            if(data[end]==x){//如果
                data[i]=y;
                data[i-1]=x;
                i--;
                end--;//位指针前移
            }else{
                data[i]=data[end];
                end--;
            }
        }

        return true;  // 如果至少有一个元素的值为x，函数返回true，否则返回false
    }
    else if(bFlag==0){//单插
        int i;
        for (i = 0; i < last; i++) {
            if (data[i] == x) {
                break;
            }
        }
        if (i == last) {
            return false; // 没有找到值为x的元素
        }
        if (last >= maxsize) {
            extend(); // 如果数组已满，扩展数组
        }
        for (int j = last; j > i + 1; j--) {
            data[j] = data[j - 1]; // 将值为x的元素之后的所有元素向后移动一位
        }
        data[i + 1] = y; // 在值为x的元素后插入值为y的元素
        last++;
        return true;
    }
}

template<class T>
bool Seqlist<T>::Remove(T x) {
    //write your code here：删除值为x的节点，务必delete释放内存
    if(bFlag==1){//多删
        int toDel = 0;//记录等于x的值的数量
        for (int i = 0; i <= last; i++)
        {
            if (data[i] == x)
            {
                //qDebug() << "删除顺序表值 " << x; //这句代码本来是用来测试删除数据的，加上后多删时间大大提高
                toDel++;//若找到值为x的，记录数加1
            }else if (toDel > 0)
            {
                //若toDel大于0 则之前有x
                //将当前元素向前移动toDel个位置
                data[i - toDel] = data[i];
            }
        }
        last -=toDel;//跟新last，减去被删除元素的数量
        return true;
    }
    else if(bFlag==0){//单删
        int i;
        for (i = 0; i < last; i++) {
            if (data[i] == x) {
                    qDebug() << "删除顺序表值 " << x;
                break;
            }
        }
        if (i == last) {
            return false; // 没有找到值为x的元素
        }
        for (int j = i; j < last - 1; j++) {
            data[j] = data[j + 1]; // 将值为x的元素之后的所有元素向前移动一位
        }
        last--;
        return true;
    }
}


template<class T>
void Seqlist<T>::Insert_last(T &x) {
    //write your code here：在list的末尾添加一个值为x的元素,尾插为构造表的必需函数
    if(last>=maxsize) extend();
    data[last++]=x;
}

template<class T>
void Seqlist<T>::Reverse() {
    //write your code here：逆置list
    for(int i=0,j=last-1;i<j;i++,j--){//双指针交换
        T temp=data[i];
        data[i]=data[j];
        data[j]=temp;
    }
}

template<class T>
int Seqlist<T>::Size() {
    return last;
}

template<class T>
int Seqlist<T>::Capacity() {
    return maxsize;//返回最大可加入元素数
}

template<class T>
T* Seqlist<T>::Begin() {
    return data;//data为数组第一项的指针
}

template<class T>
T& Seqlist<T>::operator[](int x) {
    if (x >= last) return data[last - 1];
    if (x < 0) return data[0];
    return data[x];
}






