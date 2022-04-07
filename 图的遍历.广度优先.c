#include <stdio.h>
#include <stdlib.h>

//该代码用于图的遍历---广度优先查找
//这里采用邻接表的存储方式来实现----广度优先BFS--像树的层次遍历  ---采用队列实现，--先进先出

#define MVNum 100        //最大顶点数
typedef char VerTexType; //设顶点的数据类型位字符型
typedef int ArcType;     //假设边的权值类型位整型
typedef int OtherInfo;
#define MAXQSIZE 100 //最大队列长度
//图的邻接表存储表示

//顶点的结点结构
typedef struct VNode
{
    VerTexType data;     //顶点信息
    ArcNode *firstarc;   //指向第一条依附该顶点的边的指针
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
} Graph;

//顺序队列的格式
typedef struct
{
    int *base;
    int front;
    int rear;
} SqQueue;

//顺序队列初始化
void InitQueue(SqQueue *s)
{
    s->base = (int *)malloc(sizeof(int) * MAXQSIZE);
    if (s->base == NULL)
        printf("error malloc memory");
    else
        s->front = s->rear = 0;
}

//顺序队列入队
void EnQueue(SqQueue *s, int v)
{
    if ((s->rear + 1) % MAXQSIZE == s->front)
        printf("enough");
    else
    {
        s->base[s->rear] = v;
        s->rear = (s->rear + 1) % MAXQSIZE;
    }
}

//顺序队列出队
void deQueue(SqQueue *s, int *u)
{
    if (s->rear == s->front)
        printf("empty");
    else
    {
        *u = s->base[s->front];
        s->front = (s->front + 1) % MAXQSIZE;
    }
}

//判断队列是否为空
int QueueEmpty(SqQueue *s)
{
    if (s->rear == s->front)
        return 1;
    else
        return 0;
}

//查找第一个邻接点
// int FirstAdjVex(Graph g, int u)
//{
//    ArcNode *p1;
//    if (g.vertices[u].firstarc == NULL)
//    {
//        return 0;
//    }
//    else
//    {
//        p1 = (g.vertices[u]).firstarc;
//        u = p1->adjvex;
//        return u;
//    }
//}

//查找下一个邻接点
int NextAdjVex(ArcNode **p, int w)
{
    if (*p)
    {
        *p = (*p)->nextarc;
        w = (*p)->adjvex;
        return w;
    }
}

//图的广度优先遍历---类似于树的层次遍历，采用队列的方式进行
void BFS(Graph *G, int v)
{
    int u = 0;
    int w = 0;
    SqQueue *Q = NULL;
    ArcNode *p1 = NULL;
    int visited[MVNum] = 0;            //辅助矩阵，0代表没访问过，1代表访问过
    printf("%c", G->vertices[v].data); //访问初始第v个结点
    visited[v] = 1;
    InitQueue(Q);          //辅助队列初始化，置空；
    EnQueue(Q, v);         //第v个结点入队
    while (!QueueEmpty(Q)) //判断队列是否为空
    {
        deQueue(Q, &u); //队列对头元素出队
        p1 = (G->vertices[u].firstarc);
        //队列u的每个邻接点入队
        for (w = p1->adjvex; w >= 0; w = NextAdjVex(&p1, w))
        {
            if (!visited[w])
            {
                printf("%c", G->vertices[w].data); //访问
                visited[w] = 1;
                EnQueue(Q, w); // w入队;
            }
        }
    }
}