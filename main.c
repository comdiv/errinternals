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
    calculate_Bonus(&bonus);

    // PROBLEM (1): catch errors inside calculate bonus HERE

    // Местный гуру: я посмотрел все решения, до сих пор вызывающая сторона обязана
    // знать про ошибки и реагировать на них, а лучше бы чтобы ошибки наоборот если ты их 
    // игноришь - валились бы. И ведь нельзя будет в языке заставить обрабатывать ошибку, у нас же свобода
    // наоборот у нас низовые функции просто ВОПЯТ - у нас ошибка! А мы их вызываем и игнорим.
    // Во вторых по всему стеку приходится пробрасывать эти коды или структуры ошибок. 
    // А структуры еще и память едят. Нет. Давайте так. Если есть ошибка, то все, значит что-то пошло
    // не так. И будем это пробрасывать вверх. Причем похоже вообще вплоть до точки входа и выхода 
    // из программы. И только если кто-то точно знает что делать пусть сможет это перехватить и обработать - вот он
    // пусть это и делает. Раз он умеет реагировать на исключительные ситуации, назовем это исключениями...

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