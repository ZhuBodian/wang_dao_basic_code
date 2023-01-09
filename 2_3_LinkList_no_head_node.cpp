// 不带头结点单链表
#include <stdio.h>
typedef int ElemType;

typedef struct LNode {    //定义单链表结点类型
    ElemType data;       //每个节点存放一个数据元素
    struct LNode* next;     //指针指向下一个节点
}LNode, * LinkList;


// 不带头结点的，初始化一个空的单链表
bool InitList(LinkList &L) {
    L = NULL;     //空表，暂时还没有任何结点
    return true;
}


// 不带头结点的，判断单链表是否为空
bool Empty(LinkList L) {
    if (L == NULL)
        return true;
    else
        return false;
}


// 不带头结点的，按位序插入
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    if (i == 1) {   //插入第1个结点的操作与其他结点操作不同
        LNode* s = new LNode;
        s->data = e;
        s->next = L;
        L = s;        // 头指针指向新结点
        return true;
    }
    
    LNode* p;       //指针p指向当前扫描到的结点
    int j = 1;    // 当前p指向的是第几个结点
    p = L;    // p指向第1个结点（注意:不是头结点)
    while (p != NULL && j < i - 1) { //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)  //i值不合法
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    
    return true;    // 插入成功
}


// 不带头结点，后插操作：在p结点之后插入元素e；和带头结点的一样


// 不带头结点，前插操作:在p结点之前插入元素e；和带头结点的一样
