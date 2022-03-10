#include <stdio.h>
#include <stdlib.h>

struct student
{
    int data;
    int score;
};

//struct zhi
//{
//    struct student *st;
//};
//
//void mems(struct zhi *p)
//{
//    p->st = (struct student *)malloc(sizeof(struct student));
//    if (p != NULL)
//    {
//        (p->st)->data = 10;
//        (p->st)->score = 100;
//    }
//}
//
//void show(struct zhi *sp)
//{
//    printf("%d %d\n", (sp->st)->data,(sp->st)->score);
//}
//
//int main()
//{
//    struct zhi S;
//    mems(&S);
//    show(&S);
//    // printf("%d %d\n",S.data,S.score);
//}


//两种方法（遇到的bug）
struct student* mems(struct student *p)
{
    p = (struct student *)malloc(sizeof(struct student));
    p->data = 10;
    p->score = 100;
    return p;
};

int main()
{
    struct student *S;
    S = mems(S);
    printf("%d %d\n", S->data, S->score);
}