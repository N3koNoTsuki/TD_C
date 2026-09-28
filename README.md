# TD C - INSA 3A

Travaux dirigés de langage C (INSA, 3e année).

Chaque TD est dans son propre dossier, avec son code, son `Makefile` et son `README.md`.

## TDs

| TD | Contenu |
|----|---------|
| [TD1](TD1/) | Tri récursif d'un tableau, opérations bit à bit, expressions logiques |
| [TD2](TD2/) | Pointeurs, allocation dynamique, arguments `argc`/`argv`, passage par valeur/adresse, portée des variables |

## Compiler et lancer un TD

```bash
cd TDx
make
./Output/TDx <arguments>
```

(remplacer `TDx` par `TD1`, `TD2`, ...)

`make clean` supprime les fichiers compilés.

Les arguments attendus sont indiqués dans le `README.md` de chaque TD.

## Prérequis

- `gcc`
- `make`
