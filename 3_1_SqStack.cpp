// 顺序栈
#include <stdio.h>
typedef int ElemType;

#define MaxSize 10
//定义栈中元素的最大个数
typedef struct {
    ElemType data[MaxSize];    //静态数组存放栈中元素
    int top;    //栈顶指针
} SqStack;


//初始化栈
void InitStack(SqStack& S) {
    S.top = -1;    //初始化栈顶指针
}


//新元素入栈
bool Push(SqStack& S, ElemType x) {
    if (S.top == MaxSize - 1)        //栈满，报错
        return false;
    S.top = S.top + 1;      //指针先加1
    S.data[S.top] = x;    //新元素入栈
    return true;
}


//出栈操作
bool Pop(SqStack& S, ElemType& x) {
    if (S.top == -1)
        //栈空，报错
        return false;
    x = S.data[S.top]; // 栈顶元素先出栈
    S.top = S.top - 1;//指针再减1
    return true;
}


//读栈顶元素
bool GetTop(SqStack S, ElemType& x) {
    if (S.top == -1)        //栈空，报错
        return false;
    x = S.data[S.top];  //x记录栈顶元素
    return true;
}
