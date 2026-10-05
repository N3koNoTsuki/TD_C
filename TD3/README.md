# TD3 - C

## Compilation

```bash
make
```

L'exécutable est généré dans `Output/TD3`.

Pour nettoyer :

```bash
make clean
```

## Exécution

```bash
./Output/TD3
```

Aucun argument. Le programme demande de saisir une fiche élève au clavier : nom, année de naissance, nombre de notes (`MAXNOTE` au maximum), puis les notes (entre 0 et 20).

## Contenu

- **Exercice 1.1** : définition du type structuré `Eleve` (nom, année de naissance, notes).
- **Exercice 1.2** : saisie (`saisirfiche`) et affichage (`afficherfiche`) d'une fiche élève.
- **Exercice 1.3** : calcul de la moyenne des notes (`Moyenne`).
- **Exercice 2.1** : structures avec un champ pointeur (`struct S1`) et un champ tableau (`struct S2`).
- **Exercice 2.2** : copie de structures par affectation : seul le pointeur est copié pour `S1`, tout le tableau pour `S2`.
- **Exercice 2.3** : conséquence de la copie : modifier `v11.ch` modifie aussi `v12.ch`, mais pas pour `S2`.

## Fichiers

- `main.c` : programme principal
- `function.c` : fonctions des exercices (`saisirfiche`, `afficherfiche`, `Moyenne`)
- `header.h` : type `Eleve`, structures `S1`/`S2`, constantes `MAXNOTE`/`MAXNAME`, couleurs ANSI et prototypes
- `Makefile` : compilation
