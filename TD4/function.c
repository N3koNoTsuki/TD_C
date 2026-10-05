#include "header.h"


/*
 * function : Initialise une file vide (aucun maillon).
 *
 * inputs :
 *  - file *f : adresse de la file a initialiser
 *
 * outputs :
 *  - aucun (debut et fin sont mis a NULL)
 */
void init_FIFO(file *f){
    f->debut = NULL;
    f->fin = NULL;
}

/*
 * function : Insere une valeur en fin de file. Alloue un nouveau
 *            maillon et le rattache apres le dernier.
 *            Affiche une erreur si l'allocation echoue.
 *
 * inputs :
 *  - file *f : adresse de la file
 *  - int val : valeur a inserer
 *
 * outputs :
 *  - aucun (la file est modifiee directement)
 */
void Insert(file *f, int val){
    element *nouveau = malloc(sizeof(element));
    if (nouveau == NULL) {
        printf(ROUGE "Erreur d'allocation\n" RESET);
        return;
    }
    nouveau->val = val;
    nouveau->next = NULL;

    if (estVide(f)) {
        f->debut = nouveau;
    }
    else {
        f->fin->next = nouveau;
    }
    f->fin = nouveau;
}

/*
 * function : Retire le premier element de la file et libere
 *            son maillon. Si la file est vide, affiche une erreur.
 *
 * inputs :
 *  - file *f : adresse de la file
 *
 * outputs :
 *  - int : valeur retiree, ou -1 si la file est vide
 */
int Del(file *f){
    if (estVide(f)) {
        printf(ROUGE "La file est vide, rien a retirer\n" RESET);
        return -1;
    }
    element *premier = f->debut;
    int val = premier->val;

    f->debut = premier->next;
    //la file devient vide
    if (f->debut == NULL) {
        f->fin = NULL;
    }
    free(premier);
    return val;
}

/*
 * function : Affiche le contenu de la file selon le mode choisi.
 *            Affiche "File vide" si la file ne contient rien.
 *
 * inputs :
 *  - file *f    : adresse de la file
 *  - int select : 0 = premier element, 1 = dernier element,
 *                 2 = toute la file, autre = rien
 *
 * outputs :
 *  - aucun
 */
void afficherFIFO(file *f, int select){
    if (estVide(f)) {
        printf(JAUNE "File vide\n" RESET);
        return;
    }
    switch (select) {
        //premier element
        case 0:
            printf("%d\n",f->debut->val);
            break;
        //dernier element
        case 1:
            printf("%d\n",f->fin->val);
            break;
        //tout
        case 2:
            for (element *e = f->debut; e != NULL; e = e->next) {
                printf("%d ",e->val);
            }
            printf("\n");
            break;
        //autre valeur
        default :
            break;
    }
}

/*
 * function : Compte le nombre d'elements de la file.
 *
 * inputs :
 *  - file *f : adresse de la file
 *
 * outputs :
 *  - int : nombre d'elements
 */
int nbEle(file *f){
    int acc = 0;
    for (element *e = f->debut; e != NULL; e = e->next) {
        acc++;
    }
    return acc;
}

/*
 * function : Indique si la file est vide.
 *
 * inputs :
 *  - file *f : adresse de la file
 *
 * outputs :
 *  - int : 1 si la file est vide, 0 sinon
 */
int estVide(file *f){
    return f->debut == NULL;
}

/*
 * function : Retire et libere tous les elements de la file.
 *
 * inputs :
 *  - file *f : adresse de la file
 *
 * outputs :
 *  - aucun (la file est vide en sortie)
 */
void viderFIFO(file *f){
    while (!estVide(f)) {
        Del(f);
    }
}

/*
 * function : Teste les fonctions de la file : insertion de 1 a 15,
 *            affichages, comptage, retrait puis vidage.
 *
 * inputs :
 *  - aucun
 *
 * outputs :
 *  - aucun (resultats affiches a l'ecran)
 */
void test(void){
    file *f;
    f = malloc(sizeof(file));
    init_FIFO(f);
    printf("Vide : %d\n", estVide(f));

    for (int i=1; i<=15; i++) {
        Insert(f, i);
    }

    printf("Premier : ");
    afficherFIFO(f, 0);
    printf("Dernier : ");
    afficherFIFO(f, 1);
    printf("Tout    : ");
    afficherFIFO(f, 2);
    printf("Nombre d'elements : %d\n", nbEle(f));
    printf("Vide : %d\n", estVide(f));

    printf("Retire : %d\n", Del(f));
    printf("Tout    : ");
    afficherFIFO(f, 2);
    printf("Nombre d'elements : %d\n", nbEle(f));

    viderFIFO(f);
}

// Libelles du menu
static const char *choix[NB_CHOIX] = {"0 - Inserer", "1 - Retirer", "2 - Vider", "3 - Quitter"};


/*
 * function : Affiche une ligne de bordure du tableau de la file,
 *            ex : +----+------+. La largeur de chaque case depend
 *            du nombre de chiffres de la valeur (+2 pour les espaces).
 *
 * inputs :
 *  - file *f : adresse de la file
 *
 * outputs :
 *  - aucun
 */
static void afficherBordure(file *f){
    char buf[16];
    printf("+");
    for (element *e = f->debut; e != NULL; e = e->next) {
        int largeur = snprintf(buf, sizeof(buf), "%d", e->val) + 2;
        for (int i = 0; i < largeur; i++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

/*
 * function : Efface l'ecran puis affiche la file sous forme de
 *            tableau, le menu et le message de la derniere action.
 *
 * inputs :
 *  - file *f             : adresse de la file
 *  - const char *message : message de la derniere action
 *
 * outputs :
 *  - aucun
 */
void affichage(file *f, const char *message){
    // efface l'ecran et replace le curseur en haut
    printf("\033[H\033[J");

    // la file, horizontalement
    if (estVide(f)) {
        printf(JAUNE "File vide\n" RESET);
    }
    else {
        afficherBordure(f);
        printf("|");
        for (element *e = f->debut; e != NULL; e = e->next) {
            printf(" %d |", e->val);
        }
        printf("\n");
        afficherBordure(f);
    }

    // le menu
    printf("\n");
    for (int i = 0; i < NB_CHOIX; i++) {
        printf("%s", choix[i]);
        if (i < NB_CHOIX - 1) {
            printf(" | ");
        }
    }
    printf("\n\nDerniere action : %s\n", message);
    printf("Selection : ");
}

/*
 * function : Execute l'option du menu choisie (inserer, retirer,
 *            vider ou quitter) et ecrit le resultat dans message.
 *
 * inputs :
 *  - file *f       : adresse de la file
 *  - int selection : numero de l'option (0 a NB_CHOIX - 1)
 *  - char *message : buffer de TAILLE_MSG caracteres ou ecrire
 *                    le resultat de l'action
 *
 * outputs :
 *  - int : -1 pour quitter, 0 sinon
 */
int executerChoix(file *f, int selection, char *message){
    int val;

    switch (selection) {
        //inserer
        case 0:
            printf("Valeur a inserer : ");
            if (scanf("%d", &val) == 1) {
                Insert(f, val);
                snprintf(message, TAILLE_MSG, VERT "Insere : %d" RESET, val);
            }
            else {
                snprintf(message, TAILLE_MSG, ROUGE "Saisie invalide" RESET);
            }
            break;
        //retirer
        case 1:
            if (estVide(f)) {
                snprintf(message, TAILLE_MSG, ROUGE "La file est vide, rien a retirer" RESET);
            }
            else {
                snprintf(message, TAILLE_MSG, VERT "Retire : %d" RESET, Del(f));
            }
            break;
        //vider
        case 2:
            viderFIFO(f);
            snprintf(message, TAILLE_MSG, VERT "File videe" RESET);
            break;
        //quitter
        case 3:
            return -1;
    }
    return 0;
}
