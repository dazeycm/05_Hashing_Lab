05_Hashing_Lab
==============

Implement a hash table in C++

Requirements
------------

1. `keyExists`, `find`, `remove`, and `size` should all be O(1)
2. `add` should be reasonably fast. Use linear probing to find an open slot in the hash table. This will be O(1), on average, except when `grow` is called.
3. `grow` should be O(n)
4. Do not leak memory


Reading
=======
"Open Data Structures," Chapter 5, except for 5.2.3. http://opendatastructures.org/ods-cpp/5_Hash_Tables.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. All of the functions seem to be done in constant time when compared to those in the book, however because `calcIndex` is wrong, this may not actually be true.
2. Add uses linear probing and is only O(n) when `grow` is called
3. `Grow` is done in linear time
4. There shouldn't be any memory leaks as the destructor is called. The only possible memory leak may be the new array in the `grow` method, but i'm not sure how that works with the assignment of the new array to backing array.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I believe that the keyExist functions is easy to understand, and could be easily modified if you wanted to find deleted keys for example. Having a function makes things more flexible also, and the `keyExists` can be used as any other method very easily to determine if a key exists in an array without having to do anything with pointer data. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The only thing that confused me really was the calcIndex, and what it was supposed to do. I would recommend students that they look into how the calc index function works because after getting that started everything else is pretty easy. Also, my program still gets an error on the last check that I'm completely unable to resolve, even after debugging. I'm also not sure that I'm doing the linear probing correclty, but it seems to be working. Also, see TODO section below. This includes everything that I know is broken or wrong.


**TODO** (AKA: These things are still broken)
=============================================
1. `Grow` gives an error
2. `calcIndex` returns the first value in the array, and each method then looks for the index itself. This is of course wrong, but when I try to fix it, everything breaks and I become lost. This means that each function is taking more time than it needs in order to complete.
3. Grow function doesn't call add.. confused as to how it can when the add only works on the backingArray, but the backingArray is the old backingArray, and if I make the backingArray the new one, the values will be lost. 
