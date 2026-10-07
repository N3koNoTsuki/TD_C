#include "header.h"


int main(int argc, char *argv[]){

    //allocation
    file *f = malloc(sizeof(file));
    init_FIFO(f);

    char selection[10];
    char message[TAILLE_MSG] = "";
    int idx = 0;
    int FlagStop =0;

    while (FlagStop != -1){
        affichage(f, message);
        scanf("%s", selection);
        idx = strtol(selection, NULL, 10);
        if (idx >3) {
            snprintf(message, TAILLE_MSG, ROUGE "Indexe trop grand : %d" RESET, idx);
        }
        else if (idx<0) {
            snprintf(message, TAILLE_MSG, ROUGE "Indexe trop petit : %d" RESET, idx);
        }
        else {
            FlagStop = executerChoix(f, idx, message);
        }
    }
    
    viderFIFO(f);
    free(f);
    return 0;
}

