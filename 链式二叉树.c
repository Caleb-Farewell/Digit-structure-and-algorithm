#include <stdio.h>

//本程序用于二叉树
//采用链式存储的方式来存储二叉树

//二叉树的链式存储结构
typedef struct Binode
{
    int data;
    struct Binode *lchild, *rchild; //左右孩子指针
} Binode;

//三叉链表，即指向孩子，又指向双亲
typedef struct TriNode
{
    int data;
    struct TriNode *tlchild, *parent, *trchild;
} TriNode;

//主函数
