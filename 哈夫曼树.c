#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//本代码主要用于实现哈夫曼树的构造以及算法实现

//采用顺序存储结构---构造一维结构数组

//结点类型定义
typedef struct
{
    int weigth;
    int parent, lch, rch;
} HTNode;

//查找权值最小的两个结点，并返回他们所在的序号
int Select(HTNode *ht, int k, int s1, int s2)
{
    int i, j = 1;
    int we = ht[1].weigth + ht[2].weigth;
    int a = 0;
    for (i = 1; i <= k; i++)
    {
        for (j = i + 1; j <= k; j++)
        {
            if (ht[i].parent == 0 && ht[j].parent == 0)
            {
                a = ht[i].weigth + ht[j].parent;
                if (a <= we)
                {
                    we = a;
                    s1 = i;
                    s2 = j;
                }
            }
        }
    }
}

//构造哈夫曼树
void CreatHuffmanTree(HTNode *HT, int n)
{
    int m = 0;
    int i = 0;
    int s1=0;
    int s2 = 0;
    if (n <= 1)
        return;
    else
    {
        m = 2 * n - 1;
        HT = (HTNode *)malloc(sizeof(HTNode) * (m + 1)); //构造一维结构体数组，这里0号单元未使用
        for (i = 1; i <= m; i++)                         //将2*n-1个元素的lch,rch,parent置为0
        {
            HT[i].parent = 0;
            HT[i].lch = 0;
            HT[i].rch = 0;
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%d\n", &(HT[i].weigth)); //输入前n个元素的weight的值
        }
    }

    //进行n-1次合并，依次产生n-1个新的结点HT[i],i=n+1,...,2n-1
    for (i = n + 1; i <= m; i++) //构造哈夫曼树
    {
        Select(HT, i - 1, s1, s2); //从HT[k],1<=k<=i-1中选择双亲域为0，且权值最小的结点，并返回他们在数组HT中的序号
        HT[s1].parent = i;         //设置权值相加最小的两个结点的双亲为现在构造新的结点k的序号
        HT[s2].parent = i;
        //设置新的结点的权重和儿子
        HT[i].weigth = HT[s1].weigth + HT[s2].weigth;
        HT[i].lch = s1;
        HT[i].rch = s2;
    }
}

//主函数
int main()
{
    int n = 15;
    HTNode *HT = NULL;
    CreatHuffmanTree(HT, n); //构造哈夫曼树---哈夫曼算法
    return 0;
}


