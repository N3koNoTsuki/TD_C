#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

    // Le programme attend un entier en argument (pour l'exercice 2.4)
    if ((argc < 2) || (argc > 3)) {
        printf("Please ensure to write the value for ex2.4 (int a)\n\r");
        return -1;
    }


    int Tab[LEN] = {98, 45, 61,15,15,15,151,1,18,2};

    // Exercice 1 : affiche le tableau avant et après le tri
    printf("Exercice 1:\n\r");
    afficheTab(Tab);
    orderTab(Tab, LEN);
    afficheTab(Tab);


    // Exercice 2 : opérations bit à bit
    printf("\n\rExercice 2:\n\r");
    //1 - Multiplier par 2 = décaler d'un bit vers la gauche
    int a = 15;
    printf("%d * 2 = %d\n\r", a, a<<1);
    //2 - Garde l'octet de poids fort de b et l'octet de poids faible de c
    int b = 0xABCD;
    int c = 0x1234;
    printf("b = 0x%X | c = 0x%X donc c = 0x%X\n\r", b,c, (b & 0xFF00) + (c & 0x00FF));
    //3 - Vérifie si le 10e bit est à 1 dans les deux nombres (masque 0x0200)
    int d = 0x0200;
    int e = 0x0A00;
    printf("d = 0x%X | e = 0x%X donc le 10e bit = %d\n\r", d,e, (b & 0x0200) && (c & 0x0200)? 1 : 0);
    //4 - Convertit l'argument en entier puis compte ses bits à 1
    int f = atoi(argv[1]);
    printf("f = 0x%X a %d bit a 1\n\r\n\r", f, bitcount(f));

    // Exercice 3 : résultats des expressions calculés à la main
    printf("Exercice 3:\n\r");

    printf("2*((i/5)+(4*(j-3))%%(i+j-2)) = 18\n\r");
    printf("i <= j = FALSE\n\r");
    printf("j != 6 =  TRUE\n\r");
    printf("c == 99 =  TRUE\n\r");
    printf("8*(i+j) > 'c' =  FALSE\n\r");
    printf("(i>0) && (j<5) =  FALSE\n\r");
    printf("(x>y) && (i>0) && (j<5) =  FALSE\n\r\n\r");
    printf("Avec :\n\r");
    printf("int i=8\n\r");
    printf("int j=5\n\r");
    printf("float x=0.005\n\r");
    printf("float y=-0.01\n\r");
    printf("float c='c'\n\r");






    return 0;
}
