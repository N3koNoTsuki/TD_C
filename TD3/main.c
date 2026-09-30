#include "header.h"
#include <stdio.h>

int main(int argc, char * argv[]){

    Eleve Jules;
    saisirfiche(&Jules);
    printf("%u\n",Jules.age);
    printf("%u\n",Jules.Year_Birth);
    printf("%u\n",Jules.nbNote);
    for (int i =0; i < Jules.nbNote; i++) {
        printf("%u\n", Jules.note[i]);
    
    }
}