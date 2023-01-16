// 链栈
#include <stdio.h>
typedef int ElemType;

typedef struct Linknode {
    ElemType data;    //数据域
    struct Linknode* next;    // 指针域
} *LiStack;  //栈类型定义
