# Template

[Scenario_1]: 
A common "logic" / "Operation"/ "Process" is to be applied on infinite data types (ONLY 1 at a time).

> template<typename T>
> ...

---------------------------------------------------------------------

[Scenario_2]: 
A common "logic" / "Operation"/ "Process" is to be applied on infinite data types 
(2 or more at a time, each type may be different).

> template<typename A, typename B>
> template<typename A, typename B, typename C, typename D>

----------------------------------------------------------------------

[Scenario_3]: 
A common "logic" / "Operation"/ "Process" is to be applied on infinite data types but there are some special corner cases a well
(use template specialization)

> template<typename T>
> ...
> template<>
> ...

----------------------------------------------------------------------

[Scenario_4]: (Veriadic_Template)(args...)

- Fold Recursive(c++17)
    - To avoid writing recursion

======================================================================

## Type of coding language

The [C++] is compile-time, strongly type , statically typed, OOP's, functional , structured progamming language.

-[Strongly_types](python,java,cpp) Vs. [Weakly types](js)

-[Dynamically Typed](python) Vs. [Statically_Typed](c++,java,C)



