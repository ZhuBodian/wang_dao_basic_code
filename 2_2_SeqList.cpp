// 顺序表的实现——动态分配
#include <stdio.h>
typedef int ElemType;

#define Initsize 10//默认的最大长度
typedef struct {
    ElemType *data;      //指示动态分配数组的指针
    int MaxSize;       //顺序表的最大容量
    int length;    //顺序表的当前长度
}SeqList;


// 动态顺序表初始化
void InitList(SeqList& L) {
    //用new函数申请一片连续的存储空间
    L.data = new ElemType[Initsize];
    L.length = 0;
    L.MaxSize = Initsize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len) {
    int *p = L.data;
    L.data = new ElemType[L.MaxSize + len];
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];            //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;        //顺序表最大长度增加len
    delete(p);        //释放原来的内存空间
}

int main() {
    SeqList L;    // 声明一个顺序表
    InitList(L);    //初始化顺序表
    //...往顺序表中随便插入几个元素...
    IncreaseSize(L,5);
    return 0;
}
