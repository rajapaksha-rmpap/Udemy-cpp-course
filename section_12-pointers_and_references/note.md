# Note - Pointers and References

## Part 1 - Declaring a Pointer in C++ 

- Format 
```
    int *int_pointer; // OR
    int* int_pointer_1;
```

- It is important to initialize all the pointers when declared; if not initialized, the pointer will contain a garbage value (garbage address) which can refer to **anywhere** in the memory, and this can be harmful. 
- The typical practice is to initialize the pointer as a *null pointer*, which points to memory address 0, i.e., **a null pointer points to nowhere**. 
```
    int *int_pointer {}; // OR
    int *int_pointer_1 {nullprt}; 
```

## Part 2 - Accessing Pointer Addresses
- Use the Address Operator (`&`). (a unary operator)
```
    int num {10};

    // access the value of the variable
    cout << "value of num is " << num << endl; // 10
    // know the size of the memory space acquired by the variable
    cout << "size of num is " << sizeof num << endl; // 4
    // find the memory location the variable is stored at
    cout << "address of num is " << &num << endl; // a hexadecimal pointer
```

- Then, we shall see how to use C++ pointers. 
```
    int *p; 

    // access the value of the pointer `p`
    cout << "value of p is " << p << endl; // garbage hexadecimal address
    // know the size of the pointer
    cout << "size of p is " << sizeof p << endl; // 4 (???)
    // find the address of the pointer
    cout << "address of p is " << &p << endl; // hexadecimal address

    // we can assign new addresses to the pointer `p`
    p = nullptr; // 0 
    // access the new value of the pointer
    cout << "new value of p is " << p << endl; // 0
```

- Don't confuse the size of a pointer and the size of the data the pointer points to. 
- **All the pointers in a program have the same size.** 

### Typed Pointers
- The pointers we discussed above are called *typed pointers*. 
- The compiler will make sure that the data which the address stored in a pointer variable points to is of the correct type. 
```
    int num_students {50};
    double mean_score {70.24};

    int *integer_ptr {nullptr};

    // assign the address of the integer variable `num_students` to integer pointer `integer_ptr`
    integer_ptr = &num_students; // OK

    // what happens here
    integer_ptr = &mean_score; // compile error
```
- There is another variation of pointers called *untyped void pointers*, but they are typically used in C language and not in C++ and hence not discussed here. 

## Part 3 - Dereferencing Pointers
- **The notation for dereferencing a pointer is same as the notation for declaring a pointer variable.** 
```
    int score {50};
    int *score_ptr {&score};

    cout << *score_ptr << endl; // 50

    score = 80;
    cout << *score_ptr << endl; // 80

    *score_ptr = 90;
    cout << *score_ptr << endl; // 90
    cout << score << endl; // 90
```

## Part 4 - Dynamic Memory Allocation using Pointers
- We can dynamically allocate memory inside the *heap memory* (free-store memory) using pointers in the runtime. 
- To allocate memory, use the `new` keyword in C++. 
```
    int *int_ptr {nullptr};

    cout << int_ptr << endl; // 0

    // allocate some memory for an integer inside the heap memory
    int_ptr = new int; 

    cout << "address of the newly allocated memory for an integer is " << int_ptr << endl; // a hexadecimal address
    cout << "integer data contained inside the newly allocated memory is " << *int_ptr << endl; // a garbage integer

    *int_ptr = 100;
    cout << "new integer data contained inside the allocated memory is " << *int_ptr << endl; // 100
```
- The only way to access and change this newly allocated memory is through the pointer variable; it doesn't have a variable name. 
- Once you finish using the allocated memory, maks sure to **always deallocate that memory** so that the program can use that memory space again. 
- Use the `delete` keyword followed by the pointer variable name to free the memory. 
```
    // consider the above code
    delete int_ptr;
```

### How to allocate memory for an array? 
- Use the `new` keyword followed by the datatype of tha array and the size of the array within square brackets. 
- Then, to deallocate that memory, use `delete` keyword, followed by **an empty enclosed square brackets**, and then the pointer variable name. 
```
    int *int_arr_ptr {nullptr};
    size_t size {};

    cout << "enter the size of the array: ";
    cin >> size; 

    int_arr_ptr = new int[size]; // allocate memory
    // ...
    delete [] int_arr_ptr; // free memory
```
- If you declare an array within the `main` function, then the memory for that array will be allocated inside the *function call stack memory*; but, in this way, it is created within the heap which possesses much more free memory. 
- Never loose these pointers because, once lost, they will create *memroy leaks*.  
