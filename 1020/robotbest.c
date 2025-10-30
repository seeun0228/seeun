#include <stdio.h>

int main(void) {
    // 변수 선언: mass, torque, gear, radius, SF, margin
    double mass, torque, gear, radius, SF, margin;
    // 계산 결과를 위한 변수 선언 및 초기화
    double W, F_min, F_motor = 0.0;
    int whells;
    
    // 상수 선언
    const double g = 9.81; // 중력가속도 [m/s^2]
    const double c = 0.018; // 구름저항계수 - 일반적인 고무바퀴 & 아스팔트
    const double OPTIMAL_MARGIN_MAX = 1.3; // 오버스펙 판정을 위한 최대 마진 (30% 초과 금지)

    // 1. 고정 사양 입력 (생략 없이 원본 코드를 사용한다고 가정)

    // ... (고정 사양 입력 코드) ...
    printf("--- [ 로봇 기본 사양 입력 ] ---\n");
    printf("총 하중(kg) : ");
    if (scanf("%lf", &mass) != 1 || mass <= 0) return 1; 
    printf("구동 바퀴 수 : ");
    if (scanf("%d", &whells) != 1 || whells <= 0) return 1;
    printf("안전 계수 : ");
    if (scanf("%lf", &SF) != 1 || SF < 1.0) return 1;
    printf("설계마진(20%% == 1.2로 입력) : ");
    if (scanf("%lf", &margin) != 1 || margin < 1.0) return 1;

    // 2. 필요한 최소 견인력 (F_min) 계산
    W = mass * g;
    F_min = c * W * SF * margin;

    printf("\n>>> 필요한 최소 견인력: %.2f [N] <<<\n\n", F_min);

    // 3. 모터 사양 입력 및 판정 루프 (Do-While 사용)
    do {
        printf("--- [ 모터 및 바퀴 사양 입력 ] ---\n");
        printf("모터 정격 토크(N*m) : ");
        if (scanf("%lf", &torque) != 1 || torque <= 0) return 1;
        printf("감속비 : ");
        if (scanf("%lf", &gear) != 1 || gear <= 0) return 1;
        printf("바퀴 반지름(m) : ");
        if (scanf("%lf", &radius) != 1 || radius <= 0) return 1;

        // 모터가 낼 수 있는 견인력 (F_motor) 계산
        F_motor = (torque * gear / radius) * whells;
        
        // 실제 마진율 계산 (F_motor가 F_min보다 얼마나 큰지)
        double actual_margin_ratio = F_motor / F_min; 

        printf("\n모터가 낼 수 있는 견인력: %.2f [N]\n", F_motor);

        // 4. 판정 (최적 사양 로직 추가)
        if (F_motor >= F_min) {
            // 최소 요구 견인력은 만족한 경우
            if (actual_margin_ratio <= OPTIMAL_MARGIN_MAX) {
                // F_motor가 F_min보다 30% 이하로 큰 경우 (최적 범위)
                printf("✅ 판정: **최적 범위 만족!** (마진율: %.1f%%)\n", (actual_margin_ratio - 1.0) * 100.0);
                break; // 루프 종료
            } else {
                // F_motor가 F_min보다 30% 초과로 큰 경우 (오버 스펙)
                printf("⚠️ 판정: **오버 스펙** (필요 마진을 %.1f%% 초과)\n", (actual_margin_ratio - OPTIMAL_MARGIN_MAX) * 100.0);
                printf("          더 작은 모터 토크나 감속비를 시도하여 최적화하세요.\n");
            }
        } else {
            // 최소 요구 견인력에 미달한 경우
            printf("❌ 판정: **불만족** (더 큰 모터나 감속비가 필요합니다. 다시 입력하세요.)\n");
            // F_motor < F_min 이므로 do-while 조건에 의해 루프 반복
        }

    } while (F_motor < F_min || (F_motor / F_min > OPTIMAL_MARGIN_MAX)); 
    // 최소 견인력에 미달하거나(F_motor < F_min) 오버 스펙일 때(F_motor / F_min > 1.3) 루프를 계속함

    return 0; // 프로그램 정상 종료
}