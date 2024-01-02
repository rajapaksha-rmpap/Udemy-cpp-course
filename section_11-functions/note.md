# Note - Functions 

## Part 1 - C++ Standard Libraries

- A list of all the C++ standard libraries can be found at the cpp reference page https://en.cppreference.com/w/cpp/header. 
- To use common methematical operations, like power, log, exponential, include the `<cmath>` header. 

## Part 2 - Function Definitions

- A function definition in C++ has four main parts: 
> - name - function name 
> - *parameter* list - what does the funtion take in?
> - return type - what does the function return?
> - function body - what does the function do?

```
    int add (int a, int b) {
        return a+b;
    }
```

- **The function definition must come before the function call.**
```
    // definition of main function
    int main() {
        say_hello(); 
    }

    // definition of say_hello function
    void say_hello() {
        cout << "Hello" << endl; 
    }
```
- The above code will raise the error, "error: ‘say_hello’ was not declared in this scope". 
- Having to define all the functions before calling them can be problematic in complex programs as well in the cases where two functions call each other. 
- In such cases, we can use **function prototypes**. 

## Part 3 - Function Prototypes 

- Known as *forward declarations*
- In small programs, placed at the top of the script (typically, after the include statements) 
- Typically, we put them in seperate *header files* (.h). 

- A function prototype is same as the header of the function definition which does not include the function body. 
- You may or may not specify the input parameter variable names; good to specify them for documentation purposes. 

```
    // function prototype for the above `add` function
    int add (int a, int b); // OR
    int add (int, int); 
```

## Part 4 - Function Parameters and `return` Statement

- In a function call, the inputs are called *arguments*. 
- In a function definition, the inputs are called *parameters*. 

### Pass-by-Value 

- When you pass data to a function in a function call, it is passed by value, which means a copy of the data is sent into the function. 
- Therefore, the manipulations you perform to the *parameters* within the function do not affect the *arguments* passed in. 
- Terminology to consider... 
> - Formal Parameters - the parameters defined in the function header 
> - Actual Parameters - the parameters passed in the function call, the *arguments* 

- Consider the following code. 
```
    void param_test(int formal) { // the parameter `formal` is initialized to a copy of the actual parameter value. 
        cout << formal << endl; // 50
        formal = 100; 
        cout << formal << endl; // 100 
    }

    int main() {
        int actual {50}; 
        cout << actual << endl; // 50
        param_test(actual); 
        cout << actual << endl; // 50, the actual parameter was never changed... 

        return 0; 
    }
```

## Part 5 - Default Argument Values 

- Specifying default arguments in C++ functions follow the same notation as Python. 
- Remember, all the default arguments must be placed at the tail of the input parameter list. 
- **You can specify the default argument values either in the function prototype or in the function definition header, but NOT in both.**

```
    // function prototype 
    double cal_tax(double price, double tax_rate = 0.05); 

    // function definition 
    double cal_tax(double price, double tax_rate) {
        return price += (price * tax_rate)
    }
```

- You can't do the following in C++... 
```
    cal_tax(100, tax_rate = 0.10); // YOU CAN'T DO THIS... 
```
- **How to use default arguments in function prototypes?** With function prototypes, you can specify default parameters as follows. 
```
    double cal_tax (double, double = 0.05); // equivalent to the previous function prototype 
```

## Part 6 - Function Overloading 

- Function overloading means using the same function name for different functions. 
- This is a good technique to add abstraction to a program because with function overloading, we do not need to rememeber different function names to perform similar tasks on different data types or data combinations. (Ex: we can use function overloading to define a series of functions with the same name `print` to visualize different data types.) 
- Consider the following function prototypes. 
```
    int add_numbers(int a , int b); 
    double add_numbers(double a, double b);
```
- Both functions have the same name but accept different types of input arguments and return different types of results. 
- Therefore, when function overloading is used, the compiler will call the appropriate version depending on the number of provided input arguments to the function, their type, and order. 
- Remember, all the declared overloaded functions must be defined seperately. 
```
    int add_numbers(int a, int b) {
        return a + b; 
    }

    double int_numbers(double a, double b) {
        return a + b;
    }
```
- Notice that the above two funtion definitions are almost identical except to the input arguments' and return data types. 
- To define these kind of identical function behaviors, one can use **function templates**, which we will discuss later. 

- Also, note the compiler cannot differentiate overloaded functions purely on return data type, see the following. 
```
    int function();
    double function();

    cout << function << endl; // the compiler will not know which version to call...
```

- Note that when a character is passed as an argument and a suitable overloaded function doesn't exist that contains parameters of `char` data type, then the overloaded function with an integer parameter will be used by the compiler (if such an overloaded function exists). Therefore, the character will be converted into an integer. 
- A C-style string (char array) will be converted to a C++-style string object by an overloaded function that accepts C++ strings. 

- **How to use default arguments with function overloading?** - **BE CAREFUL!!!** 
- Take a look at the following code... 
```
    // function prototypes 
    void print(int = 0);
    void print(string = "Hi"); 

    // a function call 
    print(10); 
    print("Hello"); 
    print(); // ERROR 
```
