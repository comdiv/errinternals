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

    ERR_OUT_VARIABLE = 0;

    calculate_Bonus(&bonus);

    // PROBLEM (1): catch errors inside calculate bonus HERE
    // ANSWER : WE CHECK GLOBAL ERROR FLAG IN PLACE WHERE WE CAN DECIDE WHAT TO DO
    if (ERR_OUT_VARIABLE != 0) {
        fprintf(stderr, "Error! see manual, err code: %d\n", ERR_OUT_VARIABLE);
        exit(ERR_OUT_VARIABLE);
    }
    

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