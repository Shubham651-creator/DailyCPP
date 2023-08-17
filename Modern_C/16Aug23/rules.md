# Special member functions are :
        a. default constructor
        b. copy constructor
        c. copy assignment operator
        d. move constructor
        e. move assignment operator
        f. destructor

1. Don't create special member functions in the class until you must needed.
2. Try to use const keyword to most time.
3. Adding new keyword is expensive in program.
4. Another use of Delete keyword is, when disable the special function
    CarNew::CarNew() = delete;

- Garbage data (undefined behaviour - UB ) which is not useful.

---------------------------------------------------------------------------

# When copy constructor class by implicity?
    1. all data member of class is copible
    2. all data member of parent class is must be copible.
    3. There must not be implicity and explicit move constructor and move assignment also.

-----------------------------------------------------------------------------

# KEYWORDS:

1. 'default' keyword is called also side effect and using to much Default is 
    bad habit and impossible to redefine that function.

2. 'auto' :
    - It works only when you initialized and mostly used in 
        universal refenence (forwarded refenence) and lambda function.

3. 'using' keyword(typedef) is used to alternative name.
    using newName = oldName

4. 'explicit' :
    - There is keyword in modern cpp that block compiler using 
        constructor for implicit type converstion.
    - this only mainly use when we have single argument parameterized constructor
        e.g. explicit carNew(int count);
    - explict means compiler can not use to typecasting

5. 'NULL' :
    -#define NULL 0 means NULL -> 0. It reached to zeroth address in memory which
        can not accessible and throw segmentation fault.

---------------------------------------------------------------------

# In modern Cpp programing styles are :

1. Structured oriented (imperative) way
    - small project and short
2. Object oriented way
    - object communication
3. Functional style way coding
    - If we are working with purely data
    - maths function
4. iterative apporch to processing the data
    - processing data from start to end without skipping nothing.
    - it use to processing data completely.

------------------------------------------------------------

[Rule1]
If you want to make an array of stack allocated object
so, default constructor must to ENABLE.