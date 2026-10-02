#include "header.h"


void init_FILO(filo *filo){
    filo->val = 0;
    filo->next = NULL;
}

void Insert(filo *filo){
}

void Del(filo *filo){
    free(filo);
}