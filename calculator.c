//
// Created by entworacy on 11/5/23.
//

#include "calculator.h"

void StartLevelUpCalc(unsigned int startCardLevel, unsigned int targetCardLevel, unsigned int boosterPercentage, unsigned int loopCount) {

    srand((unsigned int)time(NULL));
    if(startCardLevel > targetCardLevel) {
        printf("조건 문제: startCardLevel > targetCardLevel");
        return;
    } else if(startCardLevel < 1 || targetCardLevel < 1 || targetCardLevel - startCardLevel <= 0) {
        printf("조건 문제: 강화 기본조건");
        return;
    }

    unsigned int loopLevelUpCount = targetCardLevel - startCardLevel;
    unsigned int runCount = 100;
    char* csv_result = (char*) malloc(100000);
    strcpy(csv_result, "시행");

    for(unsigned int i = 0; i < loopLevelUpCount; i++) {
        // i번째 강화
        char DES[30];
        sprintf( DES, ",%d카 -> %d카", startCardLevel + i,  startCardLevel + i + 1);
        strcat(csv_result, DES);
        int levelUpPercentage = (CARD_LVUP_PERCENTAGE[i] * boosterPercentage) / 100;
        printf("[INFO] %d카 --> %d카 강화 성공확률 (풀게이지 확률 %d%%): ", startCardLevel + i, startCardLevel + i + 1, CARD_LVUP_PERCENTAGE[i]);
        printf("%d%%\n", levelUpPercentage);
    }

    int lvSucArr[10] = {0,};
    for(int i = 0; i < loopCount; i++) {
        printf("\n%d번 시도하기\n", runCount);
        for(int j = 0; j < runCount; j++) {
            for(int k = 0; k < loopLevelUpCount; k++) {
                targetCardLevel = k + 2;

                float levelUpPercentage = (CARD_LVUP_PERCENTAGE[k] * boosterPercentage) / 100;
                int randomicNumber = rand() % 100;
                if(randomicNumber < levelUpPercentage) {
                    lvSucArr[k]++;
                }
            }
        }
        strcat(csv_result, "\n");
        char buffer[10];
        sprintf(buffer,"%d번", runCount);
        strcat(csv_result, buffer);

        for(int j = 0; j < targetCardLevel - 1; j++) {
            printf("%d카 -> %d카: %d (%5.2lf%%), ", j+1, j+2, lvSucArr[j], 100. *  lvSucArr[j] / runCount );
            strcat(csv_result, ",");
            memset(buffer, '\0', 10);
            sprintf(buffer, "%5.2lf%%", 100. *  lvSucArr[j] / runCount );
            strcat(csv_result, buffer);
        }
        memset(lvSucArr, 0, sizeof(int) * 10);
        runCount += 100;
    }

    printf("\n파일 오픈중...\n");
    FILE *file = fopen("result.csv", "w");
    printf("쓰기중...\n");
    fprintf(file, "%s", csv_result);
    fclose(file);
    printf("쓰기완료");
    free(csv_result);
}