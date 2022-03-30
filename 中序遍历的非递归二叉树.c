#include <stdio.h>
#include <stdlib.h>

//本代码主要用于非递归方法实现中序遍历二叉树
//主要思想是基于栈，即先进后出的思想

#define Status int
//二叉树的结构形式
typedef struct Bitree
{
    int data;
    struct Bitree *lchild, *rchild;
} Bitree;

//栈的结构形式
typedef struct StackNode
{
    struct Bitree *bz;
    struct StackNode *next;
} StackNode;

//初始化栈
void InitStack(StackNode **s)
{
    *s = NULL; //栈顶指针置为空指针
}

//判断栈是否为空
int StackEmpty(StackNode *s)
{
    if (s == NULL)
        return 0;
    else
        return 1;
}

//压榨
int Push(StackNode **s, Bitree *h)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->bz = h;
    p->next = *s;
    *s = p;
    return 1;
}

//出栈
int Pop(StackNode **s, Bitree **ph)
{
    StackNode *p;
    if (*s == NULL)
        return 1;
    else
    {
        *ph = (*s)->bz;
        p = *s;
        *s = (*s)->next;
        free(p);
    }
}

//采用非递归算法进行中序遍历算法
Status MidOrderTraverse(Bitree *T)
{
    StackNode *S;
    Bitree *p;
    Bitree *q;
    InitStack(&S); //初始化栈，即将栈顶指针置为空指针
    while (p || StackEmpty(S))
    {
        if (p)
        {
            Push(&S, p);   //当二叉树指针非空时，将访问的结点压入栈中
            p = p->lchild; //继续寻找左子树
        }
        else //当寻找的结点为空时，将之前压入栈的结点指针出栈
        {
            Pop(&S, &q);             //将之前的出栈，并赋值给q
            printf("%d\n", q->data); //打印出来
            p = q->rchild;           //然后访问其右子树
        }
    }
    return 1;
}

//采用非递归算法进行先序遍历算法
Status PreOrderTraverse(Bitree *T)
{
    Bitree *p;
    StackNode *S;
    Bitree *q;
    InitStack(&S);
    while (p || StcakEmpty(S))
    {
        if (p)
        {
            printf("%d\n", p->data);
            Push(&S, p);
            p = p->lchild;
        }
        else
        {
            Pop(&S, &q);
            p = q->rchild;
        }
    }
}