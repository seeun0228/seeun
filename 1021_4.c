// 실행되는 재귀호출 함수

#include <stdio.h>

int sum_num(int count, int sum);

int main(void){
    int val = sum_num(1, 0);
    printf("%d\n", val);

    return 0;
}

int sum_num(int count, int sum) {
    if (count == 1    1) {
        return sum;
    }
    else {
        sum += count;
        sum_num(count+1, sum);
    }
}