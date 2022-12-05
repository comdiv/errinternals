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

// private defs



IntOrErr __calculate_per_men(Bonus* target);
IntOrErr __calculate_per_female(Bonus* target);
Err __calculate_by_baseStrategy(Bonus *target);

// public impls

Err calculate_Bonus(Bonus* target) {
    Err result = NO_ERROR;
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // ANSWER: shugar with conditional behavior and error accumulation
    /* many calls before ...*/
    result |= __calculate_by_baseStrategy(target);
    /* many calls after ...*/
    return result;
}


// private impls

Err __calculate_by_baseStrategy(Bonus *target) {
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // ANSWER: shugar with conditional behavior and error accumulation
    Err err = NO_ERROR;
    APPLY_INT_OR_ERR(err, target->ticketPerMen,  __calculate_per_men(target));
    APPLY_INT_OR_ERR(err, target->ticketPerFemale,  __calculate_per_female(target));
    return err;
}

IntOrErr __calculate_per_men(Bonus* target) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // ANSWER - functional-like style Either
    return INT_OR_ERR(
        target->actualMenCount!=0,
        target->menQuote / target->actualMenCount,
        BONUS_UNKNOWN, 
        ERR_ARIPH_ERR
    );
}

IntOrErr __calculate_per_female(Bonus* target) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // ANSWER - functional-like style Either
    return INT_OR_ERR(
        target->actualFemaleCount!=0,
        target->femaleQuote / target->actualFemaleCount,
        BONUS_UNKNOWN, 
        ERR_ARIPH_ERR
    );
}

