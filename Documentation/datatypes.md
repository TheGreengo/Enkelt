I want there to be easy access to a variety of different data types as a basic feature of the language so you can implement a lot of functionality right out of the box.
# Arrays
Arrays are arrays, a simple combination of a pointer and a number of memory spaces that are reserved for that array. Quite simple.

The syntax to allocate an array is 
`type[size] name`
`type[size] name = [1,2,3]`
## GrowArray
There will also be a class of arrays called `GrowArray`s which will allow for just appending items on the end and it will automatically reallocate the array as needed. If you really need this functionality though, you should just use a linked list or set.

The syntax to allocate a `GrowArray` is 
```
GrowArray(type) name
name = [1,2,3]
```
## MathArray
There will also be a class of arrays called `MathArray`s which will have basic vector math things built in such as operations on vectors and matricies and limitations requiring squareness. Essentially numpy.

The syntax to allocate a `MathArray` is 
```
MathArray(type, array_of_sizes) name
name = [1,2,3]
```
# Maps
Maps are maps, and will have an overrideable hashing function pre-defined for the basic types.

The syntax to allocate a map is 
`{type, type} name`
# Sets
Sets are the same old basic sets, they are unordered and have a set of elements inside of it that allows for no duplicates.

The syntax to allocate a set is 
`(set) name`
# Trees

The syntax to allocate a tree is 
`/type\ name`
# Linked Lists

The syntax to allocate a linked list is 
`~type~ name`
# Dequeue
Shoot, I should probably specify dequeues as well.

The syntax to allocate a dequeue is 
`|type| name`