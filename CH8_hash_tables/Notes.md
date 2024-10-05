# Hash tables  
-a hash table consists of an array, in which data is accessed via a special index called a *key*  
  
-why are then hash tables so special?  
They are special because these indices are not random.  
We use a *hash function* to generate a *key* specific for the given value.  
The given value then gets stored in the array, with the *key* value being used as its array index.  
This allows us to quickly access each array value.  
Do not misunderstand what is written : we have key-value pairs, and the key gets used as the hashing function input, which in turn gives us what the index of value in the array will be  
  
-a hash table is **directly addressed** if the hash function guarantees no two keys will generate the same hash value  
  
-**collision** - when two different keys map to the same array location  (ie. the hash function outputs the same hash value, meaning two different keys generate the same hash)  
  
-**chained hash tables** - hash tables that store data in buckets  
&nbsp;&nbsp;&nbsp;-buckets are simply linked lists  
&nbsp;&nbsp;&nbsp;-chaining is one of the ways collisions can be overcome  
&nbsp;&nbsp;&nbsp;-if we generate a hash value for some key A, and after some time, for some key D we generate the same hash value, the collision gets resolved so that the second value we want to store actually links to the first so that when you reach array index for key A, the value belonging to key A is stored there, but it also points to value for key D, thus making both values reachable  
  
-**open-addressed hash tables** - hash tables that do NOT use buckets to avoid collisions  
&nbsp;&nbsp;&nbsp;-often times linear probing can be used, especially if we are not dealing with a lot of elements  

TO DO : 8.1 Description of Chained Hash Tables