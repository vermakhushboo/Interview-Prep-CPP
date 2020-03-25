### Good to Remember Points

- One key can have only one value.
- *map.count()* returns only an integer which tells whether the key exists in the map or not. 
- *map.find()* returns an iterator using which the value corresponding to the particular key can also be accessed.
- It's better to use map.count() if you just need to check whether key exists or not to save the space of an iterator.

#### unordered_map
- There is no ordering among keys.
- It is implemented using a **Hash Table**.
- Search, Insertion and Deletion time:
  - Average Case: **O(1)**
  - Worst Case: **O(n)**
 - Use when you don't need to traverse or need ordered keys.
 
 #### map
 - Keys are ordered in increasing order by default.
 - It is implemented using _Self Balancing Binary Search Tree_ like Red-Black tree.
 - Search time: **log(n)**
 - Insertion and Deletion time: **log(n) + rebalance**
 - Useful when:
    - Ordered data is needed
    - Need to print or traverse in sorted order
    - Need of predecessor or successor of elements
 
 #### Basic Functions
 - _begin()_, _end()_, _empty()_, _size()_, _find()_, _count()_, _insert()_
 - _clear()_: removes all elements from the map 
 - _erase(const a)_: removes key value 'a' from the map 
 - _erase(iterator position)_: removes element at the position pointed by the iterator
 - *upper_bound()*, *lower_bound()*
