// 双链表
#include <stdio.h>
typedef int ElemType;


typedef struct DNode {    //定义双链表结点类型
    ElemType data;      //数据域
    struct DNode* prior, * next;    //前驱和后继指针
}DNode, *DLinklist;


//初始化双链表
bool InitDLinkList(DLinklist& L) {
    L = new DNode;      //分配一个头结点
    if (L == NULL)        // 内存不足，分配失败
        return false;
    L->prior = NULL;        //头结点的prior永远指向 NULL
    L->next = NULL;    // 头结点之后暂时还没有节点
    return true;
}


//判断双链表是否为空（(带头结点)
bool Empty(DLinklist L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}


// 在p结点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s) {
    if (p == NULL || s == NULL)        //非法参数
        return false;
    s->next = p->next;
    if (p->next != NULL)//如果p结点有后继结点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}


// 删除p结点的后继结点
bool DeleteNextDNode(DNode* p) {
    if (p == NULL)
        return false;
    DNode* q = p->next;// 找到p的后继结点q
    if (q == NULL)
        return false;// p没有后继p->next=q->next;
    if (q->next != NULL)// q结点不是最后一个结点
        q->next->prior = p;
    delete q;//释放结点空间
    return true;
}

// 销毁列表
void DestoryList(DLinklist& L) {     //循环释放各个数据结点
    while (L->next != NULL)
        DeleteNextDNode(L);
    delete L;     //释放头结点
    L = NULL;    //头指针指向NULL
}



