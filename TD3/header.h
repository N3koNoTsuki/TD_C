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

// Exercice 2 : structures avec pointeur vs tableau
struct S1 {
    int a;
    char * ch;
};

struct S2 {
    int a;
    char ch[40];
};

void saisirfiche(Eleve * eleve);
void afficherfiche(Eleve * eleve);
float Moyenne(Eleve * eleve);

