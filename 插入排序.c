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

//直接插入排序
void InsertSort(SqList *L)
{
    int i, j = 0;
    for (i = 2; i <= L->length; i++) //第1个元素已经存放了数据，
    {
        if (L->r[i].key < L->r[i - 1].key) //当要插入的元素比最后一个小的时候，则需要插入，否则直接放在表的后一位不动
        {
            L->r[0] = L->r[i]; //设置哨兵模式
            for (j = i - 1; (L->r[0].key) < (L->r[j].key); j--)
            {
                L->r[j + 1] = L->r[j]; //往后移位
            }
            L->r[j + 1] = L->r[0]; //插入到正确的位置
        }
    }
}

//折半插入排序
void BInsertSort(SqList *L)
{
    int i, j = 0;
    int low, high, mid = 1;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i].key < L->r[i - 1].key)
        {
            L->r[0] = L->r[i];
            low = 1;
            high = i - 1;
            while (low <= high) //二分查找
            {
                mid = (low + high) / 2;
                if (L->r[0].key < L->r[mid].key)
                    high = mid - 1;
                else
                    low = mid + 1;
            } //循环结束，high+1的即为插入位置
            for (j = i - 1; j >= high + 1; j--)
            {
                L->r[j + 1] = L->r[j];
            }
            L->r[high + 1] = L->r[0];
        }
    }
}

//希尔排序
void ShellInsert(SqList **L, int dk)
{
    //对顺序表L进行一趟增量为dk的shell排序，dk为步长因子
    int i, j = 0;
    for (i = dk + 1; i <= (*L)->length; i++)
    {
        if ((*L)->r[i].key < (*L)->r[i - dk].key)
        {
            (*L)->r[0] = (*L)->r[i];
            for (j = i - dk; j > 0 && ((*L)->r[0].key < (*L)->r[j].key); j = j - dk)
            {
                (*L)->r[j + dk] = (*L)->r[j];
            }
            (*L)->r[j + dk] = (*L)->r[0];
        }
    }
}

void ShellSort(SqList *L, int dlta[], int t)
{
    //按增量序列dlta[0..t-1]对顺序表L作希尔排序
    // dlta[]中的值必须是质数，增量序列必须是递减的，最后一个必须是1
    int k = 0;
    for (k = 0; k < t; k++)
    {
        ShellInsert(&(*L), dlta[k]); //每次从dlta[]数组中取出数;
    }
}
