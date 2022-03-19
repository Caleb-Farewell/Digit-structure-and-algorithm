#include <stdio.h>
#include <stdlib.h>

//本程序主要支持为双向链表

//双向链表的结构体定义，多了一个指针指向前驱
typedef struct DuLNode
{
    int data;
    struct DuLNode *prior, *next;
} DuLNode;

//给双向链表分配内存，并返回链表的头指针
DuLNode *mem()
{
    DuLNode *p;
    p = (DuLNode *)malloc(sizeof(DuLNode) * 10);
    return p;
}

//双向链表的查找
DuLNode *GetElemP_DuL(DuLNode *dp, int a)
{
    DuLNode *p;
    int i = 1;
    p = dp->next;
    while (p && i < a)
    {
        p = p->next;
        i++;
    }
    if (!p || i > a)
        printf("%s", "no exit");
    else
        return p;
}

//在带头结点的双向循环链表L中的第i个位置之前插入元素a
void ListInsert_DuL(DuLNode *p2, int i, int e)
{
    DuLNode *s, *p1;                        //这个结构体指针就是新插入的结点
    s = (DuLNode *)malloc(sizeof(DuLNode)); //给这个新的结构体分配内存
    p1 = GetElemP_DuL(p2, i);               //根据位置i在链表中查找第i个位置，并返回其地址
    if (!p1)
        return 0;
    else
    {
        s->data = e;
        s->prior = p1->prior;
        (p1->prior)->next = s;
        s->next = p1;
        p1->prior = s;
    }
}

//在带头结点的双向循环链表L删除第i个位置的结点
void ListDelete_DuL(DuLNode *p2, int i, int e)
{
    DuLNode *p1;
    p1 = GetElemP_DuL(p2, i);
    e = p1->data;
    if (!p1)
        return 0;
    else
    {
        (p1->prior)->next = p1->next;
        (p1->next)->prior = p1->prior;
        free(p1);
    }
}

//主函数
int main()
{
    DuLNode *La, *Lb;
    int i = 4, a = 10;
    La = mem(); //给双向链表分配内存
    // Lb = mem();
    ListInsert_DuL(La, i, a); //双向链表的插入（这里的La代表链表L的头指针）
    ListDelete_DuL(La, i, a); //双向链表的删除
    return 0;
}