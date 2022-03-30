#include <stdio.h>
#include <stdlib.h>

//本代码主要用于二叉树的层次遍历
//即采用队列--先进先出的方式执行
//层次遍历就是----从上到下，从左到右
#define Status int
#define MAXQSIZE 100 //最大队列长度
//二叉树的结构形式
typedef struct Bitree
{
    int data;
    struct Bitree *lchild, *rchild;
} Bitree;

//顺序队列的格式
typedef struct
{
    Bitree *base; //初始化的动态分配存储空间
    int front;    //队列头下标
    int rear;     //队列尾下标（指向队尾元素的下一个空间）
} SqQueue;

//顺序队列的初始化
void InitQueue(SqQueue *s)
{
    s->base = (Bitree *)malloc(sizeof(Bitree) * MAXQSIZE);
    if (s->base == NULL)
        printf("error malloc memory");
    else
        s->front = s->rear = 0;
}

//顺序队列的入队
void EnQueue(SqQueue *s, Bitree *q)
{
    if ((s->rear + 1) % MAXQSIZE == s->front)
        printf("enough"); //判断队列是否已满
    else
    {
        s->base[s->rear] = *q;
        s->rear = (s->rear + 1) % MAXQSIZE;
    }
}

//顺序队列出队
void deQueue(SqQueue *s, Bitree *dq)
{
    if (s->rear == s->front)
        printf("empty"); //判断队列是否为空
    else
    {
        *dq = s->base[s->front];
        s->front = (s->front + 1) % MAXQSIZE;
    }
}

//判断队列是否为空
Status QueueEmpty(SqQueue *s)
{
    if (s->rear == s->front)
        return 1;
    else
        return 0;
}

//二叉树层次遍历算法----队列实现
//从上到下---从左到右
void LevelOrder(Bitree *t)
{
    Bitree *q;
    SqQueue S;
    InitQueue(&S);               //初始化队列
    EnQueue(&S, t);              //头结点入队
    while (!QueueEmpty(&S)) //队列不为空则循环
    {
        deQueue(&S, &q); //队列出队，拿指针q去接收
        printf("%d\n", q->data);//访问二叉树数据
        if (q->lchild != NULL)
            EnQueue(&S, q->lchild);//有左孩子时，左孩子入队列
        if (q->rchild != NULL)
            EnQueue(&S, q->rchild);//有右孩子时，右孩子入队列
    }
}