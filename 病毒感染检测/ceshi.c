#include <stdio.h>
#include <string.h>

// int main()
//{
//     char a[] = {"abcd"};
//     char b[] = {"cdef"};
//     strcat(b, a); //字符串的拷贝
//     int len = strlen(b);//计算字符串的长度，直接调用函数
//     printf("%s %d\n", b, len);
// }

int main()
{
    char name[] = {"Chinanet"}, destin[20] = {};
    strncpy(destin, name, 3);
    printf("%s\n", destin);
}