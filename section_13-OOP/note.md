# Note - Object Oriented Programming (OOP)

## Part 1 - Introduction

### What is Object Oriented Programming? 
- OOP simply refers to **modeling software/programs using classes and objects**. 

### What is a Class?
- Blueprint from which the objects are created
- A user-defined datatype 
- Have attributes (data) and methods (functions) (Encapsiulation)
- Can hide attributes and methods that are internally used
- Provides a well-defined and easy-to-use public interface

### What is an Object?
- Created from a class and represents a specific instance of that class
- Can create any number of objects from the class
= Each object is unique (has its own identity)

## Part 2 - Declaring Classes and Objects
- The notation for declaring a class is given below. 
```
    class ClassName {
        // declarations ;
    }; // <- remember, there is a semicolon at the end of the class declaration
``` 
- Consider the following example
```
    class Player {
        // attributes
        string name;
        int score;
        vector<double> xp;

        // methods 
        void win();
        void upgrade(int score);
    }
```

- Then, creating instances of classes (objects) has the same notation as declaring variables of the primitive data types. 
```
    Player James;
    Player Anne;

    Player *Tom = new Player; 
    // do something
    delete Tom;
```

## Part 3 - Accessing Class Members
- There are two main operators, *dot operator* and *arrow operator*, that we can use to access members (attributes and methods) of an object of a class. 

- Dot Operator is relatively straight-forward to use; see the following code...
```
    Player James;

    James.name;        // attributes
    James.upgrade(90); // methods
```

- When we have *a pointer to an object* instead, then the pointer must be dereferenced first before accessing the members using the dot operator. 
```
    Player *Peter {nullptr};
    Peter = new Player; // remember, `Peter` is a pointer to a `Player` object 

    (*Peter).name;         // attributes
    (*Peter).upgrade(100); // methods
```
- Note that since member operation (.) has precedence over the dereferencing operator, the paranthesis must be used as shown above. 
- In these scenarios, we can directly use the arrow operator to access members of an object refered by a pointer. 
```
    Peter->name; 
    Peter->upgrade(100);
``` 

- Also remember, **all the members of a class is by default private** and cannot be accessed directly outside the class definition. 
- To make the members publicaly accessible, use the *access modifier* `public` in C++. All the attributes and methods declared after the `public` keyword will be considered public. 
```
    class Player {
        public:
            // attibutes (all public)
            string name;
            int score {0}; // can initialize here as well
            vector<double> xp {}; 

            // methods (all public)
            void talk (string phrase) { // can define the function here
                cout << name << " says " << phrase << "." << endl;
            }
            void upgrade(double); 
    }
```
- Note here, we don't have to spcifically provide `name` as an argument to the function `talk` since the variable `name` is available in the immediately above scope. 

## Part 4 - Class Members Access Modifiers

- There are 3 main basic access modifiers: 
> - `public` - accessible everywhere
> - `private` - accesssible only be members and *friends* of the class 
> - `protected` - used with *inheritence* 
- Using these are relatively straight forward. 

## Part 5 - Implementing Member Methods 
- Class member methods can be implemented in two main ways; 
> - inside the class declaration (then, explicitly inline)
> - outside the class declaration (use the syntax `ClassName :: MemberFunction`)

- Typically, the class specification/declaration is kept seperate from the implementation.
> - class declaration in a header file (.h file)
> - class implementation in a .cpp file

### Example - Method Implementation inside the Class Declaration
```
    class Account {
        private:
            // attributes (all private)
            string name {"John"};
            double balance {};
        public:
            // methods (all public)
            void set_balance(double bal) {
                balance = bal;
            }
            double get_balance() {
                return balance;
            }
    };
```
- Unless all your class member methods definitions are short and simple, this implementation of class methods can be harder to maintain. 

### Example - Method Implmentation outside the Class Declaration
```
    class Account {
        private:
            // attributes (all private)
            string name {"John"};
            double balance {};
        public:
            // methods [PUT THE FUNCTION PROTOTYPES HERE] (all public)
            void set_balance(double bal);
            double get_balance();
    };

    void Account::set_balance(double bal) {
        balance = bal;
    }

    double Account::get_balance() {
        return balance;
    }
```

- When delcaring the class specification in a .h header file, we have to add **an include guard**. 
- If multiple .cpp files try to include the same header file, the compiler will raise an error since it has to build the header file multiple times. 
- To avoid this error, declare the class within an include guard, which builds the class only if it has not been built earlier. 
```
#ifndef __ACCOUNT_H__ // this can be any name
#define __ACCOUNT_H__

// put the above class declaration here... 

#endif // use the previously built __ACCOUNT_H__
```
- Typically, the C++ IDEs help you to create a class by automatically generating a header file with the include_guard and a .cpp file with the class name. 

## Part 6 - Class Constructors and Destructors 
- Both the class constructor and destructor are special member methods of a class. 
- Both have the same name as the class and have no return type; the difference is that you have to put a tilde symbol (`~`) before the destructor's name. 
- It is common to use function overloading with constructors; also, one overloaded function with no arguments (no-arg constructor). 
- Destructor takes no arguments; and no function overloading. 
- Destructors are called automatically by C++ when the control moves on from a scope or the execution of a function which declares the class object finishes. 
- When no constructor or destructor is provided in the class declaration, the C++ will use the *default* constructor and destructor, which are empty. 
- Remember, both the constructor and destructor must be available in the public user interface; therefore, must be declared as public members. 


- Take a look at the following sample class declaration. 
```
    class Player {
        private: 
            string name;
            int score; 
            vector<double> xp {}; 
        public:
            // constructors
            Player(); // no-arg
            Player(string name);
            Player(string name, int score);
            // destructor
            ~Player(); 

            set_name(string s); // a public method to access and set the `name` attribute
    };
```
