#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//该代码用于哈夫曼树结构的应用----哈夫曼编码的实现

//哈夫曼树结构体形式
typedef struct
{
    int weight;
    int parent, lch, rch;
} HuffmanTree;

//存放哈夫曼编码的字符串结构体
typedef struct
{
    char* ch;
} HuffmanCode;

//哈夫曼编码的实现
//左孩子记0，右孩子记1

void CreatHuffmanCode(HuffmanTree *HT, HuffmanCode *HC, int n)
{
    //从叶子到根节点逆向求每个字符的哈夫曼编码，存储在编码表HC中
    char *cd;
    int i = 1;
    int start = 0; //用于指向cd的空间，从后往前开始
    int f;
    //首先为编码表开辟空间
    HC = (HuffmanCode *)malloc(sizeof(HuffmanCode) * (n + 1)); //分配n个字符编码的头指针矢量(存放每个哈夫曼树叶子的编码)
    cd = (char *)malloc(sizeof(char) * n);                     //临时存储编码的动态数组空间，从后往前开始;(最多为n-1)
    cd[n - 1] = '\0';                                          //最后一位存放为字符串结束标志，用于后面将cd复制拷贝给HC[i];
    for (i = 1; i <= n; i++)                                   //因为哈夫曼树是从第1位开始存放的
    {
        start = n - 1;
        f = HT[i].parent;
        while (f) //从叶子到根节点追溯，当双亲结点==0时，则找完
        {
            --start;            //从后往前移动
            if (i == HT[f].lch) //当为左孩子时，将临时字符串数组置0
                cd[start] = '0';
            else
                cd[start] = '1';
        }
        HC[i].ch = (char*)malloc(sizeof(char)*(n-start));
        strcpy(HC[i].ch, cd);
    }
    free(cd);
}