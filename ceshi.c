#include <stdio.h>
int main()
{
    int ht[5] = {7, 3, 5, 2, 2};
    int i, j = 1;
    int we = ht[1] + ht[2];
    int a, s1, s2 = 0;
    for (i = 0; i <= 4; i++)
    {
        for (j = i + 1; j <= 4; j++)
        {
            a = ht[i] + ht[j];
            if (a <= we)
            {
                we = a;
                s1 = i;
                s2 = j;
            }
        }
    }
    printf("%d %d\n", s1, s2);
    printf("%d\n", we);
}
