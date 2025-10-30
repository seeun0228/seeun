// 중첩 반복문을 사용한 별 출력

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i =0; i<5; i++)
    {
        for (j =5; j-i>0; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;

}

