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

