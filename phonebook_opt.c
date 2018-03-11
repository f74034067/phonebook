#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

unsigned int bkdr_hash(const char *key)
{
    unsigned int seed = 31;
    unsigned int hash = 0;
    while (*key) {
        hash = hash * seed +(*key++);
    }
    return (hash % MAX_TABLE_SIZE);
}

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    /* TODO: implement */
    unsigned int index = bkdr_hash(lastName);
    entry *p = tableHead[index]->pNext;
    while (p != NULL) {
        if (strcasecmp(lastName, p->lastName) == 0) {
            return p;
        }
        p = p->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* TODO: implement */
    /* allocate memory for the new entry and put lastName */
    unsigned int index = bkdr_hash(lastName);
    entry *p = tableCurrent[index];
    p->pNext = (entry *) malloc(sizeof(entry));
    p = p->pNext;
    strcpy(p->lastName, lastName);
    p->pNext = NULL;
    tableCurrent[index] = p;
    return e;
}
