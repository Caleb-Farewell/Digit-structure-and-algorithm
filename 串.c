#include <stdio.h>

//本程序主要用于串的顺序、链式存储

//串的顺序存储结构
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN + 1];
    int length;
} SString;

//串的链式存储结构
#define CHUNKSIZE 65
typedef struct Chunk
{
    char CH[CHUNKSIZE];
    struct Chunk *next;
} Chunk;

typedef struct
{
    Chunk *head, *tail; //串的头尾指针
    int curlen;
} Lstring;

// BF算法实现顺序串的模式匹配
int Index_BF(SString s, SString t)
{
    //这里的s代表主串、t代表子串，找到主串中是否含有子串，找到则返回子串第一个字母在主串中的位置
    int i = 1; //默认下标从1开始，即第0个里面存的是空
    int j = 1;
    //这里s和t要同时进位来进行对比
    while (i <= s.length && j <= t.length)
    {
        if (s.ch[i] == t.ch[j])
        {
            i++;
            j++;
        }
        else if (s.ch[i] != t.ch[j])
        {
            i = i - j + 2; //回溯后开始重新下一次的匹配 i-(j-1)+1
            j = 1;
        }
    }
    //当j一直移位，一直到大于字串的长度的时候说明已经匹配成功了
    if (j > t.length)
        //这里的t.length就相当于这一次的i移动了多少位，那么减去之后就是i最开始移动的位置(因为i在循环完后又移动了一次，因此不需要在+1)
        return i - t.length; //返回匹配的第一个字符的下标
    else
        return 0;
}

// KMP算法的核心---next[j]---针对模式串而言（t字串）
//默认数组下标0不存放，从下标1开始
void get_next(SString t, int *next)
{
    int i = 1;   //指向后缀的末尾位置
    int j = 0;   //指向前缀的末尾位置
    next[1] = 0; // next的第一个肯定是0
    while (i < t.length)
    {
        if (j == 0 || t.ch[i] == t.ch[j]) // t.ch[i]表示后缀的单个字符，t.ch[j]表示前缀的单个字符
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j]; //若字符不想同，j回溯
        }
    }
}

//本代码核心---KMP算法
int Index_KMP(SString s, SString t, int next[])
{
    int i = 1; //默认数组下标从1开始，即0号位不存放任何东西
    int j = 1;
    while (i <= s.length && j <= t.length)
    {
        if (s.ch[i] == t.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]; // KMP算法的核心，计算next[j]
        }
    }
    if (j > t.length)
        return i - t.length;
    else
        return 0;
}

//
//主函数
int main()
{
    SString S, T;
    int a = 0;
    int next[MAXLEN + 1];
    get_next(T, next);
    a = Index_BF(S, T);        //顺序串的模式匹配算法-BF;
    a = Index_KMP(S, T, next); //顺序串的模式匹配算法-KMP;
    return 0;
}
