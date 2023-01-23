// 固定长度串的顺序储存定义
#define MAXLEN 255  //预定义最大串长为255
typedef struct {
    char ch[MAXLEN];    // 每个分量存储一个字符
    int length;    // 串的实际长度
}SString;
/*
真正实现时，为了保证串位序与下标相一致，所以往往ch第一个位置不存数据
*/




// 固定长度串的顺序储存——求子串。用Sub返回串S的第pos个字符起长度为len的子串。
bool SubString(SString& Sub, SString S, int pos, int len) {
    //子串范围越界
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];
    Sub.length = len;
    return true;
}


// 固定长度串的顺序储存——比较操作。若S>T，则返回值>0;若S=T，则返回值=0；若S<T，则返回值<0
int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    //扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}


// 固定长度串的顺序储存——定位操作。若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置;否则函数值为0。
int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;//用于暂存子串
    while (i <= n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)++i;
        else return i; //返回子串在主串中的位置
    }
    return 0; //S中不存在与T相等的子串
}



// 可变长度的串的顺序储存定义
typedef struct {
    char* ch;    // 按串长分配存储区，ch指向串的基地址
    int length;    // 串的长度
}HString;
/*动态数组的初始化：
HString S;
S.ch = new char;
S.length = 0; 
*/


// 串的链式存储定义
typedef struct StringNode{
    char ch; // 每个结点存1个字符
    struct StringNode* next;
}StringNode, * String;
/*
但这样存储密度会很低。比如一个char是1B，一个指针在32位系统是4B，所以这样储存密度低
为了改善这一个缺点，可以考虑每次多放几个字符，如char ch[4];
*/


