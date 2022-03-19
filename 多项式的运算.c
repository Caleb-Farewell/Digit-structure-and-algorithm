#include <stdio.h>
#include <stdlib.h>

//本程序主要用于降阶排序的多项式的运算（采用头、尾指针链表表示）

//多项式的表示 结构体
typedef struct PolyNode
{
    int coef;              //多项式的系数
    int expon;             //多项式的指数
    struct PolyNode *link; //下一个结构体的指针
} PolyNode;

//将数据整合成链表，通过尾插法插入到之前的链表中
void attach(int c, int e, PolyNode **pRear)
{
    PolyNode *p;
    p = (PolyNode *)malloc(sizeof(PolyNode));
    p->coef = c; //对新结点赋值
    p->expon = e;
    p->link = NULL;
    (*pRear)->link = p; //将上一个链表结点的指针域指向这一次开辟的结点
    *pRear = p;         //修改尾指针的位置
}

//读入多项式
PolyNode *ReadPoly()
{
    int N, c, e;
    PolyNode *p, *Rear, *t;
    p = (PolyNode *)malloc(sizeof(PolyNode)); //链表头空结点
    p->link = NULL;                           //初始化头结点的指针域
    Rear = p;                                 //给尾指针弄一个空结点让他指向，作为赋初值，也可以直接给尾指针设置为NULL（这里相当于充当链表的头结点指针）
    scanf_s("%d", &N);
    while (N--)
    {
        scanf_s("%d %d", &c, &e);
        attach(c, e, &Rear); //整合成链表，并用Rear表示为尾指针，方便后续插入，由于每次需要改变，因此要将指针的地址传入过去
    }
    t = p;       //准备释放之前初始化第一次的头结点  (p和Rear在初始化是均指向一开始分配的空结点，所以在第一次进入的attach出来的时候，头结点的指针域就存放了真正链表的头指针)
    p = p->link; //释放之前需要将头结点中存储的指针域即链表的头指针拿出来
    free(t);     //进行释放
    return p;
}

//多项式相加
PolyNode *Add(PolyNode *p1, PolyNode *p2)
{
    PolyNode *front, *rear, *tmp;
    int sum;
    front = (PolyNode *)malloc(sizeof(PolyNode)); //先设置一个空的结点
    front->link = NULL;                           //对初始结点的指针域设置为空，这里的front代表头指针
    rear = front;                                 //这里的rear代表尾指针，在初始化时域front指向同一个位置，方便再后续插入的时候将空结点的指针域指向首元结点
    while (p1 && p2)
    {
        if (p1->expon == p2->expon) //这里比较多项式的指数，从而达成多项式的运算
        {
            sum = p1->coef + p2->expon; //多项式系数的相加
            if (sum)                    //当多项式的系数不等于0时则插入到链表中去
            {
                attach(sum, p1->expon, &rear);
                p1 = p1->link;
                p2 = p2->link;
            }
        }
        else if (p1->expon > p2->expon)
        {
            attach(p1->coef, p1->expon, &rear);
            p1 = p1->link;
        }
        else
        {
            attach(p2->coef, p2->expon, &rear);
            p2 = p2->link;
        }
    }

    while (p1) //当有一个链表结束了，后面的就直接插入了（这里代表p1未结束）
    {
        attach(p1->coef, p1->expon, &rear);
        p1 = p1->link;
    }
    while (p2)
    {
        attach(p2->coef, p2->expon, &rear);
        p2 = p2->link;
    }
    rear->link = NULL;   //将所形成的链表的尾指针置成NULL
    tmp = front;         //设置临时结构体指针，用于后面释放空节点空间
    front = front->link; //将用尾指针rear设置好的链表头指针设置给front，使之成为链表头指针
    free(tmp);           //释放之前设置的空结点空间
    return front;
}

//多项式相乘
PolyNode *Mult(PolyNode *p1, PolyNode *p2)
{
    PolyNode *p, *Rear, *t, *t1, *t2;
    int e, c;
    t1 = p1, t2 = p2;
    p = (PolyNode *)malloc(sizeof(PolyNode));
    p->link = NULL;
    Rear = p;
    while (t2) //先用p1的第一项乘p2，得到p
    {
        attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link; //将p1往下走一个，因为前面已经乘完一组了
    while (t1)     //通过两次while循环实现多项式相乘(先乘一组，后面再乘然后做比较)
    {
        t2 = p2;  //将p2从头开始
        Rear = p; //这里的尾指针Rear从头开始，方便比较
        while (t2)
        {
            //一次只乘一个，分别从p1和p2中提取一个进行相乘
            c = t1->coef * t2->coef;                        //得到相乘后多项式的系数
            e = t1->expon + t2->expon;                      //得到相乘后多项式的指数
            while (Rear->link && ((Rear->link)->expon) > e) //这里是做循环，找到和之前第一次相乘的指数项小的地方插入，相同的地方进行合并
            {
                Rear = Rear->link;
            }
            if (Rear->link && ((Rear->link)->expon) == e) //这里是代表第一次相乘的链表非空，且指数项找到相同----进行合并
            {
                //判别相加的时候是否0，等于0则删除，不等于0则相加合并
                if ((Rear->link)->coef + c)
                {
                    (Rear->link)->coef += c; //不等于0相加
                }
                else
                {
                    t = Rear->link;
                    Rear->link = t->link; //指向后一位，并释放掉等于0的那一项
                    free(t);
                }
            }
            else //小则插入,插入则需要申请一个新的节点
            {
                t = (PolyNode *)malloc(sizeof(PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link; //循环进行下一次的操作
        }
        t1 = t1->link;
    }
    //在最初的时候建立的一个空节点，因此要把他删掉
    t2 = p;
    p = p->link;
    free(t2);
    return p;
}

//将多项式打印出来
void PrintPoly(PolyNode *p)
{
    int flag = 0;
    if (!p)
        printf("0 0\n");
    return;
    while (p)
    {
        if (!flag)
            flag = 1;
        else
        {
            printf(" ");
            printf("%d %d", p->coef, p->expon);
            p = p->link;
        }
    }
}
//主函数
int main()
{
    PolyNode *p1, *p2, *pp, *ps;
    p1 = ReadPoly();   //读入多项式1
    p2 = ReadPoly();   //读入多项式2
    pp = Mult(p1, p2); //多项式相乘
    PrintPoly(pp);     //输出多项式
    ps = Add(p1, p2);  //多项式相加
    PrintPoly(ps);     //输出多项式
    return 0;
}