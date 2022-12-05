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

int __calculate_per_men(Bonus* target, int* err);
int __calculate_per_female(Bonus* target, int* err);
void __calculate_by_baseStrategy(Bonus *target, int* err);

// public impls

void calculate_Bonus(Bonus* target, int* err) {
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // ANSWER: just keep simple sygnature with resending pointer to optional error 
    /* many calls before ...*/
    __calculate_by_baseStrategy(target, err);
    /* many calls after ...*/
}


// private impls

void __calculate_by_baseStrategy(Bonus *target, int* err) {
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // ANSWER: just keep simple sygnature with resending pointer to optional error 
    target->ticketPerMen = __calculate_per_men(target, err);
    target->ticketPerFemale = __calculate_per_female(target, err);
}

int __calculate_per_men(Bonus* target, int* err) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // ANSWER - IF required - we will send err along with result
    return ZDIV(target->menQuote, target->actualMenCount);
}

int __calculate_per_female(Bonus* target, int* err) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // ANSWER - IF required - we will send err along with result
    return ZDIV(target->femaleQuote, target->actualFemaleCount);
}

