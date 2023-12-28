// ----------------------------- C-style Strings -----------------------------

#include <iostream>
#include <cctype> // for character testing and conversions
#include <cstring> // to work with C-style strings
#include <cstdlib> // to convert strings to int/float/...

using namespace std;

int main() {

    // // declare some string variables and initialize them
    // char first_name [12] {"HelloWorld!"}; 

    // cout << "first name: " << first_name << endl; 

    // // let's forcibly overwrite the terminating null character of the string
    // first_name[11] = '#';

    // cout << "first name string after overwriting terminating null char: " << first_name << endl; 
    // // first name string after overwriting terminating null char: HelloWorld!#
    // // although this works correctly, may cause errors... 

    char first_name [20];
    char last_name  [20];
    char full_name  [40];

    // take user input for first name and last name
    cout << "Enter first name: ";
    cin >> first_name; 
    cout << "Enter last name : ";
    cin >> last_name;
    cout << "------------------" << endl;

    // show the first and last names and their lengths
    // note that `strlen` function returns the length of the input string as `size_t` value.  
    cout << "Your first name is " << first_name << ". (no. of chars - " << strlen(first_name) << ")" << endl;
    cout << "Your last name is " << last_name << ". (no. of chars - " << strlen(last_name) << ")" << endl;

    // Find the full name of the user
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    cout << "Your full name is " << full_name << ". (no. of chars - " << strlen(full_name) << ")" << endl << endl;


    // // Ask the user to enter the full name
    // cout << "Enter full name : ";
    // cin >> full_name;

    // cout << "Your full name is " << full_name << ". (no. of chars - " << strlen(full_name) << ")" << endl << endl;
    // // Your full name is akila. (no. of chars - 5)
    // // When there is a white space character, the input stream stops reading. 

    // cout << "Enter full name : ";
    // cin.getline(full_name, 10); // THIS DOES NOT WORK!!!

    // cout << "Your full name is " << full_name << ". (no. of chars - " << strlen(full_name) << ")" << endl << endl;

    // convert the user input full name into the correct format
    for (size_t i=0; i<strlen(full_name); i++) {
        // convert first letter of the full name (same as the first letter of the first name) to upper case
        if (i == 0)
            full_name[i] = toupper(full_name[i]);

        // when hit a white space, convert the next letter (same as the first letter of the last name) to upper case
        else if (full_name[i] == ' ') {
            full_name[i+1] = toupper(full_name[i+1]);
            i++;
        }

        // then, convert all the other letters to lower case
        else 
            full_name[i] = tolower(full_name[i]);
    }

    cout << "Converted full name is " << full_name << ". (no. of chars - " << strlen(full_name) << ")" << endl << endl;

    
    char temp[] = "Akila Rajapaksha";

    if (strcmp(full_name, temp) == 0)
        cout << "User name matches the full name in the code base..." << endl;
    else 
        cout << "User name doesn't match the full name in the code base..." << endl << endl;


    return 0;
}