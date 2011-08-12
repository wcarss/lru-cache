#include "lru_cache.h"

int get(Hash *h, List *l, char *key)
{
    int value = 0;
    Node *n = NULL;
    if(NULL != (n = hash_get(h, key)))
    {
        value = n->value;
        list_remove_node(l, n);
        list_push(l, key, value, NULL);
        hash_add(h, key, value, l->root); 
    }
    return value;
}

void set(Hash *h, List *l, char *key, int value)
{
    Node *n = NULL;
    if(NULL != (n = hash_get(h, key)))
    {
        list_remove_node(l, n);
    }
    list_push(l, key, value, NULL);
    hash_add(h, key, value, l->root);
}

void del(Hash *h, List *l, char *key)
{
    Node *n = NULL;
    if(NULL != (n = hash_get(h, key)))
    {
        list_remove_node(l, n);
    }
    hash_del(h, key);
}
