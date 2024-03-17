#include <stdio.h>
#include <stdlib.h>

#include "../include/generator.h"

#define BANNER ";-.                      . .   ,         \n|  )                     | |\\ /|         \n|-'  ,-: ,-. ,-. , , , ,-| | V | ,-: ;-. \n|    | | `-. `-. |/|/  | | |   | | | | | \n'    `-` `-' `-' ' '   `-' '   ' `-` ' ' \n\n"

int main(void) {
    printf(BANNER);
    printf("1 > Generate a random password\n");
    printf("2 > Save a password to the database\n\n");

    char FirstInput;
    int iInput = 0;
    int iSuccessfulRead = 0;
    int iLength = 0;

    do {
        printf("input: ");
        FirstInput = getchar();
        while (getchar() != '\n');
    } while (FirstInput != '1' && FirstInput != '2');

    if (FirstInput == '1') {
        /*---------[ GENERATING RANDOM PASSWORD PROMT ]---------*/
        printf(".---------[ Randomly Generated Passwords ]---------.\n");
        printf("Please enter an option to enter your password:\n");
        printf("\t1 > Characters, Numbers and Special-Characters\n");
        printf("\t2 > Characters and Numbers\n");
        printf("\t3 > Characters\n");

        do {
            printf("input: ");
            iSuccessfulRead = scanf("%d", &iInput);
            if (iSuccessfulRead != 1) {
                // Clear the input buffer
                while (getchar() != '\n');
                printf("Invalid input. Please enter a valid option.\n");
            }
        } while (iInput != 1 && iInput != 2 && iInput != 3);

        do {
            printf("Input the desired password length: ");
            iSuccessfulRead = scanf("%d", &iLength);
            if (iSuccessfulRead != 1 || iLength <= 0) {
                // Clear the input buffer
                while (getchar() != '\n');
                printf("Invalid input. Please enter a positive integer.\n");
            }
        } while (iSuccessfulRead != 1 || iLength <= 0);

        char *Password = GenRandPass(iLength, iInput);
        printf(Password);
        free(Password);

    } else if (FirstInput == '2') {
        printf("im tired");
    }
}