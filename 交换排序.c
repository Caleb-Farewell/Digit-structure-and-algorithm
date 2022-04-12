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

//冒泡排序法
void bubble_sort(SqList *L)
{
    int i, j = 0;
    RedType x;
    for (i = 1; i <= (L->length) - 1; i++) // n个元素，则需要记录n-1趟
    {
        for (j = 1; j <= (L->length) - i; j++) //第m趟需要比较n-m次
        {
            if (L->r[j].key > L->r[j + 1].key)
            {
                x = L->r[j + 1];
                L->r[j + 1] = L->r[j];
                L->r[j] = x;
            }
        }
    }
}

//快速排序
int Partition(SqList *L, int low, int high)
{
    L->r[0] = L->r[low]; //先随机选取一个中心元素，放入0号位置，作为哨兵
    int pivotloc = L->r[low].key;
    while (low < high) //表明还未排序的顺序表元素大于1
    {
        while (low < high && (L->r[high].key >= pivotloc)) //判断右边的高位置是否比中心元素小
        {
            high--;
        }
        L->r[low] = L->r[high]; //小的话，就将前面low地址的位置给他
        while (low < high && (L->r[low].key <= pivotloc))
        {
            low++;
        }
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0]; //这个时候low=high
    return low;
}

//（初始的时候，low=1，high=L.length）
void QSort(SqList *L, int low, int high)
{
    int pivotloc = 0;
    if (low < high) //表明还未排序的顺序表元素大于1
    {
        //将顺序表L一分为二，pivotloc为排好的中心元素的位置
        pivotloc = Partition(L, low, high);
        //采用递归思想进行循环排序
        QSort(L, low, pivotloc - 1);  //对低子表进行递归排序
        QSort(L, pivotloc + 1, high); //对高子表进行递归排序
    }
}