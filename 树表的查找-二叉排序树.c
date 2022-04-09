#include <stdio.h>

//二叉树排序树的存储结构
typedef struct
{
    int key;       //关键字项
    int otherinfo; //其他数据域
} ElemType;

typedef struct BSTnode
{
    ElemType data;                   //数据域
    struct BSTnode *lchild, *rchild; //左右孩子指针
} BSTnode;

//二叉排序树的递归查找
BSTnode *SearchBST(BSTnode *T, int key)
{
    if ((!T) || (T->data.key == key))
        return T;
    else if (T->data.key > key)
        return SearchBST(T->lchild, key); //比根结点小，就在左子树找
    else
        return SearchBST(T->rchild, key);//比根节点大，就在右子树找
}