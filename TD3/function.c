#include "header.h"

/*
 * function : Saisit une fiche eleve au clavier : age, annee de
 *            naissance, nombre de notes puis les notes.
 *            Le nombre de notes est limite a MAXNOTE et chaque
 *            note doit etre entre 0 et 20.
 *
 * inputs :
 *  - Eleve * eleve : adresse de la fiche a remplir
 *
 * outputs :
 *  - aucun (la fiche est remplie directement)
 */
void saisirfiche(Eleve * eleve){
    printf("Entrer le nom : ");
    scanf(" %s", eleve->Name);
    printf("Entrer l'annee de naissance : ");
    scanf(" %u", &eleve->Year_Birth);
    printf("Entrer le nombre de note : ");
    scanf(" %u", &eleve->nbNote);
    if (eleve->nbNote > MAXNOTE) {
        printf(ROUGE "Nombre de notes trop eleve, ramene a %d" RESET "\n\r", MAXNOTE);
        eleve->nbNote = MAXNOTE;
    }
    for (int i=0; i < eleve->nbNote; i++) {
        printf("Entrer la note %d : ",i+1);
        scanf(" %f", &eleve->note[i]);
        if (eleve->note[i] > 20) {
            printf(ROUGE "Veuillez saisir une note entre 0 et 20 !!!" RESET "\n\r");
            i--; //redo the scanf
        }
    }
}

/*
 * function : Affiche le contenu d'une fiche eleve.
 *
 * inputs :
 *  - Eleve * eleve : adresse de la fiche a afficher
 *
 * outputs :
 *  - aucun
 */
void afficherfiche(Eleve * eleve){
    printf("Name               : %s\n\r",eleve->Name);
    printf("Annee de naissance : %u\n\r",eleve->Year_Birth);
    printf("Nombre de notes    : %u\n\r",eleve->nbNote);
    for (int i=0; i < eleve->nbNote; i++) {
        printf("  - note %d : %4.2f/20\n\r",i+1,eleve->note[i]);
    }
}

/*
 * function : Calcule la moyenne des notes d'une fiche.
 *            Pas de moyenne possible sans note : on renvoie -1
 *            (a verifier avant l'appel, cf. main).
 *
 * inputs :
 *  - Eleve * eleve : adresse de la fiche
 *
 * outputs :
 *  - float : la moyenne, ou -1 si nbNote vaut 0
 */
float Moyenne(Eleve * eleve){
    if (eleve->nbNote == 0) {
        return -1;
    }
    int acc = 0;
    for (int i = 0; i<eleve->nbNote; i++) {
        acc += eleve->note[i];
    }

    return ((float)acc)/eleve->nbNote;
}