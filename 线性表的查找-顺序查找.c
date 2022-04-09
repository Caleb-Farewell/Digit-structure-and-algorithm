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

//顺序查找
int Search_Seq(SSTable ST, int key)
{
    int i = 0;
    for (i = ST.length; i >= 1; i--) //从后往前找，数组下标为0的位置不存放数据
    {
        if (ST.R[i].key == key)
            return i;
    }
    return 0;
}

//对程序改进  --增加哨兵，即将要查找的数据放在在顺序表的表头下标为0的位置
//减少了一次if对比，缩短一半的时间
int Search_Seq_modify(SSTable ST, int key)
{
    int i = 0;
    ST.R[i].key = key; //设置监视哨，即哨兵
    for (i = ST.length; (ST.R[i].key)!=key; i--);
    return i;
}