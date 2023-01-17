// 队列的顺序实现
#include <stdio.h>
typedef int ElemType;

#define MaxSize 10
//定义队列中元素的最大个数
typedef struct {
    ElemType data[MaxSize];    //用静态数组存放队列元素
    int front, rear;        //队头指针和队尾指针
} SqQueue;


//初始化队列
void InitQueue(SqQueue& Q) {//初始时队头、队尾指针指向0
    Q.rear = Q.front = 0;
}


//判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    if (Q.rear == Q.front)        //队空条件
        return true;
    else
        return false;
}


//入队
bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;       //队满则报错
    Q.data[Q.rear] = x;    //新元素插入队尾
    Q.rear = (Q.rear + 1) % MaxSize;//队尾指针加1取模
    return true;

}


//出队（删除一个队头元素，并用x返回)
bool DeQueue(SqQueue& Q, ElemType& x) {
    if (Q.rear == Q.front)
        return false;   //队空则报错
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}


//获得队头元素的值，用x返回
bool GetHead(SqQueue Q, ElemType& x) {
    if (Q.rear == Q.front)
        return false;//队空则报错
    x = Q.data[Q.front];
    return true;
}



 // 判断队列已满/已空—————方案一
#define Maxsize 10
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
}sqQueue;
// 队列已满的条件:队尾指针的再下一个位置是队头，即(Q.rear+1)%MaxSize==Q.front
// 这样会浪费一个存储空间，但是不这样的话，队满与队空一样，无法判断
// 队空条件:Q.rear==Q.front
// 队列元素个数:(rear+MaxSize-front)%MaxSize


 // 判断队列已满/已空—————方案二
#define Maxsize 10
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    int size;   //队列当前长度
} SqQueue;
// 初始化时，rear=front=0；size=0
// 插入成功size++；
// 删除成功size--
// 队满条件：size==MaxSize
// 队空条件：size==0
// 虽然队满队空时，front和rear指向同一个位置，但是可以借助size变量区分是队空还是队满


 // 判断队列已满/已空—————方案三
#define Maxsize 10
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    int tag;//最近进行的是删除/插入
} SqQueue;
// 初始化时rear=front=O; tag =O；
// 每次删除操作成功时，都令tag=O;每次插入操作成功时，都令tag=1;
// 只有删除操作，才可能导致队空； 只有插入操作，才可能导致队满
// 队满条件：front==rear && tag == 1
// 队空条件：front==rear && tag == 0
