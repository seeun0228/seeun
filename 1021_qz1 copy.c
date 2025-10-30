
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 36
#define HD 9999


int main(void) {

    double dist[360];
    int i, min_index =0;
    double min_value;

    srand(time(NULL));


    printf("360 라이다 거리값 입력\n");
    for (i=0; i< DATA_SIZE; i++){

        double random_cm = 10.0 +(double)rand() / (RAND_MAX / 90.0);
        dist[i] = random_cm;
        printf("%3d 거리 : %.2f cm\n", i, dist[i] );
    }
    min_value = dist[0];
    for (i=1; i< DATA_SIZE; i++){
        if (dist[i]<min_value) {
            min_value = dist[i];
            min_index =i;
        }

    }



    printf("\n[라이더 최소 거리 탐색 결과]\n");
    printf("가장 가까운 거리 : %.1f cm\n", min_value);
    printf("장애물 방향 : %d\n", min_index);


    return 0;

}

