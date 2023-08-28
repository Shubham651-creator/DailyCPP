# Move Sementics

    1. std::emplace_back() 
    - it construct new object directly inside constructor.

    2. std::push_back()
    - it stores already exist object or variable.
    - std::push_back(lvalue) : copy
    - std::push_back(rvalue) : move
        > std::push_back(std::move(lvalue));

----------------------------------------------------------------------------

                Employee Object

 int*   | Department ENUM | float    | Project* 
[ 0x88H |    1      |   1230900.0f   | 0x3940J ]
    |                                      |
    |                                      |
    |                          [  201 |  DevOps | Mumbai  ]
[  101 ]
  0x88H