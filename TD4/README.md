# TD4 - C

## Compilation

```bash
make
```

L'exécutable est généré dans `Output/TD4`.

Pour nettoyer :

```bash
make clean
```

## Exécution

```bash
./Output/TD4
```

Aucun argument. Un menu s'affiche avec la file et le résultat de la dernière action :

- `0` : insérer une valeur (demandée ensuite)
- `1` : retirer le premier élément
- `2` : vider la file
- `3` : quitter

## Contenu

File (FIFO) d'entiers en liste chaînée, avec un pointeur sur le premier et sur le dernier maillon :

- création (`init_FIFO`), insertion en fin (`Insert`), retrait en début (`Del`)
- affichage (`afficherFIFO`), nombre d'éléments (`nbEle`), test de file vide (`estVide`)
- libération de tous les éléments (`viderFIFO`)
- fonction de test (`test`)
- menu interactif : affichage de la file sous forme de tableau (`affichage`) et exécution du choix (`executerChoix`)

## Fichiers

- `main.c` : programme principal et boucle du menu
- `function.c` : fonctions de la file et du menu
- `header.h` : types `element` et `file`, constantes du menu, couleurs ANSI et prototypes
- `Makefile` : compilation
