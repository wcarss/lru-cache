#ifndef _aug2011_hash_h
#define _aug2011_hash_h

#include "list.h"
#define KEY_SIZE 64
#define HASH_SIZE 100

typedef struct Hash {
   List *storage[HASH_SIZE];
   int size;
}Hash;

Hash *hash_create();
void hash_destroy(Hash *h);
void hash_add(Hash *h, char *key, int value, Node *ptr);
Node *hash_get(Hash *h, char *key);
void hash_del(Hash *h, char *key);
int key_to_hash(char *key);
#endif
