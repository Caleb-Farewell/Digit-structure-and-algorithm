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
    p = (Lnode *)malloc(sizeof(Lnode) * 10); //已经开辟了一个空间给头结点，且结构体指针P指向了头结点
                                             //p[1].next = NULL;
    p->next = NULL;                          //将头结点的指针置为空
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

//按值查找并返回其在链表中的地址。
Lnode *LocateElem_L(Lnode *Lep, int h)
{
    Lnode *p;
    int j = 1;
    p = Lep->next;
    while (p && p->data != h)
    {
        p = p->next;
        j++;
    }
    return p;
    // if (p)
    //     return j;  //用来返回其所在的序号
}

//链表的插入，第i个元素前插入数据元素e
void ListInsert_L(Lnode *lip, int i, int e)
{
    int j = 0;
    Lnode *p = lip;
    Lnode *s;
    while (p && j < i - 1)
    {
        p = p->next; //寻找第i-1个结点，p指向i-1结点
        j++;
    }
    if (!p || j > i - 1) //如果查找的位置大于表长,则循环之后出来的p是NULL空指针，或小于1，则插入位置非法
        return 0;
    else
    {
        s = (Lnode *)malloc(sizeof(Lnode));
        s->next = p->next;
        s->data = e;
        p->next = s;
    }
}

//链表的删除，将第i个元素删除
void ListDelete_L(Lnode *ldp, int i, int e)
{
    Lnode *p = ldp->next;
    Lnode *q;
    int j = 1;
    while (p && j < i - 1) //寻找第i个结点，并令p指向第i-1个结点
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return 0;
    else
    {
        q = p->next;               //临时保存被删除结点的地址以备释放
        p->next = (p->next)->next; //改变删除结点的前驱结点的指针域指向第i+1的结点地址
        e = (p->next)->data;       //保留删除结点的数据域
        free(q);                   //释放删除结点的空间
    }
}

//链表头插法 该算法的时间复杂度为o(n)
Lnode *CreatList_H(Lnode *clp, int n)
{
    int i;
    Lnode *p;
    clp = (Lnode *)malloc(sizeof(Lnode)); //先建立一个带头结点的单链表
    clp->next = NULL;                     //链表的最后一位的指针域为空
    for (i = n; i > 0; i--)
    {
        p = (Lnode *)malloc(sizeof(Lnode)); //生成新的节点，从后插入，即abcdef,则按照fedcba的顺序插入
        scanf_s("%d\n", &(p->data));        //输入节点的数值域
        p->next = clp->next;                //将头节点的指针赋值给新的节点指针
        clp->next = p;                      //将新的节点的地址赋值给头结点指针
    }
    return clp;
}

//头插法，正位序输入n个元素的值，建立带表头节点的单链表
Lnode *CreatList_R(Lnode *clp, int n)
{
    int i;
    Lnode *L;
    Lnode *r;
    clp = (Lnode *)malloc(sizeof(Lnode));
    clp->next = NULL;
    r = clp; //尾指针指向头结点
    for (i = 0; i < n; i++)
    {
        L = (Lnode *)malloc(sizeof(Lnode)); //生成新的结点，输入元素值
        L->next = NULL;
        scanf_s("%d\n", &(L->data));
        r->next = L; //将新建节点的地址赋值给前一个结点的指针
        r = L;       //将尾指针往后移
    }
}

int main()
{
    Lnode L;
    int n = 10; //人为给定
    Lnode *gp;
    Lnode *ldp;
    int length;
    int i, e, h;
    Lnode *a = InitList_L(&L); //单链表初始化
    ListEmpty(a);              //判断链表是否为空
    DestroyList_L(a);          //销毁单链表
    ClearList(a);              //清空链表，并将头指针设置为空
    length = ListLength_L(a);  //求单链表的长度
    scanf_s("%d\n", &i);
    GetElem_L(a, i, &e); //链表的查找
    scanf_s("%d\n", &h);
    ldp = LocateElem_L(a, h); //给定值在链表查找，返回其在链表中的地址
    ListInsert_L(a, i, h);    //在链表中的第i个元素之前插入数据元素e
    ListDelete_L(a, i, e);    //将链表中的第i个元素删除
                              //头插法
    gp = CreatList_H(&L, n);  //头插法
    gp = CreatList_R(&L, n);  //尾插法

    return 0;
}
