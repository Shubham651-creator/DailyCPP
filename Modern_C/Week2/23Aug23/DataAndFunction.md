# WHAT DO YOU DO WIHT DATA/VARIABLE?

1. variable have a type -------> type is declared !
    > int n1 = 10;
    > std::function<int(int)> fn = square;

2. variable are passed as arguement to functions !
    > magic(int val)
    > magic( std::function<int(int)> fn )

3. variable are returned a return value from functions !
    > std::function<int(int)> magic(int number);
        
4. content of variables can be copied into other variables !
    > std::function<int(int)> f1;
    > std::function<int(int)> f2 = f1;

5. variable can be also stored in other data containers !
    - std list of std of function wrapper to function that take int and return int
    > std::list<std::function<int(int)> > data {f1,f2,f3};

