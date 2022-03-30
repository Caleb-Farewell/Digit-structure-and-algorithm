#include <stdio.h>
#include <stdlib.h>

//本代码用于二叉树的应用----复制二叉树

#define Status int
typedef struct Bitree
{
    char data;
    struct Bitree *lchild, *rchild;
} Bitree;

//复制二叉树
//如果是空树，递归结束
//否则，申请新结点空间，复制根结点
//递归复制左子树
//递归复制右子树

//递归复制一个新的二叉树
Status Copy(Bitree *t, Bitree **Nt)
{
    if (t == NULL) //如果为空树,返回0
    {
        *Nt = NULL;
        return 0;
    }
    else
    {
        *Nt = (Bitree *)malloc(sizeof(Bitree)); //创建一个新的结点，本函数的目的是另外重新建一个一模一样的二叉树
        (*Nt)->data = t->data;             //复制根结点
        Copy(t->lchild, &((*Nt)->lchild)); //递归复制左子树
        Copy(t->rchild, &((*Nt)->rchild)); //递归复制右子树
    }
}