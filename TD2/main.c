#include "header.h"

//Pour 2.2
static int var1 = 0;
int var2 = 3;
int var3 = 6;

/*
 * function : Affiche les valeurs des variables globales.
 *            Elle est dans main.c car var1 est static : elle
 *            n'est visible que dans ce fichier.
 *            Ici aucune variable ne masque les globales.
 * 
 * inputs :
 *  - const char *moment : texte indiquant quand on affiche
 * 
 * outputs :
 *  - aucun
 */
void afficher_globales(const char *moment)
{
    printf(VERT "  [globales %s] var1 = %d, var2 = %d, var3 = %d" RESET "\n\r",
           moment, var1, var2, var3);
}

int main(int argc, char* argv[]){

    //Exercice 1.1
    printf(BLEU "Exercice 1.1:" RESET "\n\r");
    int e = 20;
    int g = 10;
    printf("e = %d, g = %d\n\r",e,g);
    permute(&e, &g);
    printf("e = %d, g = %d\n\n\r",e,g);

    //Exercice 1.2
    printf(BLEU "Exercice 1.2:" RESET "\n\r");
    printf("Le programme du 1.2 compile, mais plante a l'execution :\n\r\
" ROUGE "Segmentation fault         (core dumped) ./Output/TD2" RESET "\n\r\
car les pointeurs ne sont pas initialises : ils ne pointent sur aucune zone reservee.\n\r\
Il faut donc allouer la memoire dynamiquement avec malloc.\n\r\
A noter qu'ici un tableau (taille connue) serait plus judicieux\n\r");
    char * chaine;
    int * tab;
    chaine = malloc(TAILLE * sizeof(char));
    tab = malloc(TAILLE * sizeof(int));
    for (int i = 0; i<TAILLE - 1; i++) {
        tab[i] = i+1;
        chaine[i] = (char) (i+65);
    }
    // Caractere de fin de chaine
    chaine[TAILLE-1] = 0;
    for (int j = 0; j<TAILLE -1; j++) {
        printf("%d | %c\n\r", tab[j], chaine[j]);
    }

    //Exercice 1.3
    printf("\n\r" BLEU "Exercice 1.3:" RESET "\n\r");
    int FlagStop = 0;
    if (argc != 3) {
        printf(ROUGE "Il faut deux arguments (argc = 3 avec le nom du programme) !!!" RESET "\n\r");
        FlagStop = 1;
    }
    if(!FlagStop){
        printf("\
$%s %s %s\n\r\
C'est la commande que tu as entree pour lancer le programme, chaque \"mots\" est un argument\n\n\r", argv[0],argv[1],argv[2]);
    }
    
    //Exercice 2.1
    printf("\n\r" BLEU "Exercice 2.1:" RESET "\n\r");
    int *a;
    int b = 3;
    int c;
    a = &b;
    printf("a = &b  -> a = %p, &b = %p\n\r", (void *)a, (void *)&b);
    printf("          b = %d, *a = %d\n\r", b, *a);
    b = 2;
    printf("b = 2   -> b = %d, *a = %d (a pointe toujours sur b)\n\r", b, *a);
    // b est passe par valeur (i), par adresse (j) et via *a (k)
    c = Pipo(b, a, *a);
    printf(JAUNE "=== Retour dans le main ===" RESET "\n\r");
    printf("a  = %p (adresse de b, inchangee)\n\r", (void *)a);
    printf("*a = %d\n\r", *a);
    printf("b  = %d (modifie par *j = 4 dans Pipo)\n\r", b);
    printf("c  = %d (valeur retournee par Pipo)\n\r", c);

    //Exercice 2.2
    printf("\n\r" BLEU "Exercice 2.2:" RESET "\n\r");
    int var2;   /* locale de main : masque la globale var2 */

    var2 = 5;
    printf("Debut : var2 locale du main = %d\n\r", var2);
    afficher_globales("au debut");

    // f recoit une copie : la var2 du main ne sera pas modifiee
    printf("\n\r" JAUNE "--- f(var2) : on passe la var2 LOCALE du main (5) ---" RESET "\n\r");
    f(var2);

    // var1 est static : globale mais visible seulement dans main.c
    printf("\n\r" JAUNE "--- f(var1) : on passe la var1 GLOBALE static (0) ---" RESET "\n\r");
    f(var1);

    // Le premier appel de f a deja mis la globale var3 a 8
    printf("\n\r" JAUNE "--- f(var3) : on passe la var3 GLOBALE (deja 8 !) ---" RESET "\n\r");
    f(var3);

    printf("\n\r" JAUNE "=== Fin du main ===" RESET "\n\r");
    printf("var1 = %d (jamais modifiee : f utilise sa propre var1)\n\r", var1);
    printf("var2 = %d (locale du main)\n\r", var2);
    printf("var3 = %d (modifiee par f)\n\r", var3);
    afficher_globales("a la fin");

    return 0;
    
}