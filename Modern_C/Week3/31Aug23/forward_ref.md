##  Forward reference [for profect forwarding] 

Data* ptr = new Data(100,200);

auto s1 = std::make_shared<Employee>(
    101,                               // rvalue :101 is int temp
    "Shubham",                         // rvalue :const char array of 8
    std::vector<int>{10,20,30,40},     // rvalue :std::vector of tempoary
    ptr                                 //lvalue pointer to Data
);
 
--------------------------------------------------------------------
    class Employee:
    {
        int&& id;       //rvalue reference
        string&& name;  //rvalue reference

        public:
            Employee(int&& i, string&& n)
            : id(i), name(n) {}
    };

    template< typename A, typename B, typename class_name>
    make_shared(A arg1, B arg2, class_name b1)
    {
        class_name b1(arg1, arg2);     //lvalue, lvalue
    }

    auto e1= make_shared<int, std::string, Employee> (101,"shubam"); //rvalue, rvalue

------------------------------------------------

- Here, make_shared reject the e1 because it accpets only lvalue but we send rvalue. 

## Solution:( Perfect Forwarding)
Perfect forwarding allows a "Template_function" that accepts a set of arguments to forward these arguments to another function whilst retaining the lvalue or rvalue nature of the original function arguments using "Reference_forward" concepts.>

i.e.

    template<typename A, typename B, typename class_name>
    make_shared(A&& arg1, B&& arg2, class_name b1)
    {
        class_name b1( std::forword(arg1), std::forword(arg2) );     
    }

----------------------------------------------------------------------
 

 