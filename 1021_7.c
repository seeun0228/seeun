#include <stdio.h>

int main(void){
    int score[5];
    int i;
    int total = 0;
    double avg;
    int count; 

    count = (sizeof(score)/sizeof(score[0]));

    for (i=0; i<5; i++){
        scanf("%d", &score[i]);

    }

    for (i=0; i< count; i++){
        total += score[i]
    }

    avg = total /(double)count;
    for (i=0;)

}