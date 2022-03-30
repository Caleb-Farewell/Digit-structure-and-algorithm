#include <stdio.h>

//本代码用于二叉树的应用----计算二叉树结点总数

#define Status int
typedef struct Bitree
{
    char data;
    struct Bitree *lchild, *rchild;
} Bitree;

//如果是空树，则返回0
//否则，结点个数为左子树的结点个数+右子树的结点个数+1（根结点）

//二叉树结点总数
Status NodeCount(Bitree *t)
{
    if (t == NULL)
        return 0;
    else
    {
        return NodeCount(t->lchild) + NodeCount(t->rchild) + 1;
    }
}