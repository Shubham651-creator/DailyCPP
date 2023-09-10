# 1. Threading :

    - std::mutex mt;

    - scope based lock :
        - std::lock_guard<std::mutex> lk(mt);

-----------------------------------------------------------------------

# 2. Variant [functional_Polymorphism] :

    - Runtime polymorphism replace with functional polymorphism.
        > std::variant<obj1, obj2, ....> variant_Name;

    - std::visit(), it only exist c++17 onwards.
        > g++ -std=c++17 <fileName>.cpp

    - Forward Reference(for perfect forwarding)
        - all maker functions are e.g. of perfect forwarding

-----------------------------------------------------------------------

# 3. Optional Value[If_vector_value_container_NULL_values]

    - std::optional<Container data>;
    - std::nullopt; //return nothing in std::optional

-----------------------------------------------------------------------

# 4. Structured binding 

    - "if-init" concept
    - constexpr

-----------------------------------------------------------------------

# 5. Meta programming [genric_progamming]

    - Template
        - Special template
        - Variadic template
            > template <typename... T> 
            - fold experssion

-----------------------------------------------------------------------

# 6.Gurenteed_Copy_Elision

-----------------------------------------------------------------------

7.
8.
9.

=======================================================================

[STL_Algorithm]

- std::distance(._begin(), itr), 
    return integer

- std::copy_if(
    inputContainer.begin(), 
    inputContainer.end(), 
    outputContainer.begin(), 
    return bool lambda function
  ),
    return auto