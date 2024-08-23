#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void list_init(List *list, void (*destroy)(void *data))
{
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element;

    if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
    {
        printf("Issue mallocing space for new_element\n");
        return -1;
    }

    new_element->data = (void *)data;

    if(element == NULL) // If the given element is HEAD, ...
    {
        if(list_size(list) == 0)    // If the given list is empty (size = 0)
        {
            list->tail = new_element;   // Set the list tail to new_element
        }
        new_element->next = list->head; // Point new_element to the only next possible element : head
        list->head = new_element;   // Point the list head to new_element
    }
    else
    {
        if(element->next == NULL)   // If tail has not been set yet, ... (we compare to NULL because tail gets set to NULL in init)
        {
            list->tail = new_element;
        }
        new_element->next = element->next;  // Because we are inserting new_element after element, new_element will then be pointing to the list member to which element was previously poiniting
        element->next = new_element;    // element now must point to our new_element that we are inserting between element, and the previously following element
    }

    list->size++;
    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
    ListElmt *old_element;

    if(list_size(list) == 0)    // Before any removal, check if the list is 0
    {
        printf("Given list has no elements.\n");
        return -1;
    }

    if(element == NULL) // If the given element is at HEAD, ie. is using NULL to indicate he wants to remove HEAD element
    {
        *data = list->head->data;   // What is the point of this? If we want to remove the HEAD element, and set the element following HEAD as the new head, only the two line below are necessary.
        old_element = list->head;   // This assignment is done to have only one free at the end of function - could've been done here
        list->head = list->head->next;  // This line is used to set the new HEAD element
    }
    else
    {
        if(element->next == NULL)
        {
            printf("No more elements left after given element.\nGiven element is tail.\n");
            return -1;
        }
        *data = element->next->data;
        old_element = element->next;    // Assigning next element from our passed element for removal
        element->next = element->next->next;    // Pointing our passed element to the element after its first following element
    }

    free(old_element);
    list->size--;

    return 0;
}

void list_destroy(List *list)
{
    void *data;

    while(list_size(list) > 0)  // While there are elements left in list
    {
        if(list_rem_next(list, NULL, (void**)&data) == 0 & list->destroy != NULL)   // If list_rem_next removes the element successfully, and if list->destroy has not reached NULL (ie. HEAD/TAIL), ...
        {
            list->destroy(data);    // ... use the destroy function passed to list during init
        }
    }

    memset(list, 0, sizeof(List));
}