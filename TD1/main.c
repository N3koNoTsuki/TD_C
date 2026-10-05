#include "header.h"

int main(int argc, char* argv[]){

    // Le programme attend un entier en argument (pour l'exercice 2.4)
    if ((argc < 2) || (argc > 3)) {
        printf(ROUGE "Please ensure to write the value for ex2.4 (int a)" RESET "\n");
        return -1;
    }


    int Tab[LEN] = {98, 45, 61,15,15,15,151,1,18,2};

    // Exercice 1 : affiche le tableau avant et après le tri
    printf(BLEU "Exercice 1:" RESET "\n");
    afficheTab(Tab);
    orderTab(Tab, LEN);
    afficheTab(Tab);


    // Exercice 2 : opérations bit à bit
    printf("\n" BLEU "Exercice 2:" RESET "\n");
    //1 - Multiplier par 2 = décaler d'un bit vers la gauche
    int a = 15;
    printf("%d * 2 = %d\n", a, a<<1);
    //2 - Garde l'octet de poids fort de b et l'octet de poids faible de c en a 1
    unsigned int b = 0xFFFFFFFF;
    unsigned int c = 0xAAAAAAAA;
    printf("b = 0x%X | c = 0x%X donc => 0x%X\n", b,c, b >>16 | (~c <<16));
    //3 - Vérifie si le 10e bit est à 1 dans les deux nombres (masque 0x0200)
    int d = 0x0200;
    int e = 0x0A00;
    printf("d = 0x%X | e = 0x%X donc le 10e bit = %d\n", d,e, (d & 0x0200) && (e & 0x0200)? 1 : 0);
    //4 - Convertit l'argument en entier puis compte ses bits à 1
    int f = atoi(argv[1]);
    printf("f = 0x%X a %d bit a 1\n\n", f, bitcount(f));

    // Exercice 3 : résultats des expressions calculés à la main
    printf(BLEU "Exercice 3:" RESET "\n");

    printf("2*((i/5)+(4*(j-3))%%(i+j-2)) = " CYAN "18" RESET "\n");
    printf("i <= j = " ROUGE "FALSE" RESET "\n");
    printf("j != 6 =  " VERT "TRUE" RESET "\n");
    printf("c == 99 =  " VERT "TRUE" RESET "\n");
    printf("8*(i+j) > 'c' =  " ROUGE "FALSE" RESET "\n");
    printf("(i>0) && (j<5) =  " ROUGE "FALSE" RESET "\n");
    printf("(x>y) && (i>0) && (j<5) =  " ROUGE "FALSE" RESET "\n\n");
    printf(JAUNE "Avec :" RESET "\n");
    printf("int i=8\n");
    printf("int j=5\n");
    printf("float x=0.005\n");
    printf("float y=-0.01\n");
    printf("float c='c'\n");






    return 0;
}
