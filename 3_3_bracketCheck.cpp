// 用栈实现括号匹配问题
/*
( ( ( ( ) ) ) )
① ② ③ ④ ④ ③ ② ①
括号匹配问题中，最后出现的左括号，最先被匹配（LIFO），与栈的逻辑特性相同
每出现一个右括号，就“消耗”一个左括号,对应着出栈的操作
遇见左括号就入栈，遇见右括号就“消耗”一个左括号

用栈实现括号匹配:依次扫描所有字符，遇到左括号入栈，遇到右括号则弹出栈顶元素检查是否匹配。

可能匹配失败的三种情况：
1. 当前扫描到的右括号与栈顶左括号不匹配
2. 扫描到右括号且栈空——右括号单身
3. 处理完所有括号后，栈非空——左括号单身

*/
#include <stdio.h>
#define MaxSize 10  //定义栈中元素的最大个数
typedef struct {
    char data[MaxSize];    // 静态数组存放栈中元素
    int top;    //栈顶指针
} SqStack;


bool bracketCheck(char str[], int length) {
    SqStack S;
    InitStack(S);//初始化一个栈
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            Push(S, str[i]);//扫描到左括号，入栈
        }
        else {
            if (StackEmpty(S))  //扫描到右括号，且当前栈空
                return false;   // 匹配失败


            char topElem;
            Pop(S, topElem);    //栈顶元素出栈
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S); //检索完全部括号后，栈空说明匹配成功
}


//初始化栈
void InitStack(SqStack& S) {}


//判断栈是否为空
bool StackEmpty(SqStack S) {}


//新元素入栈
bool Push(SqStack& S, char x){}


//栈顶元素出栈，用x返回
bool Pop(SqStack& S, char& x) {}