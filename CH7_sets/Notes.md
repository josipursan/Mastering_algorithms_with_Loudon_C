# CH7 - Sets  
-sets - collections of distinguishable objects (which are called *members*), grouped together because they are in some way related  
-sets possess two important properties :  
&nbsp;&nbsp;&nbsp;-their members are unordered  
&nbsp;&nbsp;&nbsp;-no members occur more than once (no duplicates)  
  
-some languages have intrinsic support for sets (such as Pascal and Python), while C does not have any support for sets (meaning everything has to be written for C)  
  
-some applications of sets :  
&nbsp;&nbsp;&nbsp;-data correlation - sets can be used to determine how many members of each observed set are members of the other group (ie. searching for set intersections)  
&nbsp;&nbsp;&nbsp;-set covering - creating a set composed of members where each members fulfills a predetermined role, thus creating the smallest possible valid set  
&nbsp;&nbsp;&nbsp;-relational algebra - think of SQL  
  
-sets are written with curly braces around them : `S = {1,2,3}`  
-empty set - set containing no members  
-two sets are considered equal if the possess exactly the same members (their order is irrelevant - only their presence is required)  
-a set S<sub>1</sub> is subset of S<sub>2</sub> if it contains all of the members of S<sub>2</sub>  
  
-**union** of two sets yield a new set, containing all members of the sets used to create union  
-**intersection** of two sets yields a new set, containing only the members present both in S<sub>1</sub> and S<sub>2</sub>  
-**difference** of two sets, S<sub>1</sub> and S<sub>2</sub>, yields a set, containing all S<sub>1</sub> members, without any S<sub>2</sub> members  
&nbsp;&nbsp;&nbsp;&nbsp;-example : S<sub>1</sub>`= {1,2,3}`, S<sub>2</sub>`= {3,4}`; S<sub>1</sub> - S<sub>2</sub> ` = {1,2}`  
  
-intersection of a non-empty set with an empty set is empty set  
-intersection of a set with itself is the original set  
-intersections are commutative, ie. order in which intersection between sets is executed does not matter  
-intersections are associatve, ie. intersections of more than 2 sets can be performed in any order  
-intersections are distributive, ie. intersection of a set with a union of two sets can be distributed in a distributed manner (example : `S1 ^ (S2 U S3) = (S1 ^ S2) U (S1 ^ S3)`)  
  
  
-how are sets implemented?  
&nbsp;&nbsp;&nbsp;&nbsp;-sets are data structures which are also implemented using singly_linked lists  
&nbsp;&nbsp;&nbsp;&nbsp;-a stark difference is that besides the ordinary singly_linked list manipulation functionalities, we also must implement functions for finding intersections, unions, differences  