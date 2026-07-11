## 1. Threading [Multi-threading]:

- std::mutex mt;

- scope based lock :
    - std::lock_guard< std::mutex> lk(mt);

### Senories of threads

1. No threading
    - synchro, single thread
2. Synchro threading
    - continouse running, multiple threads
3. Asynchro threading
    - one thread execute different activity at same.

-----------------------------------------------------------------------
## 2. Variant [functional_Polymorphism] :

- Runtime polymorphism replace with functional polymorphism.
    > std::variant< obj1, obj2, ....> variant_Name;

- std::visit(), it only exist c++17 onwards.
    > g++ -std=c++17 <fileName>.cpp

- Forward Reference(for perfect forwarding)
    - all maker functions are e.g. of perfect forwarding

-----------------------------------------------------------------------
## 3. Optional Value[If_vector_value_container_NULL_values]

- std::optional< Container data>;
- std::nullopt; //return nothing in std::optional

-----------------------------------------------------------------------
## 4. Structured binding 

### "if-init" concept
- (since c++17) We can declare and initialize if-else
    variable with conditions itself.

    if(int i = 12; i < 10){
        std::cout<<"i is less than 10";
    }else{
        std::cout<<"i is MORE than 10";
    }

### constexpr
- To execute function on compile-time.
- e.g.
    constexpr void funct() {}

-----------------------------------------------------------------------
## 5. Meta programming [genric_progamming]

- Template
    - Special template
    - Variadic template
        > template< typename... T> 
        - fold experssion

-----------------------------------------------------------------------
## 6.Gurenteed_Copy_Elision

- Omits copy and move(since c++17) constructors,
resulting in zero-copy pass-by-value semantics.

----
----

## STL Algorithm

- std::distance(._begin(), itr), 
    return integer

- std::copy_if(
    inputContainer.begin(), 
    inputContainer.end(), 
    outputContainer.begin(), 
    return bool lambda function
  ),