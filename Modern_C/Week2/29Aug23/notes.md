# What is Iterator?
    
       0x100H 0x104H 0x108H 0x112H [consecutive memeory locations]
array :   1    2        3    4

        0x100H      0x134H     0x248H       0x782H   |          [ randomized memory locations]
List : 1 |0x134H   2 |0x248H  3 | 0x782H   4 | NULL  | END

[Iterator](Abstraction_Over_pointer)

- Iterator can give ability to work with container with same kind of syntax.
- container (could be anything)
- container.begin(first element)
- go to next elements:
        array : +4
        list : access next address
-----------------------------------------------------------------------

# Types_Of_Iterator

    1. input iterator
    2. output iterator
    3. forward itr
    4. bi-directional itr
    5. Random-access itr

--------------------------------------------------------------------------

# Type of containers:

    1. Sequential container (linear container)
        - list
        - vector
        - array, etc

    2. Associative container(key-value pair)
        [Hashing]
        - unordered_map
        - set
        - map
        - multiset, etc

    3. Container Adaptors (We can changes its implementation)
        - stack
        - queue
        - priority queue

----------------------------------------------------------------------

[Data_structure]
    - Behaviour
    - Implementation

------------------------------------------------------------------------
[std::accumalator](Reduce)

Init for addition:(By default by accumalator)

    0 10 20 30 40 50
  + | |  |  |  |   |
     10  |  |  |   |
  + |   |  |  |   |
       30   |  |   |
       +|   |  |   |
          60   |   |
         + |   |   |
            100    |
            +|     |
                150     (ans)