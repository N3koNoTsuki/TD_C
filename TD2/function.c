#include "header.h"

/*
 * function : Echange les valeurs de deux entiers avec le XOR
 *            (sans variable temporaire).
 *            Attention : si a et b pointent sur la meme case,
 *            elle est mise a 0.
 *
 * inputs :
 *  - int* a : adresse du premier entier
 *  - int* b : adresse du second entier
 *
 * outputs :
 *  - aucun (les valeurs pointees sont modifiees directement)
 */
void permute(int* a, int* b){
    // a = a^b, puis b = b^(a^b) = a, puis a = (a^b)^a = b
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/*
 * function : Montre la difference entre un passage par valeur
 *            et un passage par adresse.
 *
 * inputs :
 *  - int i : copie d'un entier (passage par valeur)
 *  - int *j : adresse d'un entier (passage par adresse)
 *  - int k : copie d'un entier (passage par valeur)
 *
 * outputs :
 *  - int : k + 10
 */
int Pipo(int i, int *j, int k){
    printf("\n" JAUNE "--- Entree dans Pipo ---" RESET "\n");
    printf("i = %d  (copie de b)\n", i);
    printf("j = %p  (copie de l'adresse de b)\n", (void *)j);
    printf("k = %d  (copie de *a, donc de b au moment de l'appel)\n", k);

    // On ecrit a l'adresse j : la variable du main est modifiee
    *j = 4;
    printf("\n*j = 4  -> on ecrit a l'adresse %p, donc b change\n", (void *)j);

    // i est une copie : le b du main ne bouge pas
    i = 5;
    printf("i = 5   -> seule la copie locale change (i = %d)\n", i);

    // k a ete copie avant *j = 4, il vaut donc toujours 2
    k += 10;
    printf("k += 10 -> k = %d (k avait copie 2, le *j = 4 ne l'affecte pas)\n", k);

    printf(JAUNE "--- Sortie de Pipo, on retourne %d ---" RESET "\n\n", k);
    return k;
}

/*
 * function : Montre la portee et la duree de vie des variables
 *            (static, locale, parametre, globale).
 *
 * inputs :
 *  - int var2 : copie de la valeur passee (masque la globale var2)
 *
 * outputs :
 *  - aucun (modifie la globale var3)
 */
void f(int var2)
{
    static int i = 0;   /* initialisee une seule fois, garde sa valeur */
    int j = 9;          /* recreee a chaque appel */
    int var1;           /* locale : la var1 static de main.c est invisible ici */

    printf(CYAN "  entree f : parametre var2 = %d, i = %d, j = %d" RESET "\n", var2, i, j);

    i++;
    j--;
    var1 = 5;   /* locale de f */
    var2 = 6;   /* parametre (copie) de f */
    var3 = 8;   /* pas redeclaree -> GLOBALE modifiee */

    printf(CYAN "  sortie f : var1 locale = %d, var2 param = %d, i = %d, j = %d" RESET "\n",
           var1, var2, i, j);
    afficher_globales("apres f");
}
