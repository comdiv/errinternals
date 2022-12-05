#include "bonus.h"

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

int __calculate_per_men(Bonus* target);
int __calculate_per_female(Bonus* target);

void calculate_Bonus(Bonus* target) {
    /* many calls before ...*/
    __calculate_by_baseStrategy(target);
    /* many calls after ...*/
}

int __calculate_by_baseStrategy(Bonus *target) {
    target->ticketPerMen = __calculate_per_men(target);
    target->ticketPerFemale = __calculate_per_female(target);
}

int __calculate_per_men(Bonus* target) {
    return target->menQuote / target->actualMenCount;
}

int __calculate_per_female(Bonus* target) {
    return target->femaleQuote / target->actualFemaleCount;
}

