#include <stdio.h>

//本代码用于二叉树的应用----计算二叉树的深度

#define Status int
typedef struct Bitree
{
    char data;
    struct Bitree *lchild, *rchild;
} Bitree;

//如果是空树，则返回0
//否则，递归计算左子树的深度计为m,递归计算右子树的深度为n，
//二叉树的深度则为m与n的较大者加1

//计算二叉树的深度
Status Depth(Bitree *t)
{
    int m = 0;
    int n = 0;
    if (t == NULL)
    {
        return 0; //如果是空树，则返回0
    }
    else
    {
        m = Depth(t->lchild);//递归计算左子树
        n = Depth(t->rchild);//递归计算右子树
        return (m>n)?(m+1):(n+1);
    }
}