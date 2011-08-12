#include "hash.h"
#include "list.h"
#include "lru_cache.h"

int main()
{
    /* Simple example usage*/
    Hash *h = hash_create();
    List *l = list_create();

    set(h, l, "a", 1);
    set(h, l, "b", 2);
    set(h, l, "c", 3);
    printf("%d\n", get(h, l, "a"));
    list_print(l);
    del(h, l, "b");
    list_print(l);

    list_destroy(l);
    hash_destroy(h);
    return 0;
}
