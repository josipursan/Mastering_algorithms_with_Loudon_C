# Pointer manipulation  

-as with other variables/data types, never assume a pointer is pointing to anything useful until it is explicitly set  
-dangling pointers - pointers that point to invalid addresses; common user generated pointer error  

-pointers generally occupy one machine word, but to avoid portability issues you should never assume they have a specific size; size varies also according to compiler settings and type specifiers  

-*REMEMBER* : when we declare a pointer, space is allocated only for the pointer itself; no space is allocated for the data the pointer references  
    &nbsp;&nbsp;&nbsp;-storage for data is allocated by declaring a variable for it, or by allocating storage dynamically at runtime (*malloc, calloc*)  

-one important usage of pointers is when passing arrays to functions  
    &nbsp;&nbsp;&nbsp;&nbsp;-both of these examples are valid :   
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int f1(int a[])`  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int f1(int *a)`  
    &nbsp;&nbsp;&nbsp;&nbsp;-both examples say that we are passing a pointer to array, ie. the first element of array; it is written just a bit differently  

-when defining a function that accepts a multidim array as a parameter, all dimensions, except for the first dimension, must be specified. Why?  
    &nbsp;&nbsp;&nbsp;-because, for example, if we have a 2x2 matrix, in memory it is actually stored in a *row per row* fashion, meaning that the first we have stored `(0,0)`, then `(0,1)`, then `(1,0)`, and then lastly `(1,1)`  
    &nbsp;&nbsp;&nbsp;-this means that the first dimension becomes irrelevant - we only have to know the seconds dimension (*rows* in this case, or to be more precise, how many elements there are per row) in order to successfully navigate this 2D array  

## 2.4.2 Pointers to pointers as parameters  

-pointers are often used as parameters to functions if a function must modify a pointer passed to it  
-to do this, a function is passed a pointer to the pointer  
-consider function `int list_rem_next(List *list, ListElmt *element, void **data)` :  
    &nbsp;&nbsp;&nbsp;-since the operation must modify the pointer *data* to make it point to the data we want to remove, we must pass the address of the pointer *data* in order to simulate *call-by-reference* param passing  
    &nbsp;&nbsp;&nbsp;-ie. because function `void list_destroy(List *list)` uses `int list_rem_next(List *List, ListElmt *element, void **data)` to remove the node from list, and get the data from the node so that `list_destroy()` can properly `free()` it, `list_destroy()` must pass a pointer to `list_rem_next()`, or to be more precise, it must pass address of the pointer, like so : `(void**)&data`
    &nbsp;&nbsp;&nbsp;-then when we have the data in `list_rem_next()`, we must dereference this double pointer we were given, like so : `*data = element->next->data`  