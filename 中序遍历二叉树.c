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

//中序遍历二叉树的操作定义
//若二叉树为空，则空操作，否则执行：
// 1.中序遍历左子树
// 2.访问根结点
// 3.中序遍历右子树

//访问结点
void visit(Bitree *T)
{
    printf("%d\n", T->data);
}
//中序序遍历二叉树
Status MidOrderTraverse(Bitree *T)
{
    if (T == NULL) //空二叉树
        return OK;
    else
    {
        MidOrderTraverse(T->lchild); //递归遍历左子树
        visit(T);                    //访问根节点
        MidOrderTraverse(T->rchild); //递归遍历右子树
    }
}

//主函数
int main()
{
    Bitree *T;
    T = (Bitree *)malloc(sizeof(Bitree));
    MidOrderTraverse(T);
}