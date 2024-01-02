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