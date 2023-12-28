// ------------------------------ Section 10 - Section Challenge ------------------------------
// Encrypts and decryptes a message 

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <random>

using namespace std;

int main() {

    string alphabet; 

    // append the capital letters
    for (char c='A'; c<='Z'; c++)
        alphabet += c;
    for (char c='a'; c<='z'; c++) 
        alphabet += c; 

    // create a suitable key 
    string key {alphabet}; 
    random_device rd;
    mt19937 g(rd()); 

    shuffle(key.begin(), key.end(), g);

    // read the user message
    string message;
    cout << "Enter the message: "; 
    getline(cin, message);

    // perform the encryption
    cout << "\nEncrypting.................." << endl << endl;

    string encrypted_msg; 
    for (char c: message) {
        if (isalpha(c))
            encrypted_msg += key.at(alphabet.find(c));
        else 
            encrypted_msg += c;
    }

    cout << "encrypted msg: " << encrypted_msg << endl << endl;

    // perform the decryption
    cout << "Decrypting.................." << endl << endl;

    string decrypted_msg;
    for (char c: encrypted_msg) {
        if (isalpha(c))
            decrypted_msg += alphabet.at(key.find(c));
        else
            decrypted_msg += c;
    }

    cout << "decrypted msg: " << decrypted_msg << endl << endl;

    if (message == decrypted_msg)
        cout << "Encryptiong and Decryption are successful..." << endl;
    else
        cout << "ERROR: Decrypted message is not correct!!!" << endl;
    

    return 0;
}