#ifndef _COLECTION_H_
#define _COLECTION_H_

typedef struct _colection_ {

    int cur;
    int numItens;
    int maxItens;
    void **itens;
    
}Colection;

Colection *colCreate(int max_itens);
int colInsert(Colection *c, void *item);
void *colRemove(Colection *c, void *key);
void *colQuery(Colection *c, void *key, int(*cmp)(void*, void*));
void *colDestroy(Colection *c);
void *colClear(Colection *c);
int paraString(void *item, void *key);
int paraInt(void *item, void *key);
int paraFloat(void *item, void *key);


#endif
