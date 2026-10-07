# ---------------------------------------------------------------
# Variables de compilation
# ---------------------------------------------------------------

# Compilateur utilisé
CC = gcc
# Options passées à la compilation (.c -> .o) :
#   -g    : ajoute les infos de debug (pour gdb / valgrind)
#   -Wall : active la plupart des avertissements
CFLAGS =  -g -Wall
# Options passées à l'édition de liens (.o -> exécutable)
LDFLAGS = -g -Wall

# ---------------------------------------------------------------
# Fichiers du projet
# ---------------------------------------------------------------

# Dossier où sont rangés les .o et l'exécutable
OUTDIR  = Output
# Exécutable final à produire
PROGS   = $(OUTDIR)/TP1
# Liste des fichiers sources
SRCS	= main.c function.c
# Liste des fichiers objets, déduite de SRCS :
# chaque "xxx.c" devient "Output/xxx.o"
OBJS	= $(SRCS:%.c=$(OUTDIR)/%.o)

# ---------------------------------------------------------------
# Règles
# ---------------------------------------------------------------

# Cible par défaut (lancée par un simple "make") : construit le programme
all: $(PROGS)

# Édition de liens : assemble tous les .o en un exécutable
#   $^ = toutes les dépendances (les .o)
#   $@ = la cible (Output/TP1)
$(PROGS): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

# Règle générique de compilation : Output/xxx.o à partir de xxx.c
#   -c  = compile sans faire l'édition de liens
#   $<  = la première dépendance (le .c)
#   "| $(OUTDIR)" = dépendance "order-only" : le dossier doit exister
#   avant de compiler, mais sa date de modif ne force pas de recompilation
$(OUTDIR)/%.o: %.c | $(OUTDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crée le dossier de sortie s'il n'existe pas (-p : pas d'erreur s'il existe)
$(OUTDIR):
	mkdir -p $(OUTDIR)

# "make clean" : supprime le dossier de sortie (et donc .o + exécutable)
clean:
	rm -rf $(OUTDIR)

# Dépendances vers les headers : si header.h ou constante.h change,
# les .o concernés sont recompilés
$(OUTDIR)/main.o : header.h constante.h
$(OUTDIR)/function.o : header.h constante.h
