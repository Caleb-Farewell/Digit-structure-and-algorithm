#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *a;
} HuffmannCode;

int main()
{
    HuffmannCode *hc;
    hc = (HuffmannCode*)malloc(sizeof(HuffmannCode)*2);
    char *cd;
    cd = (char *)malloc(sizeof(char) * 2);
    cd[0] = 'h';
    cd[1] = 'e';
    hc[1].a = (char *)malloc(sizeof(char) * 2);
    strcpy(hc[1].a, cd);
    printf("%s", hc[1].a);
}
