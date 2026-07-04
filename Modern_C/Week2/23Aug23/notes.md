# Three paradigms of programmings

    - Structured programming ! (C programing)
    - Object oriented programming!
    - Functional Programming !!!(week 2)
        - Build your solution by the following principle :
            -"Always think about data, operations to be performed,
                and how to apply operation on data. "

======================================================================

# Working of lambda function:

> struct Lambda{
>    opertaor() (int number){
>       return number*number;
>   }
> }

> struct Lambda f1;
> f1(20);

=======================================================================

# auto V/s template

[auto] : determine the type of a variable based on initial value and you can't further modify.
> auto n1 = 10 ; //n1 is determined to be of type integer
> n1= "shubam" ; //error: type was already fixed as int

> auto f1 = [] (int n){return n*n;};

- f1 is lambda function (with f1 as an object of an internal class lambda) that takes one integer and returns void.

------------------------------------------------------------------------

[template] : allows you to determine a standred format of code structure that can be used by the compiler to create more code at compiler time
(overriding).

====================================================================

# Reference :

- lvalue reference (int& n1)
- rvalue reference (int&& n2)

    > int n1 =10
    > int& n2 = n1;
    > int& n3 = n2;

    >int* ptr = 10;
    > int& refPtr = ptr;

    [SYMBOL_TABLE]

    NAME    ADDRESS     content     ALTERNATE NAMES
    n1      0x100H      10              n2,n3
    refPtr  0x300U      0x49U           ptr