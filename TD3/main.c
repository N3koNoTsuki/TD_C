#include "header.h"


int main(int argc, char * argv[]){

    //Exercice 1.1 : type Eleve defini dans header.h
    Eleve Jules;

    //Exercice 1.2
    printf(BLEU "Exercice 1.2:" RESET "\n");
    printf(JAUNE "--- Saisie de la fiche ---" RESET "\n");
    saisirfiche(&Jules);
    printf("\n" JAUNE "--- Affichage de la fiche ---" RESET "\n");
    afficherfiche(&Jules);

    //Exercice 1.3
    printf("\n" BLEU "Exercice 1.3:" RESET "\n");
    if (Jules.nbNote == 0) {
        printf(ROUGE "Pas de note : moyenne impossible a calculer" RESET "\n");
    } else {
        printf("Moyenne : " VERT "%.2f" RESET "\n", Moyenne(&Jules));
    }

    //Exercice 2.1
    printf("\n" BLEU "Exercice 2.1:" RESET "\n");
    struct S1 v11, v12;
    struct S2 v21, v22;

    v11.a = 3;
    // Pas v11.ch = "Hulk" : une chaine litterale est en lecture seule,
    // la modifier au 2.3 ferait un segmentation fault
    v11.ch = malloc((strlen("Hulk") + 1) * sizeof(char));
    strcpy(v11.ch, "Hulk");

    v21.a = 5;
    // ch est un tableau : on ne peut pas faire v21.ch = "Gruik"
    strcpy(v21.ch, "Gruik");

    printf("v11 = {%d, \"%s\"}\n", v11.a, v11.ch);
    printf("v21 = {%d, \"%s\"}\n", v21.a, v21.ch);

    //Exercice 2.2
    printf("\n" BLEU "Exercice 2.2:" RESET "\n");
    // L'affectation copie la structure champ par champ
    v12 = v11;
    v22 = v21;

    printf(JAUNE "--- S1 : ch est un pointeur ---" RESET "\n");
    printf("v11.ch = %p\n", (void *)v11.ch);
    printf("v12.ch = %p (meme adresse : seul le pointeur est copie)\n", (void *)v12.ch);

    printf(JAUNE "--- S2 : ch est un tableau ---" RESET "\n");
    printf("v21.ch = %p\n", (void *)v21.ch);
    printf("v22.ch = %p (adresse differente : les 40 octets sont copies)\n", (void *)v22.ch);

    //Exercice 2.3
    printf("\n" BLEU "Exercice 2.3:" RESET "\n");
    v11.ch[0] = 'B';
    v21.ch[0] = 'B';
    printf("v11.ch[0] = 'B' et v21.ch[0] = 'B'\n");

    printf(JAUNE "--- S1 ---" RESET "\n");
    printf("v11.ch = \"%s\"\n", v11.ch);
    printf("v12.ch = \"%s\" " VERT "(modifiee aussi : meme zone memoire)" RESET "\n", v12.ch);

    printf(JAUNE "--- S2 ---" RESET "\n");
    printf("v21.ch = \"%s\"\n", v21.ch);
    printf("v22.ch = \"%s\" " VERT "(pas modifiee : chaque structure a son tableau)" RESET "\n", v22.ch);

    // v11.ch et v12.ch pointent sur la meme zone : un seul free
    free(v11.ch);

    return 0;
}