// 문자열 전용 입출력 함수 : gets, puts
// 빈칸을 포함한 문자열 입력

#include <stdio.h>

int main(void){
    char str[80];

    printf("문자열 입력 :"); //입력 안내 메시지 출력
    gets(str); // 빈칸을 포함한 문자열 입력
    puts("입력된 문자열 :"); // 배열에 저장된 문자열 출력
    puts(str);

    return 0;



}