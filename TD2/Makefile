CC = gcc
CFLAGS =  -g -Wall 
LDFLAGS = -g -Wall  

OUTDIR  = Output
PROGS   = $(OUTDIR)/TD2
SRCS	= main.c function.c
OBJS	= $(SRCS:%.c=$(OUTDIR)/%.o)

all:	$(PROGS)

$(PROGS): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OUTDIR)/%.o: %.c header.h | $(OUTDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR):
	mkdir -p $(OUTDIR)

clean:
	rm -rf $(OUTDIR)

$(OUTDIR)/main.o : header.h 
$(OUTDIR)/function.o : header.h