// 带头结点单链表
#include <stdio.h>
typedef int ElemType;

typedef struct LNode {    //定义单链表结点类型
    ElemType data;       //每个节点存放一个数据元素
    struct LNode* next;     //指针指向下一个节点
}LNode, * LinkList;

/*
typedef相当于重名名
上段代码相当于
struct LNode{   //定义单链表结点类型
    ElemType data;      //每个节点存放一个数据元素
    struct LNode *next;     //指针指向下一个节点
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;

要表示一个单链表时，只需声明一个头指针L，指向单链表的第一个结点
LNode * L;  //声明一个指向单链表第一个结点的指针
或: LinkList L; //声明一个指向单链表第一个结点的指针
*/


// 带头结点的，初始化一个空的单链表
bool InitList(LinkList &L) {
    L = new LNode;    //分配一个头结点
    if (L == NULL)    //内存不足，分配失败
        return false;
    L->next = NULL;     //头结点之后暂时还没有节点
    return true;
}


//判断带头结点的单链表是否为空
bool Empty(LinkList L) {
    if (L->next == NULL) 
        return true;
    else
        return false;
}


// 带头结点，在第i个位置插插入元素e 
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    LNode *p;       //指针p指向当前扫描到的结点
    int j = 0;      // 当前p指向的是第几个结点
    p = L;    //L指向头结点，头结点是第0个结点(不存数据)
    while (p != NULL && j < i - 1) {    //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)      //i值不合法
        return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;        //将结点s连到p之后
    return true;    //插入成功
}


// 带头结点/不带头结点，后插操作：在p结点之后插入元素e
bool InsertNextNode(LNode* p, ElemType e) {
    if (p == NULL)
        return false;
    LNode* s = new LNode;
    if (s == NULL) // 内存分配失败，如内存不足 
        return false;
    s->data = e;       //用结点s保存数据元素e
    s->next = p->next;
    p->next = s;        //将结点s连到p之后
return true;
}


// 带头结点/不带头结点，前插操作:在p结点之前插入元素e
bool InsertPriorNode(LNode* p, ElemType e) {
    if (p == NULL)
        return false;
    LNode* s = new LNode;
    if (s == NULL)//内存分配失败
        return false;
    s->next = p->next;
    p->next = s;     //新结点s 连到p之后
    s->data = p->data;    //将p中元素复制到s中
    p->data = e;    // p 中元素覆盖为e
    return true;
}


// 带头结点按位序删除，并返回删除所节点的值
bool ListDelete(LinkList& L, int i, ElemType& e) {
    if (i < 1)
        return false;
    LNode* p;       // 指针p指向当前扫描到的结点
    int j = 0;    // 当前p指向的是第几个结点
    p = L;    //L指向头结点，头结点是第0个结点(不存数据)
    while (p != NULL && j < i - 1) {    //循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if (p == NULL)    // i值不合法
        return false;
    if (p->next == NULL)    //第i-1个结点之后已无其他结点
        return false;
    LNode* q = p->next;     // 令q指向被删除结点
    e = q->data;    //用e返回元素的值
    p->next = q->next;    //将*q结点从链中“断开”
    delete q;   //释放结点的存储空间
    return true;    //删除成功
}


// 带头结点/不带头结点指定节点的删除
// 只适合p非最后一个节点的情况，如果p是最后一个节点，那么只能采用那种，从第一个节点开始遍历的算法
bool DeleteNode(LNode* p) {
    if (p == NULL)
        return false;
    LNode* q = p->next;    // 令q指向 * p的后继结点
    p->data = p->next->data;    //和后继结点交换数据域。如果p是最后一个节点，这句出错。
    p->next = q->next;    //将*q结点从链中“断开”
    delete q;     //释放后继结点的存储空间
    return true;
}


// 带头结点，按位查找，返回第i个元素
LNode* GetElem(LinkList L, int i) {
    if (i < 0)
        return NULL;
    LNode* p;   // 指针p指向当前扫描到的结点
    int j = 0;  // 当前p指向的是第几个结点
    p = L;     //L指向头结点，头结点是第0个结点(不存数据)
    while (p != NULL && j < i) { //循环找到第i 个结点
        p = p->next;
        j++;
    }
    return p;
}


// 带头结点，按值查找，找到数据域==e的结点
LNode* LocateElem(LinkList L, ElemType e) {
    LNode* p = L->next;    //从第1个结点开始查找数据域为e的结点
    while (p != NULL && p->data != e)
        p = p->next;
    return p;   //找到后返回该结点指针，否则返回NULL
}


// 带头结点，求表长度
int Length(LinkList L) {
    int len = 0;        //统计表长
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}


// 尾插法建立单链表
LinkList List_Taillnsert(LinkList& L) {    //正向建立单链表
    ElemType x;  
    L = new LNode;      //建立头结点
    LNode* s, * r = L;      //r为表尾指针
    scanf("%d", &x);            //输入结点的值
    while (x != 9999) {        //输入9999表示结束
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;      //r指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL;     //尾结点指针置空
    return L;
}


// 头插法建立带头结点单链表
LinkList List_HeadInsert(LinkList& L) {  //逆向建立单链表
    LNode* s;
    ElemType x;
    L = new LNode;//创建头结点
    L->next = NULL;    // 初始为空链表
    scanf("%d", &x);    //输入结点的值
    while (x != 9999) {        //输入9999表示结束
        s = new LNode;//创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s;        //将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}




int main() {
    LinkList L;
    InitList(L);
    return 0;  
}