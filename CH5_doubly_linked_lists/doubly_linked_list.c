#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "doubly_linked_list.h"

void dlist_init(DList *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

void dlist_destroy(DList *list)
{
    void *data;

    while(dlist_size(list) > 0)
    {
        if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0 && list->destroy != NULL)  // if dlist_remove is returning 0 (ie. everything is running ok), and list->destroy is not NULL (ie. some function has been assigned here, and this function frees the data properly), invoke the function pointer
        {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(DList));
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
    DListElmt *new_element;

    if(element == NULL && dlist_size(list) != 0)
    {
        printf("Given element is null\n");
        return -1;
    }

    if((new_element = (DListElmt*)malloc(sizeof(DListElmt))) == NULL)
    {
        printf("Malloc for new_element failed");
        return -1;
    }

    new_element->data = (void*)data;    //Assigning given data to the new list element
    
    if(dlist_size(list) == 0)   // if list is empty
    {
        list->head = new_element;
        list->tail = new_element;
        list->head->prev = NULL;
        list->tail->next = NULL;
    }
    else    // normal insertion, ie. list is not empty
    {
        new_element->next = element->next;
        new_element->prev = element;

        if(element->next == NULL) // if element->next is NULL, it means that element is tail of list
        {
            list->tail = new_element;
        }
        else
        {
            element->next->prev = new_element // list is : ACD; we are inserting B after A; we need to inform C that its new prev element is now B, not A, which is what we do in this line
        }
        element->next = new_element;
    }

    list->size++;

    return 0;
}

int dlist_ins_prev(DList *list, DListElmt *element, void *data)
{
    DListElmt *new_element;

    if(element == NULL && dlist_size(list) != 0)
    {
        printf("Given element is null\n");
        return -1;
    }

    if((new_element = (DListElmt*)malloc(sizeof(DListElmt))) == NULL)
    {
        printf("Malloc failed for new_element\n");
        return -1;
    }

    new_element->data = (void*)data;

    if(dlist_size(list) == 0)   // if list is empty
    {
        list->head = new_element;
        list->tail = new_element;
        list->head->prev = NULL;
        list->head->next = NULL;
    }
    else // list is not empty
    {
        new_element->next = element;
        new_element->prev = element->prev;

        if(element->next == NULL) // if given element is HEAD
        {
            list->head = new_element;
        }
        else
        {
            element->prev->next = new_element; // beacuse we are inserting new_element before element, we must point (element-1) to new_element            
        }
        element->prev = new_element;
    }

    list->size++;

    return 0;
}


int dlist_remove(Dlist *list, DListElmt *element, void **data)
{
    if(element == NULL || dlist_size(list) == 0)     // just a check to catch if given element is empty/doesn't exist, or if list is empty
    {
        printf("Element is NULL, or list is empty\n");
        return -1;
    }

    *data = element->data;

    if(element == list->head)    // if our given element is the list head, ...
    {
        list->head = element->next; // new list head becomes the element after our given element

        if(list->head == NULL)
        {
            list->tail == NULL;
        }
        else
        {
            element->next->prev = NULL;
        }
    }
    else    // normal removal, from anywhere in list
    {
        element->prev->next = new_element;

        if(element->next == NULL)   //if element is list tail, ...
        {
            list->tail = element->prev; // assign (element-1) as list tail
        }
        else
        {
            element->next->prev = element->prev;    // the previous element of (element+1) must be set to (element-1) because we are removing element
        }
    }

    free(element);

    list->size--;

    return 0;
}