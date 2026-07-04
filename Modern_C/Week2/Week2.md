# Week 2

1.Functional programming:

    - Treats functions as a variables.

2.Lambda function (temporary function):

    > std::function<int(int)> fptr = [](int n){return n*n;};

    > fptr(input_param);

3. Reference wrapper:

    - std::ref()
    - std::cref(), [constant_reference](cref_is_immutable)
    - std::reference_wrapper<int>()

4. Partial functions:

    - std::bind()
    - using namespace std::placeholders;


5. functional wrapper :

    > std::functional<return_type(input_param)> fn;

    > fn(input_param);

    - Template functional wrapper
        >template<class_T>;

        >std::function<T> fn;

6. Move sementics

    - std::move()

