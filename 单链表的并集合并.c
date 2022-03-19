#include <stdio.h>
#define length 3

//两个链表的合并去并集

//链表的结构体形式
typedef struct Lnode
{
    int a;
    struct Lnode *next;
} Lnode;

//给链表分配内存
Lnode *mem()
{
    Lnode *p;
    p = (Lnode *)malloc(sizeof(Lnode) * length);
    return p;
}

//链表的长度
int ListLength(Lnode *p)
{
    Lnode *lp;
    int i = 1;
    lp = p->next;
    while (lp)
    {
        i++;
        lp->next;
    }
    return i;
}

//链表的查找，给定位置i,找到其结点的数据
void GetElem(Lnode *p, int i, int *da)
{
    Lnode *gp;
    int j = 1;
    gp = p->next;
    while (gp && j < i)
    {
        gp = gp->next;
        j++;
    }
    if (!p || j > i)
        printf("%s\n", "no exist");
    else
        *da = gp->next;
}

//链表的查找，按照给定的数据h去链表中查找
Lnode *LocateElem(Lnode *p, int h)
{
    Lnode *lep;
    lep = p->next;
    int j = 1;
    while (lep && lep->a != h)
    {
        lep = lep->next;
        j++;
    }
    return lep; //若找到返回其所在的位置（即指针）
}

//链表的插入,在第i个结点前插入
void ListInsert(Lnode *p, int i, int data)
{
    Lnode *lip, *s;
    int j = 1;
    lip = p->next;
    while (lip && j < i - 1)
    {
        lip = lip->next;
        j++;
    }
    if (!p || j > i - 1)
        return 0;
    else
    {
        s = (Lnode *)malloc(sizeof(Lnode));
        s->next = lip->next;
        s->a = data;
        lip->next = s;
    }
}

//链表的并集合并
void unionList(Lnode *ap, Lnode *bp)
{
    int la_length, lb_length;
    int i = 1;
    int e;
    Lnode *p;
    la_length = ListLength(ap);      //获取链表La的长度
    lb_length = ListLength(bp);      //获取链表Lb的长度
    for (i = 1; i <= lb_length; i++) //在链表Lb中循环
    {
        GetElem(bp, i, &e);    //从链表Lb的第i个位置取出其数据e
        p = LocateElem(ap, e); //讲链表Lb的数据e于链表La做对比，若找到则返回地址
        if (!p)                //当返回地址为0即找不到时，进行插入
        {
            ListInsert(ap, ++la_length, e); //在链表La中插入元素e。
        }
    }
}

//用链表实现有序表的合并
void MergeList_L(Lnode *la, Lnode *lb, Lnode *lc)
{
    Lnode *pa, *pb, *pc;
    pa = la->next;
    pb = lb->next;
    pc = lc = pa; //用链表La的头结点作为链表Lc的头结点
    while (pa && pb)
    {
        if (pa->a <= pb->a)
        {
            pc->next = pa; //先将pc指针所指向的结点的指针域赋值
            pc = pa;       //然后pc指针移动至刚刚赋值的结点处，对他进行下一次操作
            pa = pa->next; //由于是对pa指针进行操作，因此pa指针需要移动至下一个结点处
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb; //插入剩余段
    free(lb);                //释放lb的头结点
}

int main()
{
    Lnode *la, *lb, *lc;
    la = mem(); //链表分配内存
    lb = mem();
    unionList(la, lb); //链表的并集合并
}