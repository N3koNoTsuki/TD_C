#include "stdio.h"
#include "stdlib.h"

// Couleurs ANSI pour le terminal
#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define JAUNE  "\033[33m"
#define BLEU   "\033[1;34m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

#define MAXNOTE 10

typedef struct{

    unsigned int age;
    unsigned int Year_Birth;
    unsigned int nbNote;
    unsigned int note[MAXNOTE];
}Eleve;

void saisirfiche(Eleve * eleve);

