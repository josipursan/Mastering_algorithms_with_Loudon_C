#ifndef LIST_H
#define LIST_H

#include <stdio.h
#include <stdlib.h>

// Structure for linked list elements
typedef struct ListElmt
{
    void *data;
    struct ListElmt *next;
};

// Structure representing the linked list
typedef struct List
{
    int size;

    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    ListElmt *head;
    ListElmt *tail;
}List;

// Public interfaces
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElmt *element, const void *data); //list_insert_next
int list_rem_next(List *list, ListElmt *element, void **data);  //list_remove_next

#define list_size(list) ((list)->size);
#define list_head(list) ((list)->head);
#define list_tail(list) ((list)->tail);
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0);
#define list_is_tail(list, element) ((element) == (list)->tail ? 1 : 0);
#define list_data(element) ((element)->data);
#define list_next(element) ((element)->next);

#endif