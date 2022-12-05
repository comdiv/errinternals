#pragma once
#ifndef BONUS_HEADER
#define BONUS_HEADER

/// структура некоей промо программы по раздаче на мероприатии флаеров, билетов с рекламой
typedef struct Bonus
{
    // 1. некие исходные значения программы

    // 1.1 сколько всего билетов
    int totalBonusTickets;

    // 1.2 степень участия мужчин в программе (0.0 - 1.0, но обычно 0.3 их приходит меньше)
    float menRate;

    // 1.3 расчетно - сколько выдать билетов на мужчин
    int menQuote;

    // 1.4 расчетно - сколько выдать билетов на женщин
    int femaleQuote;


    // 2. актуальные данные

    // 2.1 сколько реально пришло мужчин
    int actualMenCount;

    // 2.2 сколько реально пришло женщин
    int actualFemaleCount;

    // 2.3 сколько в руки выдавать билетов мужчинам
    int ticketPerMen;

    // 2.4 сколько в руки выдавать билетов
    int ticketPerFemale;

} Bonus;

// мужчины не наш профиль, на них много не закладываем
#define FIXED_MEN_RATE 0.2
#define BONUS_UNKNOWN -1

#define ERR_ARITH_ERROR 2

void init_Bonus(int ticketCount, Bonus* target);
void calculate_Bonus(Bonus* target);

// не хотим использовать штатный errno

int* ___bonusErrNo();


#define ERR_OUT_VARIABLE  (*___bonusErrNo())

#endif