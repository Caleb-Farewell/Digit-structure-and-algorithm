#include <stdio.h>

//该代码用于图的遍历---深度优先查找（近似于树的先根遍历）
//这里采用邻接矩阵的存储方式来实现----深度优先DFS--有回溯的思想，---因此需要考虑用递归的思路

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

// DFS(优先搜索遍历)
void DFS(AMGraph G, int v) // G代表图，v代表起始顶点
{
    int w = 0;
    int visited[MVNum] = 0;  //辅助矩阵，0代表没访问过，1代表访问过
    printf("%c", G.vexs[v]); //访问第v个顶点
    visited[v] = 1;
    for (w = 0; w < G.vexnum; w++) //对邻接矩阵的第v行进行遍历访问，查询每个列w
    {
        if (G.arcs[v][w] != MaxInt && !(visited[w])) //当邻接矩阵的元素不等于无穷大且，辅助矩阵不为1时
            DFS(G, w);                               // w是v的邻接点，如果w未访问，则递归调用DFS
    }
}