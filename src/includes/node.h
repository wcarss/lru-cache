#ifndef _aug2011_node_h
#define _aug2011_node_h
#include "util.h"

typedef struct Node {
   struct Node *next;
   struct Node *prev;
   int value;
   void *ptr;
   char key[STRING_SIZE];
}Node;

Node *node_create(char *key, int value, void *ptr);
void node_destroy(Node *n);
#endif
