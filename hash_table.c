
#include"hash_table.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define Table_Size (1024*1024)

struct kv{
    struct kv *next;
    char *key;
    void *value;
    void (*free_value)(void *);
};

// hashTable
struct HashTable{
    struct kv **table;
};

static void init_kv(struct kv *kv){
    kv->next = NULL;
    kv->key = NULL;
    kv->value = NULL;
    kv->free_value = NULL;
}

static void free_kv(struct kv* kv){
    if (kv)
    {
        if (kv->free_value)
        {
            kv->free_value(kv->value);
        }
        free(kv->key);
        kv->key = NULL;
        free(kv);
    }
}

// times33 hash function
static unsigned int hash_33(char *key){
    unsigned int hash = 0;
    while (*key)
    {
        hash=(hash<<5)+hash+*key++;
    }
    return hash;
}
// new 
HashTable* hash_table_new(){
    HashTable *ht = malloc(sizeof(HashTable));
    if (NULL==ht)
    {
        hash_table_delete(ht);
        return NULL;
    }
    ht->table = malloc(sizeof(struct kv*)*Table_Size);
    if (NULL==ht->table)
    {
        hash_table_delete(ht);
        return NULL;
    }
    memset(ht->table,0,sizeof(struct kv*)*Table_Size);
    
    return ht;
}

// delete
void hash_table_delete(HashTable *ht){
    if (ht)
    {
        if (ht->table)
        {
            int i = 0;
            for (i = 0; i < Table_Size; i++)
            {
                struct kv *p = ht->table[i];
                struct kv *q = NULL;
                while (p)
                {
                    q = p->next;
                    free_kv(p);
                    p = q;
                }
                
            }
            free(ht->table);
            ht->table = NULL;
        }
        free(ht);
    }
}

// insert
int hash_table_put2(HashTable* ht, char* key, void* value, void(*free_value)(void*)){
    int i = hash_33(key) % Table_Size;
    struct kv *p = ht->table[i];
    struct kv *pre = p;
    
    while (p)
    {
        // already stored
        if (strcmp(p->key,key)==0)
        {
            if (p->free_value)
            {
                p->free_value(p->free_value);
            }
            p->value = value;
            p->free_value = free_value;
            break;
        }
        pre = p;
        p = p->next;
    }
    // has not stored
    if (p==NULL)
    {
        char *kstr = malloc(strlen(key)+1);
        if (kstr==NULL)
        {
            return -1;
        }
        struct kv *kv = malloc(sizeof(struct kv));
        if (NULL == kv)
        {
            free(kstr);
            kstr = NULL;
            return -1;
        }
        init_kv(kv);
        kv->next = NULL;
        strcpy(kstr,key);
        kv->key = kstr;
        kv->value = value;
        kv->free_value = free_value;
        
        if (pre==NULL)
        {
            ht->table[i] = kv;
        }else
        {
            pre->next = kv;
        }
    }
    return 0;
}

void *hash_table_get(HashTable *ht,char* key){
    int i = hash_33(key) % Table_Size;
    struct kv *p = ht->table[i];
    while (p)
    {
        if(strcmp(key,p->key)==0){
            return p->value;
        }
        // 链式冲突解决
        p = p->next; 
    }
    return NULL;
    
}

void hash_table_rm(HashTable *ht,char*key){
    int i = hash_33(key) % Table_Size;
    struct kv *p = ht->table[i];
    struct kv *pre = p;
    while (p)
    {
        if (strcmp(key,p->key)==0)
        {
            free_kv(p);
            if(p==pre){
                ht->table[i] = NULL:
            }else{
                pre->next = p->next;
            }
        }
        pre = p;
        p = p->next;   
    }
}


