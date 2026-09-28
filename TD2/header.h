#include "stdio.h"
#include "stdlib.h"

#define TAILLE 10

// Couleurs ANSI pour le terminal
#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define JAUNE  "\033[33m"
#define BLEU   "\033[1;34m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

extern int var2;
extern int var3;

void permute(int* a, int* b);
int Pipo(int i, int *j, int k);
void afficher_globales(const char *moment);
void f(int var2);

