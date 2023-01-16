// 共享栈
#include <stdio.h>
typedef int ElemType;

#define MaxSize 10
//定义栈中元素的最大个数
typedef struct {
    ElemType data[MaxSize];    //静态数组存放栈中元素
    int top0;    // 0号栈栈顶指针
    int top1;   //1号栈栈顶指针
}ShStack;


//初始化栈
void InitStack(ShStack& S) {
    S.top0 = -1;    //初始化栈顶指针
    S.top1 = MaxSize;
}
