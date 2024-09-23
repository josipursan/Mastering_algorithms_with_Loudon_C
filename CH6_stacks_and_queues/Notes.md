# CH6 - stacks and queues  
-**stacks** - efficient data structures for storing and retrieving data in a last in, first out manner (LIFO) order; this allows us to retrieve data in the opposite order to storage order  
-**queues** - data structures used for storing and retrieving data in first in, first out manner (FIFO); this allows us to retrieve the data in the same order as it was stored  
-despite the fact that both stacks and queues effectively use singly-linked lists to achieve their desired structure, you could say that the usage of singly linked lists as such is hidden behind a layer of functions which receive only the pointer to HEAD or TAIL of the stack/queue, and pointer to data that we want to store to stack/queue  
&nbsp;&nbsp;&nbsp;&nbsp;-handling of singly-linked list nodes is done in those function, and is thus hidden from users
  
## 6.1. - Description of stacks  
-*push* - the action of putting a new element on top of the stack  
-*pop* - the action of removing an element from the top  
-*peek* - action of just looking at the element sitting on top of the stack  
  
-naturally, stacks are implemented using linked lists, because it is actually just a linked list with specific behaviour (by this I mean that when pushing new elements they are pushed only to the HEAD, when popping we are popping only from the HEAD)  
  
## 6.4. - Description of Queues  
-comparable to queues at the post office - first come, first serve  
-*enqueue* - to place an element at the tail of the queue  
-*dequeue* - to remove an element from the HEAD  
-*peek* - the act of inspecting the element at the HEAD of a queue without actually removing it  