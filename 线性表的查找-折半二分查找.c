#include <stdio.h>

typedef struct
{
    int key; //关键字域
} ElemType;

//顺序表结构类型定义
typedef struct
{
    ElemType *R; //表基地址
    int length;  //表长
} SSTable;       // Sequential Search Table

//折半查找---非递归
int Search_Bin(SSTable ST, int key)
{
    int low = 1;
    int high = ST.length; //二分查找的上下区间
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ST.R[mid].key == key)
            return mid;
        else if (ST.R[mid].key > key)
            high = mid - 1;
        else
            low = low + 1;
    }
    return 0;
}

//折半查找---递归
int Search_Bin_recursion(SSTable ST, int key, int low, int high)
{
    int mid = 0;
    if (low > high)
        return 0;
    mid = (low + high) / 2;
    if (ST.R[mid].key == key)
        return mid;
    else if (ST.R[mid].key > key)
    {
        high = mid - 1;
        Search_Bin_recursion(ST, key, low, high);
    }
    else
    {
        low = mid + 1;
        Search_Bin_recursion(ST, key, low, high);
    }
}
