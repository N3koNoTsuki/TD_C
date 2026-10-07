// Empêche d'inclure ce fichier plusieurs fois
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Couleurs ANSI pour le terminal
#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define JAUNE  "\033[33m"
#define BLEU   "\033[1;34m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

// Un maillon de la file
typedef struct element{
    int val;
    struct element *next;
} element;

// La file : pointeurs sur le premier et le dernier maillon
typedef struct file{
    element *debut;
    element *fin;
} file;



void init_FIFO(file *f);
void Insert(file *f, int val);
int Del(file *f);
void afficherFIFO(file *f, int select);
int nbEle(file *f);
int estVide(file *f);
void viderFIFO(file *f);
void test(void);

// Menu interactif
#define NB_CHOIX 4
#define TAILLE_MSG 64

void affichage(file *f, const char *message);
int executerChoix(file *f, int selection, char *message);

#endif
