#include <stdio.h>
#include <stdlib.h>

//本程序采用链式存储方式表示队列

#define MAXQSIZE 100 //最大队列长度

//链式存储队列的形式
typedef struct Qnode
{
    int data;
    struct Qnode *nest;
} Qnode;

//头尾指针
typedef struct
{
    struct Qnode *front; //队头指针（链表的头指针指向头结点）
    struct Qnode *rear;  //队尾指针
} LinkQueue;

//链队列的初始化（队头和队尾指针指向一起）
void InitQueue(LinkQueue *s)
{
    s->front = s->rear = (Qnode *)malloc(sizeof(Qnode *));
    if (!s->front)
        printf("overflow");
    else
        (s->front)->nest = NULL;
}

//销毁链队列，从队头结点开始，依次释放所有结点
void DestroyQueue(LinkQueue *s)
{
    Qnode *P;
    while (s->front)
    {
        P = (s->front)->nest;
        free(s->front);
        s->front = P;
    }
}

//链队列入列
void EnQueue(LinkQueue *s, int a)
{
    Qnode *p;
    p = (Qnode *)malloc(sizeof(Qnode));
    p->data = a;
    p->nest = NULL;
    (s->rear)->nest = p; //尾部插入
    s->rear = p;
}

//链队列出列
void DeQueue(LinkQueue *s, int *a)
{
    if (s->front != s->rear) //首先保证链队列为非空
    {
        Qnode *p;
        p = (s->front)->nest;
        *a = p->data;
        (s->front)->nest = p->nest;
        if (s->rear == p) //当删除的结点为最后一个尾结点
        {
            s->rear = s->front; //需要重置尾指针
        }
        free(p);
    }
}

//求链队列的队头元素
void GetHead(LinkQueue *s, int *a)
{
    if (s->front != s->rear)
        *a = ((s->front)->nest)->data;
    else
        printf("empty");
}

//主函数
int main()
{
    int e = 10;
    int a = 0;
    int b = 0;
    LinkQueue Q;
    InitQueue(&Q);    //链队列的初始化
    DestroyQueue(&Q); //销毁链队列
    EnQueue(&Q, e);   //链队列将元素e入列
    DeQueue(&Q, &a);  //链队列的出列
    GetHead(&Q, &b);  //求链队列的对头元素
    return 0;
}