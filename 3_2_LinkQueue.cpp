// 队列的链式实现
#include <stdio.h>
typedef int ElemType;


typedef struct LinkNode {    //链式队列结点
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct {    //链式队列
    LinkNode* front, * rear;//队列的队头和队尾指针
}LinkQueue;


//初始化队列(带头结点)
void InitQueue(LinkQueue &Q){   //初始时front、rear都指向头结点
    Q.front = Q.rear = new LinkNode;
    Q.front->next = NULL;
}


//判断队列是否为空（带头结点）
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}


//新元素入队(带头结点)
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = new LinkNode;
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;    //新结点插入到rear之后
    Q.rear = s;    //修改表尾指针
}


//队头元素出队（带头结点)
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
        return false;   //空队
    LinkNode* p = Q.front->next;
    x = p->data;    //用变量x返回队头元素
    Q.front->next = p->next; // 修改头结点的 next指针
    if (Q.rear == p)       //此次是最后一个结点出队
        Q.rear = Q.front;    //修改rear指针
    delete p;    // 释放结点空间
    return true;
}


//初始化队列(不带头结点)
void InitQueue(LinkQueue& Q) {   //初始时 front、rear都指向NULL
    Q.front = NULL;
    Q.rear = NULL;
}


//判断队列是否为空(不带头结点)
bool IsEmpty(LinkQueue Q) {
    if (Q.front == NULL) 
        return true;
    else
        return false;
}



//新元素入队(不带头结点)
void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = new LinkNode;
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL){   //在空队列中插入第一个元素
        Q.front = s;    //修改队头队尾指针
        Q.rear = s;
    }
    else {
        Q.rear->next = s;    // 新结点插入到rear结点之后
        Q.rear = s;        //修改rear指针
    }
}


//队头元素出队(不带头结点)
bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == NULL)
        return false;   //空队
    LinkNode* p = Q.front;    // p指向此次出队的结点
    x = p->data;    /// 用变量x返回队头元素
    Q.front = p->next;    //修改front指针
    if (Q.rear == p) {    //此次是最后一个结点出队
        Q.front = NULL;     // front指向NULL
        Q.rear = NULL;       // rear指向NULL
    }
    delete p;    // 释放结点空间
    return true;
}
