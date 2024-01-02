// ----------------------------------------- Functions -----------------------------------------

#include <iostream>
#include <string>

using namespace std;

// definition of say_hello function
void say_hello(string name, string suffix = "", string prefix = "") {
    cout << "Hello " << suffix << name << " " << prefix << endl; 
}

// definition of main function
int main() {
    string my_name {"Akila Rajapaksha"};
    say_hello(my_name); 
    say_hello("Rajapaksha", "Mr."); 
    say_hello("Rajapaksha", "Mr.", "R.M.P.A.P.");
    say_hello("Rajapaksha", "", "R.M.P.A.P."); // want to see "Hello Rajapaksha R.M.P.A.P."
}

