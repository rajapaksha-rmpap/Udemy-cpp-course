// ----------------------------- C++-style Strings -----------------------------

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // declaring and initializing C++-style strings
    string s1;              // empty
    string s2 {"Akila"};    // Akila
    string s3 {s2};         // Akila
    string s4 {"Akila", 3}; // Aki
    string s5 {"Akila", 1, 3}; // kil
    string s6 (3, 'A');     // AAA 

    vector<string> str_vec {s1, s2, s3, s4, s5, s6};

    cout << "the initalized strings: " << endl; 
    for (string s: str_vec)
        cout << "\t" << s << endl;

    string breakline (20, '-');
    cout << breakline << endl << endl;
    
    
    s1 = "Rajapaksha"; // the string will dynamically expand. 
    cout << "s1 - " << s1 << endl;
 
    s1 = s2; // Akila - the string will dynamically shrink. 
    cout << "s1 - " << s1 << endl;

    cout << breakline << endl << endl;


    string first_name {"Akila"};
    string last_name  {"Rajapaksha"};

    string full_name = first_name + " " + last_name; // here, `first_name` and `last_name` are C++-style strings, whereas " " is a C-style string literal. 
    cout << "Full name is " << full_name << "." << endl; 

    // cout << "Full name is " << "Akila" + " " + "Rajapaksha" << endl; // ERROR!!!; all strings are of C-style. 

    cout << breakline << endl << endl;


    string whole_name = "Akila Rajapaksha"; 
    
    cout << whole_name[10] << ", " << whole_name[18] << endl; // p, <garbage>
    cout << whole_name.at(10) << ", "; // p, 
    // cout << whole_name.at(18) << endl; // ERROR

    cout << breakline << endl << endl; 

    // iterating over a string
    for (char c: full_name)
        cout << c << endl;

    cout << breakline << endl << endl; 

    string fruit {"Apple"}; 
    if (fruit < "Banana")
        cout << fruit + " is smaller than Banana." << endl; 
    if (fruit < "apple")
        cout << fruit + " is smaller than apple in lowercase." << endl; 
    string fruit_ {"App"}; 
    if (fruit_ < "apple")
        cout << fruit_ << " is smaller than apple in lowercase." << endl; 
    if ("App" < "apple") // NO ERROR; BUT INCORRECT OPERATION!!!
        cout << "App" << " is smaller than apple in lowercase." << endl; 

    cout << breakline << endl << endl; 
    
    // some useful string methods (.length(), .substr(), .find())
    string phrase {"This is me trying"};
    cout << "length of the phrase: " << phrase.length() << endl; 
    cout << "first 4 chars: " + phrase.substr(0, 4) << endl;
    cout << "last 4 chars: " + phrase.substr(phrase.length()-4, 4) << endl;
    cout << "'is' is found at: " << phrase.find("is") << endl;
    cout << "'is' is found at after the first word: " << phrase.find("is", 4) << endl; 
    cout << "'e' is found at: " << phrase.find('e') << endl; 
    cout << "'a' is found at: " << phrase.find('a') << endl; // 'a' is found at: 18446744073709551615 (???)

    cout << breakline << endl << endl; 


    // ----------------------------- QUIZ 1 -----------------------------
        
    string unformatted_full_name {"StephenHawking"};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    size_t last_name_start_idx = unformatted_full_name.find('H'); 
    
    string first_name_ {unformatted_full_name, 0, 7}; // ???
    string last_name_ = unformatted_full_name.substr(last_name_start_idx);
    
    string formatted_full_name = first_name_ + last_name_; // StephenHawking
    
    formatted_full_name.insert(last_name_start_idx, 1, ' '); // Stephen Hawking
    
    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << "Full name: " + formatted_full_name <<endl;
    
    cout << breakline << endl << endl; 


    // ----------------------------- QUIZ 2 -----------------------------

    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};
    
    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
    //----WRITE YOUR CODE BELOW THIS LINE----
    
    // remove the first name from journal_entry_1
    journal_entry_1.erase(0, journal_entry_1.find('N'));
    
    if (journal_entry_1 > journal_entry_2) 
        journal_entry_1.swap(journal_entry_2); 

    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
    
    cout << journal_entry_1 << "\n" << journal_entry_2 << endl;


    return 0; 
}