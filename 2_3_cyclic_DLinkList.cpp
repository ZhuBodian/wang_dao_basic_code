// 循环双链表
#include <stdio.h>
typedef int ElemType;


typedef struct DNode {    //定义双链表结点类型
    ElemType data;      //数据域
    struct DNode* prior, * next;    //前驱和后继指针
}DNode, * DLinklist;


//初始化空的循环双链表
bool InitDLinkList(DLinklist& L) {
    L = new DNode;//分配一个头结点
    if (L == NULL)        //内存不足，分配失败
        return false;
    L->prior = L;//头结点的prior指向头结点
    L->next = L;    //头结点的next指向头结点
    return true;
}


//判断循环双链表是否为空
bool Empty(DLinklist L) {
    if (L->next == L)
        return true;
    else
        return false;
}


//判断结点p是否为循环双链表的表尾结点
bool isTail(DLinklist L, DNode* p) {
    if (p->next == L)
        return true;
    else
        return false;
}


//在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s) {
    s->next = p->next; // 将结点 * s插入到结点 * p之后
    p->next->prior = s;  //如果只是普通双链表，那么若p是最后一个元素，这里会出错
    s->prior = p;
    p->next = s;
}


// 删除p结点的后继结点
bool DeleteNextDNode(DNode* p) {
    DNode* q = p->next;// 找到p的后继结点q
    p->next = q->next;
    q->next->prior = p;  //如果只是普通双链表，那么若p是最后一个元素，这里会出错
    delete q;//释放结点空间
    return true;
}