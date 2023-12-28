# Note - Characters and Strings

## Part 1 - Character Functions

- Characters in both C and C++ are single characters typically represented in integers then mapped to some format like ASCII. 
- To use character functions in C++, include the **standard library header** `<cctype>`. 
- See the doucmentation at https://en.cppreference.com/w/cpp/header/cctype. 
- There are two types of character functions, *test functions* and *conversion functions*. 
- A list of some test functions are given below. 
> - `islower(c)` 
> - `isupper(c)` 
> - `isalpha(c)` - checks whether the char is alphabetic
> - `isalnum(c)` - checks whether the char is alphanumeric
> - `isdigit(c)` ...

- However, there are only two conversion functions, `toupper(c)` and `tolower(c)`. 

## Part 2 - C-style Strings 

- There are two types of strings; **C-style strings** and **C++-style strings**, where the former is more powerful. 

- C-style strings are stored in a contiguous block of memory as an array of characters. 
- Therefore, the individual chars in a C-style string can be accessed using the typical array subscription notation. 
- The end of a string (a char array) is marked by a terminating null character (same as integer 0). Therefore, known as zero or null-terminated strings. 

### C-style String *Literals*

- Enclose a sequence of characters withing double quotes as in `"Akila"`. 
- When declared like this, the string becomes a *constant*. 

### Declaring and Initializing a C-style string

- Use the *initalizer list syntax* to initalize a char array and declare its value. 
```
    char name[] {"Akila"}; // the C++-compiler will allocate 6 characters for this string including the terminating null char.  
```
- Now, we cannot extend this string by assigning a new character at the 5th index because it will replace the null char and cause unforseeable problems. 
- But, you can allocate more memory for the string and later extend the string by assigning new chars. 
```
    char name[10] {"Akila"}; // now, the chars in indices 5 to 9 are null chars, so you can extend this up to a 9-char string, say "Akila1234". 
```

- Now, this will not work. 
```
    char name[8]; // declare a string variable but don't declare it. 
    name = "Akila"; // ERROR 
```
- Why an error? - Both the char array `name` and the string literal `"Akila"` are both evaluated to their array starting locations, and you can't assign one location to another. 
- Then how do we assign a string to the variable `name`? - Use the function `strcpy(<char_array>, <string_literal>)` in `<cstring>`. 

- The `cstring` header includes functions to handle C-style strings, including 
> - copy
> - concatenate
> - compare
> - search, and many more. 

- To convert C-style strings to integers, float, or ..., use <cstdlib> header, it contains the appropriate functions. 

## Part 3 - C++-style Strings

- Similar to C-style strings
> - stored in contiguous memory blocks
> - can be directly used with input and output streams (`cin` and `cout`)

- However, C++ style strings
> - are dynamic in size (whereas C-style strings are fixed in size [null terminating].)
> - are objects and have rich set of methods
> - can be used with operators +, =, ==, >, >=, <, <=, +=, and []

- The C-style strings can be converted into C++-style strings and vice-versa. 
- To use C++-style strings, include the header `string`. 

### Declaring and Initializing a C++-style string

- There are various ways (we are not goint to talk about everyone here). 
```
    string s1; // empty - will be automatically initialized to an empty string, so don't have to deal with garbage values like in C. 
    string s2 {"Akila"}; // Akila
    string s3 {s2}; // Akila
    string s4 {"Akila", 3}; // Aki - 3 is the length of the string 
    string s5 {"Akila", 1, 3}; // kil - 1 is the starting index, and 3 is the length of the string
    string s6 {s2, 3}; // la - 3 is the starting index, and in default length woule be taken as size() - index
    string s7 {s3, 3, 1}; // l - 3 is the starting index, and 1 is the length of the string 
    string s6 (3, 'A'); // AAA - 3 is the length of the string, and 'A' is the filling character. 
```

- Unlike in C, C++-style strings can be **assigned** values directly (remember, in C, we have to use `strcpy` to copy a string/a string literal to another string variable).
```
    string s1; // empty
    s1 = "Rajapaksha"; // the string will dynamically expand. 

    string s2 = "Akila"; 
    s1 = s2; // Akila - the string will dynamically shrink. 
```

- **To concatenate strings**, use the `+` operator. 
```
    string first_name {"Akila"};
    string last_name  {"Rajapaksha"};

    string full_name = first_name + " " + last_name; // here, `first_name` and `last_name` are C++-style strings, whereas " " is a C-style string literal. 

    cout << "Full name is " << "Akila" + " " + "Rajapaksha" << "." << endl; // THIS DOES NOT WORK!!!; all strings are of C-style. 
```

- **To access characters** of the string, use the subscription opeartion `[]` or `.at()` method. 
- The former method does not perform **bound checking** (i.e., if the index surpasses the boundary/size of the string, no error will be raised), whereas the `.at()` method does (safer). 
```
    string whole_name = "Akila Rajapaksha"; 
    
    cout << whole_name[10] << ", " << whole_name[18] << endl; // p, <garbage>
    cout << whole_name.at(10) << ", "; 
    cout << whole_name.at(18) << endl; 
    /*
    ERROR MESSAGE: 
    terminate called after throwing an instance of 'std::out_of_range'
    what():  basic_string::at: __n (which is 18) >= this->size() (which is 16)
    */
```

- **String comparison** is done *lexicographically* and peformed using operators, `==`, `!=`, `>`, `>=`, `<`, and `<=`. 
- Remember that the uppercase letters are smaller compared to their lowercase counterparts. 
- String comparisons are only possible if at least one of the operands is a C++-style strings (whether or not this raises errors may depend on the compiler). 
```
    string fruit {"Apple"}; 
    if (fruit < "Banana")
        cout << fruit + " is smaller than Banana." << endl; 
    if (fruit < "apple")
        cout << fruit + " is smaller than apple in lowercase." << endl; 
    if ("Apple" < "apple") // NO ERROR; BUT INCORRECT OPERATION!!! (here, it is correct, but these C-style-to-C-style string comparsion often leads to incorrect results.)
        cout << "Apple" << " is smaller than apple in lowercase." << endl; 
```

- Then, we can talk about the some useful string methods. 
- `.substr(start_index, length)` method to slice a string 
- `.find(char or char array, start_index)` method to find a character or a character sequence in a string
- `.length()` method to directly find the length of a string 