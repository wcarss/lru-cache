#include "util.h"
#include "hash.h"

Hash *hash_create()
{
    int i = 0;
    Hash *h = NULL;

    if(NULL == (h = calloc(sizeof(Hash), 1)))
    {
        perror("Failed to allocate hash in hash_create.");
        return NULL;
    }

    h->size = HASH_SIZE;
    for (i = 0; i < h->size; i++)
    {
        if(NULL == (h->storage[i] = list_create()))
        {
            perror("Failed to allocate list in hash_create.");
            return NULL;
        }
    }

    return h;
}

void hash_destroy(Hash *h)
{
    int i;

    if(NULL == h)
    {
        perror("Null hash passed into hash_destroy.");
        return;
    }

    for (i = 0; i < h->size; i++)
    {
        list_destroy(h->storage[i]);
        h->storage[i] = NULL;
    }

    h->size = 0;
    free(h);
}

void hash_add(Hash *h, char *key, int value, Node *ptr)
{
    int access_value = key_to_hash(key);
    list_push(h->storage[access_value], key, value, ptr);
}

Node *hash_get(Hash *h, char *key)
{
    Node *n = NULL;
    int access_value = key_to_hash(key);
    n = list_find(h->storage[access_value], key);
    return n ? n->ptr : NULL;
}

void hash_del(Hash *h, char *key)
{
    int access_value = key_to_hash(key);
    Node *n = list_find(h->storage[access_value], key);
    list_remove_node(h->storage[access_value], n);
}

int key_to_hash(char *key)
{
    int i;
    int hash_value = 0;

    for (i = 0; key[i] != '\0'; i++)
    {
        hash_value += key[i] % 2 == 0 ? key[i] * 3 : key[i] * 7;
    }
    hash_value = hash_value % HASH_SIZE;
    /*printf("%s hashed to %d\n", key, hash_value);*/
    return hash_value;
}
