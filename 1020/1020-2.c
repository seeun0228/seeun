#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y;

    printf("실수 x 입력: ");
    scanf("%lf", &x);
    printf("실수 y 입력: ");
    scanf("%lf", &y);

    printf("\n[math.h 함수 예제]\n");
    printf("sqrt(x) = %.4f\n",sqrt(x));
    printf("pow(x,y) = %.4f\n", pow(x,y));
    printf("sqrt(X) %.4f\n", sqrt(x));

    return 0;

}