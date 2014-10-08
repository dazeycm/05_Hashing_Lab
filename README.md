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

1. All of the functions seem to be done in constant time when compared to those in the book.
2. Add uses linear probing and is only O(n) when `grow` is called
3. `Grow` is done in linear time
4. There shouldn't be any memory leaks as the destructor is called. The only possible memory leak may be the new array in the `grow` method, but i'm not sure how that works with the assignment of the new array to backing array.

#### 2. I decided to use two function (`keyExists` and `find`) to enable lookup of keys. Another option would have been to have `find` return a `T*`, which would be `NULL` if an item with matching key is not found. Which design do you think would be better? Explain your reasoning. You may notice that the designers of C++ made the same decision I did when they designed http://www.cplusplus.com/reference/unordered_map/unordered_map/

I believe that the keyExist functions is easy to understand, and could be easily modified if you wanted to find deleted keys for example. Having a function makes things more flexible also, and the `keyExists` can be used as any other method very easily to determine if a key exists in an array without having to do anything with pointer data. 

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The only thing that confused me really was the calcIndex, and what it was supposed to do. I would recommend students that they look into how the calc index function works because after getting that started everything else is pretty easy. Also, my program still gets an error on the last check that I'm completely unable to resolve, even after debugging. 
