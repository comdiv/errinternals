#include "bonus.h"
#include "hack.h"

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

// public impls

void calculate_Bonus(Bonus* target) {

    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // ответ простой - делать не придется НИЧЕГО
    /* many calls before ...*/
    __calculate_by_baseStrategy(target);
    /* many calls after ...*/
}


// private impls

void __calculate_by_baseStrategy(Bonus *target) {
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // ответ простой - делать не придется НИЧЕГО
    target->ticketPerMen = __calculate_per_men(target);
    target->ticketPerFemale = __calculate_per_female(target);
}

int __calculate_per_men(Bonus* target) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // тут конечно все равно придется как-то детектить проблемы и заменять ИСКЛЮЧЕНИЯМИ
    if (target->actualMenCount == 0) {
        THROW(ERR_DIV_BY_ZERO);
    }
    return target->menQuote / target->actualMenCount;
}

int __calculate_per_female(Bonus* target) {
    if (target->actualFemaleCount == 0) {
        THROW(ERR_DIV_BY_ZERO);
    }
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // тут конечно все равно придется как-то детектить проблемы и заменять ИСКЛЮЧЕНИЯМИ
    return target->femaleQuote / target->actualFemaleCount;
}

