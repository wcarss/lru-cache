#include "util.h"
#include "list.h"

List *list_create()
{
    List *l = NULL;
    
    if (NULL == (l = calloc(sizeof(List), 1)))
    {
        perror("Failed to allocate new list in list_create.");
        return NULL;
    }
    
    l->root = NULL;
    l->current = NULL;

    return l;
}

void list_destroy(List *l)
{
    if (NULL == l)
    {
        perror("Null list passed into list_destroy.");
        return;
    }
    
    while(NULL != l->root)
        list_remove_node(l, l->root);

    free(l);
}

void list_remove_node(List *l, Node *n)
{
    Node *prev = NULL, *next = NULL;

    if (NULL == l)
    {
        perror("Null list passed to remove_node.");
        return;
    }

    if (NULL == l->root)
    {
        perror("Empty list passed to remove_node.");
        return;
    }

    if (NULL == n)
    {
        perror("Null node passed to remove_node.");
        return;
    }

    prev = n->prev;
    next = n->next;

    if (NULL == prev)
    {
        l->root = next;
    }
    else
    {
        prev->next = next;
    }

    if (NULL != next)
    {
        next->prev = prev;
    }

    node_destroy(n);
    l->current = l->root;
}

void list_print(List *l)
{
    if (NULL == l)
    {
        perror("Null list passed into print_list.");
        return;
    }

    if (NULL == l->root)
    { 
        perror("Empty list passed into print_list.");
        return;
    }
    
    l->current = l->root;
    while(l->current != NULL)
    {
        printf("(%s, %d)", l->current->key, l->current->value);
        if(l->current->next != NULL) printf(", ");
        l->current = l->current->next;
    }
    printf("\n");
    l->current = l->root;
}

void list_push(List *l, char *key, int value, void *ptr)
{
    Node *n = NULL;

    if (NULL == l)
    {
        perror("Null list passed into list_push.");
        return;
    }

    if (NULL == key)
    {
        perror("Null key passed into list_push.");
        return;
    }

    if (NULL == (n = node_create(key, value, ptr)))
    {
        perror("Failed to allocate new node in list_push.");
        return;
    }

    if(NULL != l->root)
        l->root->prev = n;
        
    n->next = l->root;
    l->root = n;
    l->current = l->root;
}

Node *list_find(List *l, char *key)
{
    Node *n = NULL;

    if(NULL == l)
    {
        perror("Null list passed into list_find.");
        return NULL;
    }

    if(NULL == key)
    {
        perror("Null key passed into list_find.");
        return NULL;
    }

    l->current = l->root;
    while(l->current != NULL && 0 != strcmp(key, l->current->key))
    {
        l->current = l->current->next;
    }

    n = l->current;
    l->current = l->root;
    return n;
}
