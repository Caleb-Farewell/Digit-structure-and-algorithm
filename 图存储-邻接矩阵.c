#include <stdio.h>

//该代码用于表示图的存储---数组表示法---邻接矩阵
//邻接矩阵的存储表示：用两个数组分别存储顶点表和邻接矩阵

#define MVNum 100        //最大顶点数
typedef char VerTexType; //设顶点的数据类型位字符型
typedef int ArcType;     //假设边的权值类型位整型
#define MaxInt 32767     //最大权值,即无穷大

//邻接矩阵结构体
typedef struct
{
    VerTexType vexs[MVNum];     //顶点表(图中有多少个顶点)
    ArcType arcs[MVNum][MVNum]; //邻接矩阵（图中有多少个顶点，每个顶点有多少个邻接点）--也就是边
    int vexnum, arcnum;         //图的当前顶点数和边数

} AMGraph; // Adjacency Matrix Graph(邻接矩阵图)

//顶点表的查找
int Locate(AMGraph g, char v)
{
    int i = 0;
    for (i = 0; i < g.vexnum; i++)
    {
        if (v == g.vexs[i])
            return i;
    }
    return -1;
}

//创建无向图
//思想  1输入总顶点数和总边数
//     2依次输入点的信息存入顶点表中
//     3初始化邻接矩阵，使每个权值初始化为极大值
//     4构造邻接矩阵

int CreateUDN(AMGraph *G)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char v1, v2;
    int weight;
    scanf("%d %d", &(G->vexnum), &(G->arcnum)); //输入总顶点数和边数
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &((G->vexs)[i])); //输入顶点信息
    }
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            (G->arcs)[i][j] = MaxInt; //初始化邻接矩阵，边的权值均设置为极大值
        }
    }
    //构造邻接矩阵
    for (k = 0; k < G->arcnum; k++) //输入一条边所依附的顶点及边的权值
    {
        scanf("%c %c %d", &v1, &v2, &weight);
        i = Locate(*G, v1); //确定输入的顶点的位置下标，方便在邻接矩阵中输入权值
        j = Locate(*G, v2);
        (G->arcs)[i][j] = weight;
        (G->arcs)[j][i] = weight;  //因为是无向图，所以邻接矩阵是对称的
    }
    return 1;
}

//无向图就是没有权值，只有1和0，初始时，邻接矩阵都为0，构造的时候为1
//有向网就不是对称矩阵，只需要一次，不需要对阵化