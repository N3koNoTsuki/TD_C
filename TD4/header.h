// Empêche d'inclure ce fichier plusieurs fois
#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"

// Couleurs ANSI pour le terminal
#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define JAUNE  "\033[33m"
#define BLEU   "\033[1;34m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

typedef struct filo{
    int val;
    struct filo *next;
} filo;

void init_FILO(filo *filo);
void Del(filo *filo);
void Insert(filo *filo);

#endif
