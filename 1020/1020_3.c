#include <stdio.h>

int main(void)
{
    int a =2;
    int i;

    for (printf("hi\n"); i < 3; i++)
    {
        a = a * 2;
    }
    printf("a : %d\n", a);

    return 0;
}