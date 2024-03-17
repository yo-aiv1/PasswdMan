#include <sodium.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable: 4996) // disable the stinky scanf warning

char *GenRandPass(int lenght, int PassType) {
    /*---------[ VARIABLE DECLARATIONS ]---------*/
    int index = 0;
    int len = 0;

    /*---------[ INITIALIZING LIBRARY ]---------*/
    if (sodium_init() < 0) {
        printf("[-] Error initializing sodium. :(\n");
        exit(1);
    }

    /*---------[ ACTUAL LOGIC HERE ]---------*/

    // lists of characters to pick from
    const char* sOption[] = {
        ".,-<>@+*$/()=?{}[]!#%&12345ABCDEFGHIJKLMNOPTVWXYZabcdefghijklmnopqrstuvwxyz",
        "12345ABCDEFGHIJKLMNOPTVWXYZabcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPTVWXYZabcdefghijklmnopqrstuvwxyz"
    };

    char* pass = (char*)calloc((size_t)(lenght + 1), sizeof(char));
    if (!pass) {
        printf("[-] Error allocating memory with calloc. :(\n");
        return NULL;
    }

    switch (PassType) {
    case 1:
        index = 0;
        len = (int)strlen(sOption[index]);
        break;
    case 2:
        index = 1;
        len = (int)strlen(sOption[index]);
        break;
    case 3:
        index = 2;
        len = (int)strlen(sOption[index]);
        break;
    }

    // generate and display password
    for (int i = 0; i < lenght; i++) {
        pass[i] = sOption[index][randombytes_uniform(len)];
    }

    return pass;
}
