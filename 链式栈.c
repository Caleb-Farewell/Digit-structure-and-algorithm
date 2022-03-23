#include <stdio.h>
#include <stdlib.h>

//本代码主要用于链式存储的栈的表示和实现
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

//链栈的初始化，构造一个空栈
void InitStack(StackNode **s)
{
    *s = NULL; //栈顶指针置为空指针
}

//判断链栈是否为空
int StackEmpty(StackNode *s)
{
    if (s == NULL)
        return 0;
    else
        return 1;
}

//链栈的入栈
int Push(StackNode **s, int a)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode)); //生成新的链表的结点
    p->data = a;                                //放置新结点的数据域
    p->next = *s;                               //防止新结点的指针域，
    *s = p;                                     //移动栈顶指针（链表头指针）
    return 1;
}

//链栈的出栈
int Pop(StackNode **s, int *e)
{
    StackNode *p;
    if (*s == NULL) //首先判断是否为空栈
        printf("error");
    else
    {
        *e = (*s)->data;
        p = *s;
        *s = (*s)->next;
        free(p); //出栈后要及时记得释放空间
        return 1;
    }
}

//获取栈顶元素
int GetTop(StackNode *s)
{
    if (s != NULL)
        return s->data;
}

//主函数
int main()
{
    int e = 10;
    int a = 0;
    int d = 0;
    StackNode *S;  //链表的头指针，同时也表示链栈的栈顶指针
    InitStack(&S); //链栈的初始化
                   // printf("%d", S);
    StackEmpty(S); //判断链栈是否为空
    Push(&S, e);   //链栈的入栈
    Pop(&S, &a);   //链栈的出栈
    d = GetTop(S); //获取栈顶元素
    return 0;
}