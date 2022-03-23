#include <stdio.h>
#include <stdlib.h>

//本程序采用顺序存储方式表示队列（考虑到了循环队列来解决假溢出）
#define MAXQSIZE 100 //最大队列长度

typedef struct
{
    int *base; //初始化的动态分配存储空间
    int front; //队列头下标
    int rear;  //队列尾下标
} SqQueue;

//顺序队列初始化
void InitQueue(SqQueue *s)
{
    s->base = (int *)malloc(sizeof(int) * MAXQSIZE); //分配数组空间
    if (s->base == NULL)
        printf("error");
    else
    {
        s->base = s->front = 0; //队列头下标、尾下标尾为0
    }
}

//求队列的长度
int QueueLength(SqQueue s)
{
    return ((s.rear - s.front + MAXQSIZE) % MAXQSIZE);
}

//顺序队列入队
void EnQueue(SqQueue *s, int a)
{
    //首先判断队列是否已满
    if ((s->rear + 1) % MAXQSIZE == s->front) //采用这个方式判断rear是否等于front
        printf("enough");
    else
    {
        s->base[s->rear] = a;               //新元素加入队尾
        s->rear = (s->rear + 1) % MAXQSIZE; //队尾下标加+1
    }
}

//顺序队列出队
void OutQueue(SqQueue *s, int *a)
{
    //先判断队列是否为空
    if (s->rear == s->front)
        printf("empty");
    else
    {
        *a = s->base[s->front];
        s->front = (s->front + 1) % MAXQSIZE;
    }
}

//主函数
int main()
{
    int e = 10;
    int a = 0;
    int length = 0;
    SqQueue Q;
    InitQueue(&Q);           //队列初始化
    length = QueueLength(Q); //求队列的长度
    EnQueue(&Q, e);          //顺序队列入队
    OutQueue(&Q, &a);        //顺序队列出队
    return 0;
}
