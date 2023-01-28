#include<stdio.h>
#define ElemType int

typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;


// 二叉树层次遍历
void visit(BiTree T) {}
// 先序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);       //访问根结点，具体要做什么根据vist函数而定
        PreOrder(T->lchild);        // 递归遍历左子树
        PreOrder(T->rchild);        // 递归遍历右子树
    }
}


// 中序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        PreOrder(T->lchild);        // 递归遍历左子树
        visit(T);       //访问根结点，具体要做什么根据vist函数而定
        PreOrder(T->rchild);        // 递归遍历右子树
    }
}


// 后序遍历
void PreOrder(BiTree T) {
    if (T != NULL) {
        PreOrder(T->lchild);        // 递归遍历左子树
        PreOrder(T->rchild);        // 递归遍历右子树
        visit(T);       //访问根结点，具体要做什么根据vist函数而定
    }
}


//层序遍历
typedef struct LinkNode {    //链式队列结点
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct {    //链式队列
    LinkNode* front, * rear;//队列的队头和队尾指针
}LinkQueue;

void InitQueue(LinkQueue &Q) {}
void EnQueue(LinkQueue &Q, BiTree T) {}
bool IsEmpty(LinkQueue Q) {}
void DeQueue(LinkQueue &Q, BiTree &p) {}


void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);   //初始化辅助队列
    BiTree p;
    EnQueue(Q, T);  //将根结点入队
    while ( !IsEmpty(Q)) {        //队列不空则循环
        DeQueue(Q, p);  //队头结点出队
        visit(p);        // 访问出队结点
        if (p->lchild != NULL)
            EnQueue(Q, p->lchild);  //左孩子入队
        if (p->rchild != NULL)
            EnQueue(Q, p->rchild);  //右孩子入队
}
}


//线索二叉树结点
typedef struct ThreadNode {
    ElemType data;
    struct ThreadNode* lchild, * rchild;
    int ltag, rtag;    //左、右线索标志，tag==0，表示指针指向孩子tag==1，表示指针是“线索”
}ThreadNode,*ThreadTree;
//全局变量pre，指向当前访问结点的前驱
ThreadNode* pre = NULL;

void visit(ThreadNode* q) {
    if (q->lchild == NULL) {//左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL){
        pre->rchild = q;//建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}


//中序线索化二叉树T
void CreateInThread(ThreadTree T) {
    pre = NULL;    // pre初始为NULL
    if (T != NULL) {
        //非空二叉树才能线索化
        InThread(T);        // 中序线索化二叉树
        if (pre->rchild == NULL) {
            pre->rtag = 1;//处理遍历的最后一个结点
        }
    }
}

// 中序遍历二叉树，一遍遍历一遍线索化
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lchild);        // 递归遍历左子树
        visit(T);       //访问根结点，具体要做什么根据vist函数而定
        InThread(T->rchild);        // 递归遍历右子树
    }
}


//先序线索化二叉树T
void CreatePreThread(ThreadTree T) {
    pre = NULL;    // pre初始为NULL
    if (T != NULL) {        //非空二叉树才能线索化
        PreThread(T);        //先序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1;    //处理遍历的最后一个结点
    }
}


//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T);   //先处理根节点
        if (T->ltag == 0)   // lchild不是前驱线索
            PreThread(T->lchild);
        PreThread(T->rchild);
    }
}


//后序线索化二叉树T
void CreatePostThread(ThreadTree T) {
    pre = NULL;    // pre初始为NULL
    if (T != NULL) {        // 非空二叉树才能线索化
        PostThread(T);        //后序线索化二叉树
        if (pre->rchild == NULL)
            pre->rtag = 1;//处理遍历的最后一个结点
    }
}


//后遍历二叉树，一边遍历一边线索化
void PostThread(ThreadTree T) {
    if (T != NULL) {
        PostThread(T->lchild);//后序遍历左子树
        PostThread(T->rchild);//后序遍历右子树
        visit(T);        //访问根节点
    }
}


