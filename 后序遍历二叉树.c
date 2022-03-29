#include <stdio.h>
#include <stdlib.h>

//本代码主要用于遍历二叉树中的先序遍历、中序遍历和后序遍历
#define Status int
#define OK 1
typedef struct Bitree
{
    int data;
    struct Bitree *lchild, *rchild;
} Bitree;

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
//中序序遍历二叉树
Status LadOrderTraverse(Bitree *T)
{
    if (T == NULL) //空二叉树
        return OK;
    else
    {
        LaOrderTraverse(T->lchild); //递归遍历左子树
        LadOrderTraverse(T->rchild);//递归遍历右子树
        visit(T);//访问根结点
    }
}

//主函数
int main()
{
    Bitree *T;
    T = (Bitree *)malloc(sizeof(Bitree));
    LaOrderTraverse(T);
}