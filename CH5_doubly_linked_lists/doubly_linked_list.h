/* 
    Remember that the most common #defin guard naming convention states that 
    your guard should be named PATH_TO_FILE_H.
    E.g. /pero/zdero/spongebob/myHeader.h means #define guard will be : #define PERO_ZDERO_SPONGEBOB_MYHEADER_H.

    The way you named this file is in direct conflict with this naming convention.
*/

#ifndef DLIST_H  
#define DLIST_H

#include <stdlib.h>

// Structure representing each element in the doubly linked list
typedef struct DListElmt
{
    void *data;
    void *next;
    void *prev;
}DListElmt;

// Strucutre representing the doubly linked list
typedef struct DList
{
    int size;

    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);

    DListElmt *head;
    DListElmt *tail;
}DList;


// Public interfaces ˇ
void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt *element, const void **data);
int dlist_ins_prev(DList *list, DListElmt *element, const void **data);
int dlist_remove(DList *list, DListElmt *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev == NULL ? 1 : 0)    // if an element is head, when creataing the list, or adding the element to list, we must set prev pointer to NULL, thus indicating it is HEAD
#define dlist_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif