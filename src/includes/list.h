#ifndef _aug2011_list_h
#define _aug2011_list_h
#include "node.h"

typedef struct List {
   Node *root;
   Node *current;
}List;

List *list_create();
void list_destroy(List *l);
void list_remove_node(List *l, Node *n);
void list_print(List *l);
void list_push(List *l, char *key, int value, void *ptr);
Node *list_find(List *l, char *key);
#endif
