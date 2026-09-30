#include "header.h"
#include <stdio.h>

void saisirfiche(Eleve * eleve){
    printf("Entrer l'age :");
    scanf(" %u", &eleve->age);
    printf("Entrer l'annee de naissance :");
    scanf(" %u", &eleve->Year_Birth);
    printf("Entrer le nombre de note :");
    scanf(" %u", &eleve->nbNote);
    if (eleve->nbNote > MAXNOTE) {
        printf("nombre de note trop elever, rebasculler a %d", MAXNOTE);
        eleve->nbNote = MAXNOTE;
    }
    for (int i=0; i < eleve->nbNote; i++) {
        printf("Entrer la note %d:",i+1);
        scanf(" %u", &eleve->note[i]);
    }
    
}