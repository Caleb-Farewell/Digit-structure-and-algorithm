#include <stdio.h>
#include <stdlib.h>

//本程序主要对应循环链表

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode;


//给链表分配内存，并返回链表的头指针
Lnode *mem()
{
    Lnode *p;
    p = (Lnode *)malloc(sizeof(Lnode) * 10);
    return p;
}

//将带尾指针循环链表的合并
void Connect(Lnode *ta, Lnode *tb)
{
    Lnode *p;
    //这里假设ta和tb都是两个链表的尾指针
    p = ta->next;
    ta->next = (tb->next)->next;
    free(tb->next); 
    tb->next = p;
}

int main()
{
    Lnode *La,*Lb;
    La = mem(); //给链表分配内存
    Lb = mem();
    Connect(La, Lb); //循环链表的合并
    return 0;
}