# TD C - INSA 3A

Travaux dirigés de langage C (INSA, 3e année).

Chaque TD est dans son propre dossier, avec son code, son `Makefile` et son `README.md`.

## TDs

| TD | Contenu |
|----|---------|
| [TD1](TD1/) | Tri récursif d'un tableau, opérations bit à bit, expressions logiques |
| [TD2](TD2/) | Pointeurs, allocation dynamique, arguments `argc`/`argv`, passage par valeur/adresse, portée des variables |
| [TD3](TD3/) | Structures, saisie/affichage d'une fiche élève, copie de structures (pointeur vs tableau) |
| [TD4](TD4/) | File (FIFO) en liste chaînée, menu interactif |

## Compiler et lancer un TD

```bash
cd TDx
make
./Output/TDx [arguments]
```

(remplacer `TDx` par `TD1`, `TD2`, ...)

`make clean` supprime les fichiers compilés.

Les arguments attendus (s'il y en a) sont indiqués dans le `README.md` de chaque TD.

## Prérequis

- `gcc`
- `make`
