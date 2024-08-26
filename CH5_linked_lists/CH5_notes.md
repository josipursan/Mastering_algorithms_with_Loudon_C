# CH5 - Linked lists

-note to self regarding the implementation shown in book : some functions seem unnecessary, or at least the way their functionality has been implemented seems unnecessary  

-some functions considered unnecessary :  
    &nbsp;&nbsp;&nbsp;-`void list_init(List *list, void (*destroy)(void *data))` - why take care of destroying/deallocing memory in list_init? Store a pointer to HEAD to some variable, which will then be supplied to dealloc function.
    <br></br>
    &nbsp;&nbsp;&nbsp;-`int list_ins_next(List *list, ListElmt *element, const void *data) and int list_rem_next(List *list, ListElmt *element, void **data)` - passing pointer to the whole list is not necessary, instead `List *list` can be replaced by a `void *ptr_to_element_from_which_we_want_to_insert`  
    <br></br>
    &nbsp;&nbsp;&nbsp;-`ListElmt *list_head(const List *list) and ListElmt *list_tail(const List *list)` - having specific functions to find head and tail is not necessary, except if finding head and tail is necessary from scopes where head and tail ptr vars are not accessible (*this is probably here only for learning purporses*); head and tail addresses should be stored to ptr normal ptr vars

<br></br>

-structure *ListElmt* represents an individual element of a linked list (one node)  
-structure *List* is the linked list data structure  
    &nbsp;&nbsp;&nbsp;&nbsp;-*List* structure consists of 5 members :  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-*size* is the number of elements in the list  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-*match* is a member not used by linked lists, but by datatypes that will be derived later from linked lists  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-*destroy* is the encapsulated destroy function passed to *list_init*  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-*head* is a pointer to the first element of the linked list  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-*tail* is a pointer to the tail (last) element of the list  


## Implementation  

-bear in mind that passing `NULL` as `element` to functions such as `list_ins_next(), list_rem_next()` indicates that the new element should be inserted at the head  

#### Comments on `list_destroy()` and `list_rem_next()` implementations  
-note that in structure `ListElmt` you have a `void *data` element  
-if all you do is `free(old_element)`, without freeing whatever is hidden in `void *data`, you will create a resource leak  
-this is exactly why `list_rem_next()` has parameter `void **data` in its signature; because once `list_rem_next()` does `free(old_element)`, it will return the pointer to data of this old element to `list_destroy()`, where using a function pointer that was passed we will access that data and free it properly to avoid resource leaks  
-what if the `data` pointer is actually a field of pointers, each pointing to a struct, for which appropriate memory was malloced?; remember : for every malloc you need a free, no matter how deep it goes

-approach outlined in the book is a bit more generic, and is the exact same thing this guy on StackOverflow also wondered about : https://stackoverflow.com/questions/67346917/freeing-data-in-a-linked-list  
  
-however, what if freeing of this data wasn't done in `list_destroy()`, but instead in `list_rem_next()`?  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-of course this would mean that function signature need to change : `list_rem_next()` would now need to have the function pointer as argument - this function pointer represents the specific data removal function; `list_init()` would lose this argument because author's implementation passes the function for data destruction during init phase, and this function then gets set to `destroy` element in `List` structure  
    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  
    `void_list_init(List *list)` --> `void (*destroy)(void *data)` is removed because we don't want to pass function pointer to `list_init()`  
    `list_rem_next(List *list, ListElmt *element, void (*destroy)(void *data))` --> `void *data` argument gets removed because we no longer have to pass a pointer to this function to get back the data, to be able to remove the `free()` the data properly  
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-`void (*destroy)(void *data)`function pointer now becomes argument for `list_rem_next()` because `list_rem_next()` removes the node from the list, and frees the data in node properly