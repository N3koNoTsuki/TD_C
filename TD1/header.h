// Empêche d'inclure ce fichier plusieurs fois
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

// Taille du tableau utilisé dans l'exercice 1
#define LEN 10

// Couleurs ANSI pour le terminal
#define ROUGE  "\033[31m"
#define VERT   "\033[32m"
#define JAUNE  "\033[33m"
#define BLEU   "\033[1;34m"
#define CYAN   "\033[36m"
#define RESET  "\033[0m"

// Trie le tableau dans l'ordre croissant
void orderTab(int tab[], int len);
// Affiche les LEN valeurs du tableau
void afficheTab(int tab[]);
// Compte le nombre de bits à 1 dans un entier
int bitcount(int a);

#endif
