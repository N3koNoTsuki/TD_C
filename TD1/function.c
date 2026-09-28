#include "header.h"

/*
 * function : Trie un tableau dans l'ordre croissant (recursif).
 *            On place le plus grand element a la fin, puis on
 *            recommence sur le reste du tableau.
 * 
 * inputs :
 *  - int tab[] : tableau a trier
 *  - int len : nombre de cases a trier
 * 
 * outputs :
 *  - aucun (le tableau est modifie directement)
 */
void orderTab(int tab[], int len) {
  // Un tableau de 0 ou 1 élément est déjà trié : on s'arrête
  if (len < 2) {
    return;
  }

  // Recherche du maximum et de sa position
  int max = tab[0];
  int ind = 0;

  for (int i = 1; i < len; i++) {
    if (max < tab[i]) {
      max = tab[i];
      ind = i;
    }
  }

  // Échange du maximum avec la dernière case
  int tmp = tab[len - 1];
  tab[len - 1] = max;
  tab[ind] = tmp;

  // On trie le reste du tableau
  orderTab(tab, len - 1);
}

/*
 * function : Affiche les valeurs du tableau sur une ligne
 * 
 * inputs :
 *  - int tab[] : tableau a afficher (de taille LEN)
 * 
 * outputs :
 *  - aucun
 */
void afficheTab(int tab[]) {
  for (int i = 0; i < LEN; i++) {
    printf("%i ", tab[i]);
  }
  printf("\n\r");
}

/*
 * function : Renvoie le nombre de bit a 1 dans un int
 * 
 * inputs :
 *  - int a : entier dont on veut savoir le nombre de bit a 1
 * 
 * outputs :
 *  - int BitCpt : nombre de bit a 1 
 */
int bitcount(int a) {

    int BitCpt = 0;
    for (int i = 0; i < 32; i++) {
        BitCpt += (a >> i) & 0x00000001;
    }
    return BitCpt;
}
