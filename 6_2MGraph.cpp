// 邻接矩阵储存图
#define MaxVertexNum 100    //顶点数目的最大值
typedef struct {
    char Vex[MaxVertexNum];    //顶点表
    int Edge[MaxVertexNum][MaxVertexNum];    // 邻接矩阵，边表
    int vexnum, arcnum;    //图的当前顶点数和边数/弧数
}MGraph;


// 邻接矩阵储存带权图（网）
#define MaxVertexNum 100    //顶点数目的最大值
#define INFINITY 99999   //宏定义常量"无穷"
typedef char VertexType;    //顶点的数据类型
typedef int EdgeType;   //带权图中边上权值的数据类型
typedef struct {
    VertexType Vex[MaxVertexNum];    //顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 边的权
    int vexnum, arcnum;     //图的当前顶点数和弧数
}MGraph;


// 邻接表法（顺式+链式存储）
//"边/弧"
#define vertexType int


typedef struct ArcNode {
    int adjvex;    //边/弧指向哪个结点
    struct ArcNode* next;    // 指向下一条弧的指针
    // InfoType info;   //边权值
}ArcNode;

//"顶点"
typedef struct VNode {
    vertexType data;    //顶点信息
    ArcNode* first;     //第一条边/弧
}VNode,AdjList [MaxVertexNum] ;

//用邻接表存储的图
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;


