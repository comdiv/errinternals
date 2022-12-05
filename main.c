#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "bonus.h"

int readInt(const char* prompt);

int main()
{
    int ticketCount = readInt ("Please enter ticket count: ");
    printf("Ok, assumed that total count of tickets: %d\n", ticketCount);

    Bonus bonus;
    init_Bonus(ticketCount, &bonus);
    printf("Bonus successfully initialized with total:%d, menRate: %f, menQuote: %d, femaleQuote: %d\n", 
        bonus.totalBonusTickets, 
        bonus.menRate,
        bonus.menQuote,
        bonus.femaleQuote
        );

    printf("Ok after all guests on board fill count data\n");
    bonus.actualMenCount = readInt("Enter actual men count: ");
    bonus.actualFemaleCount = readInt("Enter actual femail count: ");
    printf("Ok, perform compilation...\n");

    // PROBLEM (1): catch errors inside calculate bonus HERE
    // ANSWER: you can deal with error or not too deal

    int err = 0;
    calculate_Bonus(&bonus, &err);
    if (err) {
        fprintf(stderr, "Error! Read manual, code: %d\n", err);
    }
    /**
     * calculate_Bonus(&bonus, NULL); // это игнор ошибки
     * 
     * Это и есть эквивалент обработки в GO, мы получаем в ответ и результат и ошибку, но которую можно при этом игнорировать
     * 
     * func calculate_Bonus(bonus *Bonus) error {...}
     * // обработка
     * err := calculate_Bonus(&bonus)
     * if err != nil {
     *    ...
     * }
     * // игнор
     * _ = calculate_Bonus(&bonus)
     * 
     * // Результат возвращается всегда, ошибка в принципе возвращается, но обработка - опциональная
    */

    printf("All well, %d per male, %d per female", bonus.ticketPerMen, bonus.ticketPerFemale);
    return 0;
}

int readInt(const char* prompt) {
    const char *line = readline (prompt);
    int number = atoi(line);
    if (number <= 0 && strcmp(line, "0") != 0 ){
        printf("Incorrect number: `%s`, relaunch program!\n", line);
        exit(1);
    }
    return number;
}