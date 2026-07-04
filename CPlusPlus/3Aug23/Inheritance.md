# Properties of Inheritance:

- If any function is not present in derived class, 
then it call by Base class(if present in base class).

- Virtual = request to runtime polymorphism implementation 
- Virtual is non-static variable and vfPtr is added per object i.e.
if Employee e[10], then it creates 10 vfPtr.
- But vfTable is Static Array i.e creates only once.
- constructor never be Virtual, because vfTable is initize in constructor.

- base class pointer is Generic pointer which accept all derived class address.
_____________________________________________________________________________________________


# TYPE-CASTING:
1. special case in cpp for inheritance - 
Dynamic cast operator:(down cast)

- If casting is failed,then it return 0 or nullptr

Employee* eptr = new SalesPerson; //base class
Salesperson * sp;

//coping employee pointer into SalesPerson pointer
> sp = dynamic_cast < SalesPerson * > (ep);
------------------------------------------------------------------------------------------
2. Static cast operator : 
- It avoid runtime polymorphism implementation
- and bad for when we used with reference

int a=10, b=3;
float result = static_cast<float> (a/b);

//result = 3.333