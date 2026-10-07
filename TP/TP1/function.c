#include "header.h"


void affiche(char tab[]){
    printf("%s\n",tab);
}

long int factoriel(long int fact){
    long int retVal = 1;
    for (int i = 1; i<=fact; i++) {
            retVal *=i;
    }
    return retVal;
}

void meow(void){
    printf(MEOW);
}

void ldate(void){
    system("/bin/date");
}