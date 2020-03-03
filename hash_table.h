#pragma once

typedef struct HashTable HashTable;

#ifdef __cplusplus
extern "C" {
#endif
// new
    HashTable *hash_table_new();
// delete
    void hash_table_delete(HashTable *ht);
//add or update 
    #define hash_table_put(ht,key,value) hash_table_put2(ht,key,value,NULL);
    int has_table_put2(HashTable *ht,char *key ,void *value,void(*free_value)(void *));
// getValue
    void *hash_table_get(HashTable *ht,char *key);
// remove
    void hash_table_rm(HashTable *ht,char *key);
#ifdef __cplusplus
}
#endif