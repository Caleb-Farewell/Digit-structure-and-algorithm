#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//多项式的顺序存储结构类型定义
#define maxsize 100 //线性表存储空间的初始分配量
typedef struct              //多项式非零项的定义
{
    float p; //非零项的系数
    int e;   //非零项的指数
} Polynomial;

typedef struct
{
    Polynomial *elem; //存储空间的基地址
    int length;       //多项式中当前项的个数
} Sqlist;             //多项式的顺序存储结构类型为Sqlist
