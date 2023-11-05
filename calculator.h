//
// Created by entworacy on 11/5/23.
//

#ifndef FIFA_CARDLVUP_CALCULATOR_CALCULATOR_H
#define FIFA_CARDLVUP_CALCULATOR_CALCULATOR_H

#include <stdbool.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 게이지 100% 기준 강화 성공 확률
static int CARD_LVUP_PERCENTAGE[] = {
        100,
        81,
        64,
        50,
        26,
        15,
        7,
        4,
        2
};

void StartLevelUpCalc(unsigned int startCardLevel, unsigned int targetCardLevel, unsigned int boosterPercentage, unsigned int loopCount);


#endif //FIFA_CARDLVUP_CALCULATOR_CALCULATOR_H
