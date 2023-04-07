#include <stdlib.h>

typedef struct hash_table {
    unsigned long int size;
    void **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size) {
    // Allocate memory for the hash table
    hash_table_t *table = malloc(sizeof(hash_table_t));
    if (table == NULL) {
        // If memory allocation failed, return NULL
        return NULL;
    }

    // Allocate memory for the array
    table->array = calloc(size, sizeof(void *));
    if (table->array == NULL) {
        // If memory allocation failed, free the hash table and return NULL
        free(table);
        return NULL;
    }

    table->size = size;
    return table;
}

