#include <stdio.h>
#include "calculator.h"

int main() {
    int startLevel;
    int endLevel;
    int booster;
    int loopCount;
    printf("시작 레벨 입력(1부터): ");
    scanf("%d", &startLevel);
    printf("끝나는 레벨 입력: ");
    scanf("%d", &endLevel);
    printf("강화부스터 몇퍼인지(백분율로입력): ");
    scanf("%d", &booster);
    printf("반복 횟수 입력: ");
    scanf("%d", &loopCount);
    StartLevelUpCalc(startLevel, endLevel, booster, loopCount);
    return 0;
}
