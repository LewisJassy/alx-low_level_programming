#include "hash_tables.h"
#include <stdlib.h>

hash_table_t *hash_table_create(unsigned long int size) {
    hash_table_t *array = (hash_table_t*)malloc(sizeof(hash_table_t));
    size_t i;
    
    // Allocate memory for the array of pointers (buckets) inside the hash table
    hash_table_t* new_table = (hash_table_t*)malloc(sizeof(hash_table_t));
    if (size == 0){
        return NULL;
    }
    if (new_table == NULL){
        return NULL;
    }
    if (array == NULL){
        free(new_table);
        return NULL;
    }

    // Initiallize the hash table with the provided size
    new_table->array = array;
    new_table->size = size;

    // Intialize each bucket in the array to NULL
    for (i  = 0; i < size; i++){
        *(array + 1) = NULL;
    }
    return new_table;
}