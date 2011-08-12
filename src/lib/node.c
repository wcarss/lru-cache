#include "util.h"
#include "node.h"

Node *node_create(char *key, int value, void *ptr)
{
    Node *n = NULL;
    
    if (NULL == key)
    {
        perror("Null key passed into node_create.");
        return NULL;
    }
    
    if(NULL == (n = calloc(sizeof(Node), 1)))
    {
        perror("Failed to allocate new node in node_create.");
        return NULL;
    }
    
    n->next = NULL;
    n->prev = NULL;
    n->value = value;
    n->ptr = ptr;
    strncpy(n->key, key, STRING_SIZE);

    return n;
}

void node_destroy(Node *n)
{
    if (NULL == n)
    {
        perror("Null node passed into node_destroy.");
        return;
    }

    n->next = NULL;
    n->prev = NULL;
    n->value = 0;
    n->ptr = NULL;
    memset(n->key, 0, STRING_SIZE);
    free(n);
}
