#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    // ask the user for input string
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    // create each level of pyramid
    for (int i=0; i<str.length(); i++) {

        // create the sub string required for a given level of the pyramid
        string sub_str {str.substr(0, i+1)};

        // create a copy of the sub string to reverse
        string sub_str_cpy {sub_str};

        // reverse the sub string
        reverse(sub_str_cpy.begin(), sub_str_cpy.end()); 

        // remove the first character of the reversed sub string
        string reversed_sub_str {sub_str_cpy.substr(1, sub_str_cpy.length())};

        // create a string to add the required shift to the pyramid level
        string white_space_shift (str.length()-i-1, ' ');

        // display the pyramid level
        cout << white_space_shift + sub_str + reversed_sub_str << endl;
    }

    return 0; 
}