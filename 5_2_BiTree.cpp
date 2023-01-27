#define MaxSize 100
#define ElemType int
// 二叉树顺序存储
struct TreeNode {
    ElemType value;//结点中的数据元素
    bool isEmpty;   //结点是否为空
};

/*
定义一个长度为MaxSize的数组t，按照从上至下、从左至右的顺序依次存储完全二叉树中的各个结点
可以让第一个位置空缺，保证数组下标和节点编号一致
TreeNode t[MaxSize];

for (int i=0; i<MaxSize; i++){  //初始化时所有结点标记为空
    t[i].isEmpty=true;
}

*/


// 二叉树的结点(链式存储)
struct ElemType {
    int value;
};

typedef struct BiTNode {
    ElemType data;    //数据域
    struct BiTNode *lchild, *rchild;    // 左、右孩子指针
}BiTNode, *BiTree;

/*
二叉树链式存储初始化：
//定义一棵空树
BiTree root = NULL;

//插入根节点
root = new BiTree;
root->data = {1};
root->lchild = NULL;
root->rchild = NULL;

//插入新结点
BiTNode * p = new BiTNode;
p->data = {2};
p->lchild = NULL;
p->rchild = NULL;
root-> = lchild =p; //作为根节点的左孩子
*/


// 三叉链表
typedef struct BiTNode {
    ElemType data;    //数据域
    struct BiTNode* lchild, * rchild;    // 左、右孩子指针
    struct BiTNode* parent;     //父节点指针
}BiTNode, * BiTree;