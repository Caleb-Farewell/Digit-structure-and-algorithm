#include <stdio.h>
#include <stdlib.h>

#define Status int
#define OK 1
typedef struct Bitree
{
    int data;
    struct Bitree *lchild, *rchild;
} Bitree;

//本代码主要用于遍历二叉树中的先序遍历、中序遍历和后序遍历

//先序遍历二叉树的操作定义
//若二叉树为空，则空操作，否则执行：
// 1.访问根结点
// 2.先序遍历左子树
// 3.先序遍历右子树

//中序遍历二叉树的操作定义
//若二叉树为空，则空操作，否则执行：
// 1.中序遍历左子树
// 2.访问根结点
// 3.中序遍历右子树

//后序遍历二叉树的操作定义：
//若二叉树为空，则空操作，否则执行：
// 1.后序遍历左子树
// 2.后序遍历右子树
// 3.访问跟结点

//访问结点
void visit(Bitree *T)
{
    printf("%d\n", T->data);
}

//先序遍历二叉树
Status PreOrderTraverse(Bitree *T)
{
    if (T == NULL) //空二叉树，访问结束
        return OK;
    else
    {
        visit(T);                    //访问根结点
        PreOrderTraverse(T->lchild); //递归遍历左子树
        PreOrderTraverse(T->rchild); //递归遍历右子树
    }
}

//主函数
int main()
{
    Bitree *T;
    T = (Bitree *)malloc(sizeof(Bitree));
    PreOrderTraverse(T);
} 