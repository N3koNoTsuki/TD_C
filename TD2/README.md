# TD2 - C

## Compilation

```bash
make
```

L'exécutable est généré dans `Output/TD2`.

Pour nettoyer :

```bash
make clean
```

## Exécution

```bash
./Output/TD2 <arg1> <arg2>
```

Les deux arguments (quelconques) sont utilisés pour l'exercice 1.3 (affichage de la ligne de commande via `argc` / `argv`). Sans exactement deux arguments, un message d'erreur est affiché pour cet exercice et le reste du programme s'exécute normalement.

Exemple :

```bash
./Output/TD2 hello world
```

## Contenu

- **Exercice 1.1** : échange de deux entiers par pointeurs avec le XOR, sans variable temporaire (`permute`).
- **Exercice 1.2** : pointeurs non initialisés (segmentation fault) et allocation dynamique avec `malloc`.
- **Exercice 1.3** : arguments de la ligne de commande (`argc`, `argv`).
- **Exercice 2.1** : passage par valeur vs passage par adresse (`Pipo`).
- **Exercice 2.2** : portée et durée de vie des variables : globales, `static`, locales, paramètres, masquage (`f`, `afficher_globales`).

## Fichiers

- `main.c` : programme principal, variables globales et `afficher_globales`
- `function.c` : fonctions des exercices (`permute`, `Pipo`, `f`)
- `header.h` : prototypes, constante `TAILLE`, couleurs ANSI et déclarations `extern`
- `Makefile` : compilation
