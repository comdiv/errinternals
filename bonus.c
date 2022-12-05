#include "bonus.h"
#include <errno.h>

void init_Bonus(int ticketCount, Bonus *target)
{
    Bonus tmp = {
        .totalBonusTickets = ticketCount,
        .menRate = FIXED_MEN_RATE,
        .menQuote = (int)((float)ticketCount * FIXED_MEN_RATE),
        .femaleQuote = ticketCount - (int)((float)ticketCount * FIXED_MEN_RATE),
        .actualMenCount = 0,
        .actualFemaleCount = 0,
        .ticketPerMen = BONUS_UNKNOWN,
        .ticketPerFemale = BONUS_UNKNOWN,
    };
    *target = tmp;
}

// private defs
int __calculate_per_men(Bonus* target);
int __calculate_per_female(Bonus* target);
void __calculate_by_baseStrategy(Bonus *target);

// public impl
void calculate_Bonus(Bonus* target) {
    /* many calls before ...*/
    __calculate_by_baseStrategy(target);
    /* many calls after ...*/
}


// private impl


void __calculate_by_baseStrategy(Bonus *target) {
    target->ticketPerMen = __calculate_per_men(target);
    target->ticketPerFemale = __calculate_per_female(target);
}

int __calculate_per_men(Bonus* target) {
    if(target->actualFemaleCount == 0) {
        errno = ERR_ARITH_ERROR;
        return BONUS_UNKNOWN;
    }
    return target->menQuote / target->actualMenCount;
}

int __calculate_per_female(Bonus* target) {
    if(target->actualFemaleCount == 0) {
        errno = ERR_ARITH_ERROR;
        return BONUS_UNKNOWN;
    }
    return target->femaleQuote / target->actualFemaleCount;
}

