#include <stdio.h>

//由于栈本声就是线性表，因此有-顺序存储和链式存储两种方式
//本程序采用顺序存储的方式表示栈
#define MAXSIZE 100

typedef int Status; //使用Status来代替整型
typedef struct
{
    int *base;     //栈底指针
    int *top;      //栈顶指针
    int stacksize; //栈可用最大容量
} SqStack;

//栈的初始化
Status InitStack(SqStack *s)
{
    s->base = (int *)malloc(sizeof(int) * MAXSIZE);
    if (s->base != NULL)
    {
        s->top = s->base;
        s->stacksize = MAXSIZE;
        // printf("%p %p\n", s->base, s->top);
        return 1;
    }
    else
        return 0;
}

//判断栈是否为空，若栈顶的位置与栈底的位置相等，则表示为空
Status StackEmpty(SqStack *s)
{
    if (s->base == s->top)
        return 0; //代表为空栈
    else
        return 1; //代表为非空栈
}

//求解顺序栈的长度即，栈顶指针-减去栈底指针
Status StackLength(SqStack *s)
{
    return (s->top) - (s->base);
}

//销毁顺序栈，即释放栈底指针的空间，指针置为NULL，栈的大小为0
Status DestroyStack(SqStack *s)
{
    if (s->base)
    {
        free(s->base);
        s->stacksize = 0;
        s->top = s->base = NULL;
    }
    return 1;
}

//顺序栈的入栈,先判断是否满栈，然后利用指针对地址赋值后，栈顶指针加一
void Push(SqStack *s, int a)
{
    if ((s->top) - (s->base) == s->stacksize)
        printf("error");
    else
        *(s->top)++ = a;
}

//顺序栈的出栈，先判断是否为空栈（下溢），栈顶指针先减一在赋值
void Pop(SqStack *s, int *pa)
{
    if (StackEmpty)
        printf("error");
    else
        *pa = *(--s->top);
}

//主函数
int main()
{
    SqStack S;
    int e = 10;
    int a = 0;
    Status len;
    InitStack(&S);         //构造一个空栈，即初始化
                           // printf("%d", S.stacksize);
                           // printf("%p %p\n", S.base,S.top);
    StackEmpty(&S);        //判断栈是否为空
    len = StackLength(&S); //求顺序栈的长度
    DestroyStack(&S);      //销毁顺序栈
    Push(&S, e);           //顺序栈的入栈
    Pop(&S, &a);           //顺序栈的出栈
    return 0;
}