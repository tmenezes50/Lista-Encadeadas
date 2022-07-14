#include "colection.h"
#include <stdio.h>
#include "account.h"
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

Colection *colCreate(int n) {
    Colection *c;
    if (n > 0) {
        c = (Colection *)malloc(sizeof(Colection));
        if (c != NULL) {
            c->itens = (void * *)malloc(sizeof(void *)* n);
            if(c->itens != NULL) {
                c->numItens = 0;
                c->maxItens = n;
                c->cur = 0;
                return c;
            }
            free(c);
        }
    }
    return NULL;
}

void *colDestroy(Colection *c) {
    if (c!=NULL) {
        if(c->numItens == 0) {
            free(c->itens);
            free(c);
        }
    }
}

int colInsert(Colection *c, void *item) {
    if(c != NULL) {
        if(c->numItens < c->maxItens) {
            c->itens[c->numItens] = item;
            c->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *colRemove(Colection *c, void *key) {
    int i, j; 
    void *data;
    if (c == NULL) {
        return NULL;
    }

    if(c->numItens <= 0) {
        return NULL;
    }

    for(i=0; i< c->numItens; i++) {
        if (c->itens[i] == key) {
            data = c->itens[i];
            for (j=i; j < c->numItens; j++) {
                c->itens[j] = c->itens[j+1];
            }
            c->numItens--;
            return data;
        }
    }
}

void *colClear(Colection *c) {
    int i;
    if (c != NULL) {
        if (c->maxItens > 0) {
            for (i=0; i <= c->numItens; i++) { 
                colRemove(c, c->itens[0]);
            }
        }
    }
}

void *colQuery(Colection *c, void *key, int (*cmp)(void*, void*)) {
    int i; // contador
    if (c != NULL) {
        if(c->maxItens > 0) {
            for (i=0; i < c->maxItens; i++) {
                if (cmp (c->itens[i], key) == TRUE) {
                    return c->itens[i];
                }
            }
            return NULL;
        }
        return NULL;
    }
    return NULL;
}

int paraString(void *item, void *key) {
    account*conta_auxiliar = (account*)item;
    if (strcmp(conta_auxiliar->cliente,(char *)key) == FALSE) {
        return  TRUE;
    }
    return FALSE;
}

int paraInt(void *item, void *key) {
    account*conta_auxiliar = (account*)item;
    if (conta_auxiliar->numConta == *(int *)key) {
        return TRUE;
    }
    return FALSE;
}

int paraFloat(void *item, void *key) {
    account*conta_auxiliar = (account*)item;
    if (conta_auxiliar->saldo == *(float *)key) {
        return TRUE;
    }
    return FALSE;
}