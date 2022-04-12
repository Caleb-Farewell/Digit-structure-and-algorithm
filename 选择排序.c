#include <stdio.h>

//在各种排序算法中，数据均采用顺序表的方式进行存储
#define MAXSIZE 100
typedef int KeyType;
typedef int InfoType;

//定义每个记录（数据元素）的结构
typedef struct
{
    KeyType key;         //关键字
    InfoType ohtherinfo; //其他数据项
} RedType;               // record type

//定义一个顺序表
typedef struct
{
    RedType r[MAXSIZE + 1]; //一般0位置存储哨兵
    int length;             //顺序表的长度
} SqList;

//简单选择排序
void SelectSort(SqList *k)
{
    int i, j = 0;
    int h = 0;
    RedType x;
    for (i = 1; i < k->length; i++)
    {
        h = i;
        for (j = i + 1; j <= k->length; j++)
        {
            if (k->r[j].key < k->r[h].key) //选择一个最小的
            {
                h = j;
            }
        }
        if (h != i)
        {
            x = k->r[i];
            k->r[i] = k->r[h];
            k->r[h] = x;
        }
    }
}

//堆排序
//建立堆的时候，从n/2处开始，即从最后一个非叶子结点开始依次进行堆的调整
//堆的调整
void HeapAdjust(elem R[], int s, int m)
{
    //已知R[s...m]中记录的关键字除R[s]之外均满足堆的定义
    //调整R[s]的关键字，使得R[s...m]成为一个大堆
    int rc = R[s];
    int j = 0;
    for (j = 2 * s; j <= m; j *= 2) //循环找到最大的
    {
        if (j < m && R[j] < R[j + 1]) //判断左右子树那边大
        {
            j++; //选择下一个大的边
        }
        if (rc >= R[j]) //说明rc已经是最大的了，就不需要改变了
            break;
        R[s] = R[j]; //将最大的上移
        s = j;       //由于j的上移了，因此需要继续找最大的来弥补补全
    }
    R[j] = rc; //这时的j是最小的位置，将rc插入
}

void Swap(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}

//堆排序
void Headsort(elem R[], int n)
{
    //对R[1]到R[n]进行堆排序
    int i = 0;
    for (i = n / 2; i >= 1; i--) //对每个非叶子结点开始进行堆调整，建立初始堆（因为一开始是乱序的，所以要先建立初始堆，即保证根节点最小或最大）
    {
        HeapAdjust(R, i, n); //建立初始堆
    }
    for (i = n; i > 1; i--) //进行n-1次排序
    {
        Swap(R[1], R[i]);        //根与最后一个元素进行交换(其实就是输出了根节点，然后将最后一个元素放到根节点上，重新进行一次堆的调整)
        HeapAdjust(R, 1, i - 1); //对R[1]到R[i-1]重新建堆
    }
}