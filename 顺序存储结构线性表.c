#include <stdio.h>
#include <stdlib.h>
#include <head.h>

int InitList_Sq(Sqlist *p)
{
    //为顺序表分配空间
    p->elem = (Polynomial *)malloc(sizeof(Polynomial) * maxsize);
    if (p->elem != NULL)
    {
        p->length = 0; //空表长度为0
    }
    else
        return OVERFLOW;
}

void DestroyList(Sqlist *dp)
{
    free(dp->elem); //释放内存以达到销毁
    dp = NULL;
}

void ClearList(Sqlist *cp)
{
    cp->length = 0; //将线性表的长度置为0
}
int GetLength(Sqlist *gp)
{
    return gp->length;
}
int IsEmpty(Sqlist *ip)
{
    if (ip->length == 0)
    {
        return 1;
    }
    return 0;
}

int GetElem(Sqlist *gp, int i, int h)
{
    if (i < 1 || i > gp->length)
        return ERROR;
    else
    {
        h = (gp->elem + i - 1)->e; //将第i个取值出来
        return h;
    }
}

//顺序表查找
int LocateElem(Sqlist *lp, float h)
{
    int i = 0;
    //在线性表中查找值为e的数据元素，并返回其序号
    for (i = 0; i < lp->length; i++)
    {
        if ((lp->elem + i)->p == h)
            return i + 1; //查找成功，返回序号
        else
            return 0;
    }
}

//顺序存储线性表的插入
int ListInsert_Sq(Sqlist *lq, int i, float g)
{
    int j = 0;
    if (i < 1 || i > lq->length + 1) //检测插入的i的位置是否合法
        return ERROR;
    else if (lq->length == maxsize)  //检查是否内存溢出
        return ERROR;
    else
    {
        for (j = lq->length - 1; j >= i - 1; j--) //这里的j表示下标,i是位序,第i个位置插入，则它的下标就是i-1，那么i-1也需要移动
        {
            (lq->elem + j + 1)->p = (lq->elem + j)->p;
        }
        (lq->elem + i - 1)->p = g;
        lq->length++;
        return OK;
    }
}

//顺序存储线性表的删除
int ListDelete_Sq(Sqlist *lq, int i)
{
    int j = 0;
    if (i < 1 || i > lq->length)
        return ERROR;
    else
    {
        for (j=i; j <=lq->length-1; j++)
        {
            (lq->elem+j-1)->p = (lq->elem+j)->p;
        }
        lq->length --;
        return OK;
    }
}

int main()
{
    int i;
    int e;
    float h, g;
    Sqlist L;                //L为线性表
    InitList_Sq(&L);         //构造一个空的顺序存储线性表L，并初始化
    DestroyList(&L);         //销毁一个线性表
    ClearList(&L);           //清空一个线性表
    GetLength(&L);           //求解线性表的长度
    IsEmpty(&L);             //判断线性表是否为空
    GetElem(&L, i, e);       //顺序表的取值
    LocateElem(&L, h);       //线性表查找
    ListInsert_Sq(&L, i, g); //线性表的插入
    ListDelete_Sq(&L, i);    //顺序表删除
    return 0;
}