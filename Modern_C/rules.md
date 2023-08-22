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
    - this only mainly use when we have single argument parameterized constructor.k
        e.g. explicit carNew(int count);
    - explict means compiler can not use to typecasting

5. 'NULL' :
    -#define NULL 0 means NULL -> 0. It reached to zeroth address in memory which can not accessible and throw segmentation fault.
    - alternative of NULL is modern cpp is 'nullptr'.

6. 'noexcept' :
    - it tell compiler, never throw exception

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

# Rules

[Rule1][default constructor]
If you want to make an array of stack allocated object
so, default constructor must to ENABLE.

-----------------------------------------------------------

[Rule2][Branchless progamming]
- You should avoid or minimizing branching 
    i.e if-else, switch, expections,etc. for optimization.

--------------------------------------------------------------

[Rule3][const keyword]
- if function marked as 'const' i.e function does not modify the object
    which invoked(called) the function.
> DataType functionName() const 

--------------------------------------------------------------

[Rule4][sequence point  i.e. ';']
- In the same sequence point, value of one variable cannot be modify more than onces.

> a = ++a - ++a; //undefined behaviour
--------------------------------------------------------------------

=========================================================================

# Modern Cpp features 
1. Classes & template classes
    - with special memeber function & overloaded operator
2. Automatic v/s heap allocation
3. Smart pointer for resource managment
4. MOVE semantics
5. Reference semantics(lvalue and rvalue)
                |
                |
                |
# Difficulties face by Developer
6. dev is not happy with reference !

       > int n1=10;
       > int& n2 = n1;

        > int& arr[1] = {n2}; //NOT POSSIBLE;

    STL CONTAINER DON'T WORK WIHT RAW REFERENCE (REGULAR) !

    Solution - [reference_Wrapper]

7.  developer wants predefined functions
    Solution -[STL_alogrithms]

8. developer need more ways to arrange my data!
    e.g.hash, LIFO,FIFO, balance tree, priority
    Solution - [STL_container]

9. Developer wants to attach a pointer to everything !
    WHY NOT FUNCTIONS?
    - 
    Solution - [std::function<T>wrapper]

10. [Lambda_function] (temporary function )

11. Can compiler give develper a gurantee that it will take effort to prevent a copy in the background?
Solution - [Gurantee_copy-elision](c++17)

12. How do developer handle nothing? NULL DATA? Absence of data?
    - [std::optional-wrapper]

13. how to avoid run-time polymorphism?
    -   [using_std::variant] [std::visit]

14. what if developer work with differenct data type?
    -[std::any]
    > std::any n = 10;
    > n = "shbubh";

15. Want to full access of all CPU core?
    - Parallel excecution of object
    - [concurrence_mechanisms]