# TD1 - C

## Compilation

```bash
make
```

L'exécutable est généré dans `Output/TD1`.

Pour nettoyer :

```bash
make clean
```

## Exécution

```bash
./Output/TD1 <entier>
```

L'argument `<entier>` (en décimal) est utilisé pour l'exercice 2.4 (comptage des bits à 1).

Exemple :

```bash
./Output/TD1 255
```

## Contenu

- **Exercice 1** : tri récursif d'un tableau (`orderTab`) et affichage (`afficheTab`).
- **Exercice 2** : opérations bit à bit (décalage, masques, test d'un bit, comptage des bits avec `bitcount`).
- **Exercice 3** : évaluation d'expressions logiques et arithmétiques.

## Fichiers

- `main.c` : programme principal
- `function.c` : fonctions des exercices
- `header.h` : prototypes et constante `LEN`
- `Makefile` : compilation
