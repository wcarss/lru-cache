#ifndef _aug2011_lru_cache_h
#define _aug2011_lru_cache_h
#include "hash.h"
#include "list.h"

int get(Hash *h, List *l, char *key);
void set(Hash *h, List *l, char *key, int value);
void del(Hash *h, List *l, char *key);
#endif
