# CH4 - Analysis of Algorithms

-algorithm performance is usually expressed as a function of the size of the data it processes  
-for some data of size *n* we describe its performance with some function `f(n)`  
-we are primarily interested in the growth rate of `f(n)`, ie. how quickly the algo's performance will degrade as the size of data increases  
  
-a few simplifications exist for O-notation :  
    &nbsp;&nbsp;-constant terms can be ignored (in expression `T(n) = n + 50`, constant term `50` becomes irrelevant if `n` is large enough)  
    &nbsp;&nbsp;-we can ignore constant multipliers of terms because they too will become insignificant as the value of `n` increases (<code>T<sub>1</sub>(n) = n<sup>2</sup></code>  <code>T<sub>2</sub> = 10n</code>; If `n` is larger than 10, <code>T<sub>1</sub></code> will always be greater than <code>T<sub>1</sub></code>, thus making the constant 10 multiplier irrelevant)  
    &nbsp;&nbsp;-we need to consider only the highest order term, because as `n` increases, higher-order terms quickly outweigh the lower-order ones  
    &nbsp;&nbsp;-these ideas are formalized in the below notations  


-`O(1)` - constant terms  
-if a task/algo executes in a certain amount of time regardless of the data size  
-formally stated for some constant `c` : `O(c) = O(1)`  
  
-`O(cT) = cO(T) = O(T)` - multiplicative constants are omitted  
-this rule is applied when a number of tasks all execute in the same amount of time  
-if three tasks each run in time `T(n) = n`, the result is `O(3n)`, which simplifies to `O(n)`  
-first line of this section states the formal notation for some constant `c`  
  
-addition is performed by taking the maximum  
-this rule is applied when tasks are executed one after another  
-example : `T1(n) = n and T2(n) = n^2` describe two tasks executed sequentially  
    &nbsp;&nbsp;-the result is `O(n) + O(n^2)`, which simplifies to `O(n^2)`  
-formally stated : `O(T1) + O(T1+T2) = max(O(T1), O(T2))`  
  
-multiplication is not changed, but often rewritten more compactly  
-this rule is applied when one task causes another to be executed some number of times for each iteration of itself  
-for example, in a nested loop whose outer iterations are described as `T1`, and whose inner iterations are described by `T2`, if `T1(n) = n and T2(n) = n`, the result is `O(n)O(n), or O(n^2)`  
-formally stated : `O(T1)O(T2) = O(T1T2)`  
  
-complexities have no real measurement unit - the only describe how the resource that is being measured will be affected by a change in data size  
-example : saying `T(n)` is `O(n)` conveys that the algorithm's running time varies proportionally to `n`  
  
-many complexities occur frequently in computing  
-`O(1)` - fetching the first element from a set of data  
-`O(lg n)` - splitting a set of data in half, then splitting the halves in half, etc.  
-`O(n)` - traversing a set of data  
-`O(n lg n)` - splitting a set of data in half repeatedly, and traversing each half  
-`O(n^2)` - traversing a set of data once for each member of another set of equal size  
-`O(2n)` - generating all possible subsets of a set of data  
-`O(n!)` - generating all possible permutations of a set of data  

-for a graphical depiction of the above described complexities, google it, or check out page 73 in the book  
  
-whether a particular complexity is considered efficient or inefficient depends on the problem  
-generally speaking, an **efficient** algorithm is the one in which we know we are doing the best we can do given certain criteria  
-an algorithm is said to be **efficient** if there are no algorithms with lower complexities to solve the same problem  
-if two algorithms are of the same complexity, it may be wortwhile to consider their less significant terms and factors - if the data on which algorithms' performances depend is small enough, even an algorithm of greater complexity with **small** constants may perform better in practice than one that has lower order of complexity, but larger constants  
-additionally, how difficult the algorithm will be to develop and maintain should be taken into account
  

-note that at the end of this chapter, also as in other chapters, interesting questions and answers are given