#include<time.h>
#include "hash.h"

int main()
{
    int sum = 0, state_flag = -1, test_size = 0, word_size = 0, i = 0, j = 0, k = 0, zero_count = 0, hi = 0, li = 0, value = 0, min = 0x7A*7*KEY_SIZE, max = -1;
    char *word = NULL;
    int *stats = NULL;
    List *l = NULL;
    srand(time(NULL));

    test_size = rand() % HASH_SIZE + HASH_SIZE*2;
    stats = calloc(sizeof(int), HASH_SIZE);
    for (i = 0; i < test_size; i++)
    {
        word_size = rand() % KEY_SIZE;
        word = calloc(word_size, 1);
        for (j = 0; j < word_size-1; j++)
        {
            word[j] = rand() % 2 == 0 ? (rand() % 25) + 0x41 : (rand() % 25 + 0x61);
        }
        printf("%s", word);
        while (k < word_size)
        {
            k += 1;
        }
        while (k < KEY_SIZE)
        {
            printf(" ");
            k += 1;
        }
        k = 0;
        value = key_to_hash(word);
        stats[value] += 1;
        sum += value;
        printf("hashes to %d.\n", key_to_hash(word));
        free(word);
    }

    l = list_create();
    state_flag = -1;
    for (i = 0; i < HASH_SIZE; i++)
    {
        if (state_flag == -1 && stats[i] > 0)
        {
            state_flag = i;
        }
        else if (state_flag != -1 && stats[i] > 0)
        {
            value = i;
            if (stats[i] > max)
            {
                max = stats[i];
                hi = i;
            }
            if (stats[i] < min)
            {
                min = stats[i];
                li = i;
            }
        }
        else if (stats[i] == 0)
        {
            zero_count++;
            list_push(l, ".", i, NULL);
        }
    }
    printf("There were %d hashes.\n", test_size);
    printf("The average hash value was %g\n", (double)sum/(double)test_size);
    printf("min hash value was %d\n", state_flag);
    printf("max hash value was %d\n", value);
    printf("(of a theoretical range from %d to %d)\n", 0, HASH_SIZE-1);
    printf("most common number was %d (%d occurences)\n", hi, max);
    printf("least common number was %d (%d occurences)\n", li, min);
    printf("%d numbers did not occur. They are:\n", zero_count);
    l->current = l->root;
    while (l->current != NULL)
    {
       printf("%d", l->current->value);
       if (l->current->next != NULL)
       {
           printf(", ");
       }
       l->current = l->current->next;
    }
    printf("\n\nWoo, statistics!\n");
    list_destroy(l);
    free(stats);
    return 0;
}
