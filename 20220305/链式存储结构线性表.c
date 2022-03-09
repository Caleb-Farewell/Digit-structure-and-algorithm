#include <stdio.h>
#include <stdlib.h>
//#include "head.h"
//#include "Project1/head.h"

//typedef struct Lnode //声明结点的类型和指向节点的指针类型
//{
//    float data;         //结点的数据域
//    struct Lnode *nest; //结点的指针域
//} Lnode, *LinkList;     //LinkList指向结构体Lnode的指针类型
//
//int main()
//{
//    LinkList L;  //定义了链表L
//   // LinkList p = &L;
//   // p->data = 2.0;
//   // printf("%f\n", p->data);
//}

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode;

//单链表的初始化：
//1.先生成新结点作为头结点，用头指针指L指向头结点
//2.将头结点的指针域置为空

Lnode *InitList_L(Lnode *p)
{
    p = (Lnode *)malloc(sizeof(Lnode) * 3); //已经开辟了一个空间给头结点，且结构体指针P指向了头结点
                                            //p[1].next = NULL;
    p->next = NULL;                         //将头结点的指针置为空
    return p;
}

//判断链表是否为空
void ListEmpty(Lnode *lp)
{
    if ((lp->next) != NULL)
        printf("%d\n", 3);
    else
        printf("%d\n", 0);
}

//单链表的销毁
void DestroyList_L(Lnode *dp)
{
    Lnode *op;
    // Lnode *ndp = dp[1].next;
    // int i = 1;
    while (dp)
    {
        op = dp;       //这里的dp在初始时就是头指针
        dp = dp->next; //将链表指针置为下一个结点的指针后在释放之前的空间
        free(op);      //销毁前一个结点
    }
}

//清空链表
void ClearList(Lnode *cp)
{
    Lnode *p, *q;
    p = cp->next; //因为头指针最后要置空所以要提出给定，保留头指针所在的位置
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    cp->next = NULL; //头结点指针域置为空
}

//求解单链表的长度
int ListLength_L(Lnode *lp)
{
    Lnode *p;
    int i = 0;
    p = lp->next; //p指向首元结点所在的位置
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//链表的查找，根据给定的i,找到第i个元素的数据值
void GetElem_L(Lnode *gp, int i, int *da)
{
    Lnode *p;
    int j;
    p = gp->next; //从头结点中找到首元结点的地址
    j = 1;        //首元结点找到就是1
    while (p && j < i)
    {
        p = p->next;
        j++;
    } 
    if (!p || j > i) //如果p是个空指针或者第i个元素不存在
        printf("%s", "no exist");
    else
        *da = p->data;
}

int main()
{
    Lnode L;
    int length;
    int i, e;
    Lnode *a = InitList_L(&L); //单链表初始化
    ListEmpty(a);              //判断链表是否为空
    DestroyList_L(a);          //销毁单链表
    ClearList(a);              //清空链表，并将头指针设置为空
    length = ListLength_L(a);  //求单链表的长度
    scanf_s("%d\n", &i);
    GetElem_L(a, i, &e); //链表的查找
    return 0;
}
