#include <stdio.h>
#include <stdlib.h>

//该代码用于表示图的存储---链式表示法---邻接表

#define MVNum 100        //最大顶点数
typedef char VerTexType; //设顶点的数据类型位字符型
typedef int ArcType;     //假设边的权值类型位整型
typedef int OtherInfo;
//图的邻接表存储表示

//顶点的结点结构
typedef struct VNode
{
    VerTexType data;     //顶点信息
    ArcType *firstarc;   //指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum]; //定义了一个以结构体为类型的数组  ---相对于 AdjList v;

//边的结点结构
typedef struct ArcNode
{
    int adjvex;              //该边所指向的顶点的位置
    struct ArcNode *nextarc; //指向下一条边的指针
    OtherInfo info;          //和边相关的信息
} ArcNode;

//图的结构定义
typedef struct
{
    AdjList vertices;   //定义一个结构体VNode的数组
    int vexnum, arcnum; //图的当前顶点数和边数
} ALGraph;

//邻接表的算法思想
// 1输入总顶点数和总边数
// 2建立顶点表---a.依次输入点的信息存入顶点表中；b.使每个表头结点的指针域初始化为NULL
// 3创建邻接表---a.依次输入每条边依附的两个顶点；b.确定两个定的顶点的序号i和j建立边结点；c.将此边结点分别插入到vi,vj对应的两个边链表的头部

//查找
int Locate(ALGraph g, char v)
{
    int i = 0;
    for (i = 0; i < g.vexnum; i++)
    {
        if (v == (g.vertices[i]).data)
            return i;
    }
    return -1;
}

//采用邻接表示法，创建无向图G
int CreateUDG(ALGraph *G)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char v1, v2;
    ArcNode *p1, *p2;
    scanf("%d %d", &(G->vexnum), &(G->arcnum)); //输入总顶点数，总边数
    for (i = 0; i < G->vexnum; i++)             //构造表头结点表
    {
        scanf("%c", &((G->vertices)[i]).data); //输入顶点值
        (G->vertices)[i].firstarc = NULL;      //初始化表头结点的指针域
    }
    //构造邻接表
    for (k = 0; k < G->arcnum; k++)
    {
        scanf("%c %c", &v1, &v2);
        i = Locate(*G, v1); //查找位置
        j = Locate(*G, v2);
        p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = i;
        p1->nextarc = (G->vertices)[j].firstarc; //头插法
        p2 = (ArcNode *)malloc(sizeof(ArcNode)); //如果是有向图，则没有p2
        p2->adjvex = j;
        p2->nextarc = (G->vertices)[i].firstarc;
        (G->vertices)[i].firstarc = p2; //串联链表
        (G->vertices)[j].firstarc = p1;
    }
    return 1;
}