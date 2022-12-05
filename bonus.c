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



IntResult __calculate_per_men(Bonus* target);
IntResult __calculate_per_female(Bonus* target);
VoidResult __calculate_by_baseStrategy(Bonus *target);

// public impls

VoidResult calculate_Bonus(Bonus* target) {
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // RUST LIKE - мы не просто копим ошибки, мы еще можем и структурировано досрочный выход с пропагацией сделать
    /**
     * Это аналог растовского
     * fn calculate_Bonus(&mut target: Bonus) -> Result<(),Error> {
     *      __calculate_by_baseStrategy(target)?; // знак вопроса в конце означает, 
     *              //что если тут ошибка прерваться и выдать уже ошибку завернутую в результат
     *      ...
     * }
    */
    /* many calls before ...*/
    unwrapOrError(__calculate_by_baseStrategy(target));
    /* many calls after ...*/
    return NO_ERROR_RESULT;
}


// private impls

VoidResult __calculate_by_baseStrategy(Bonus *target) {
    // PROBLEM (3) WE DON'T WANT TO STEP BY STEP WORK WITH ERRORS ON ALL CALLS (WE ARE LAZY)
    // RUST LIKE - мы не просто копим ошибки, мы еще можем и структурировано досрочный выход с пропагацией сделать
    unwrapValueOrError(target->ticketPerMen, __calculate_per_men(target) )
    unwrapValueOrError(target->ticketPerFemale, __calculate_per_female(target) )
    return NO_ERROR_RESULT;
}

IntResult __calculate_per_men(Bonus* target) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // ANSWER - functional-like style Either
    return INT_OR_ERR(
        target->actualMenCount!=0,
        target->menQuote / target->actualMenCount,
        BONUS_UNKNOWN, 
        ERR_ARIPH_ERR
    );
}

IntResult __calculate_per_female(Bonus* target) {
    // PROBLEM (2) EXCEPTION IS OCCURED HERE, AT LOWEST LEVEL
    // ANSWER - functional-like style Either
    return INT_OR_ERR(
        target->actualFemaleCount!=0,
        target->femaleQuote / target->actualFemaleCount,
        BONUS_UNKNOWN, 
        ERR_ARIPH_ERR
    );
}

