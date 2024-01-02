// --------------------------------- pointers ---------------------------------

#include <iostream>

using namespace std;

int main() {


    // -------------- using address operator --------------
    int num {10};

    // access the value of the variable
    cout << "value of num is " << num << endl; // 10
    // know the size of the memory space acquired by the variable
    cout << "size of num is " << sizeof num << endl; // 4
    // find the memory location the variable is stored at
    cout << "address of num is " << &num << endl; // 0x7fffffffddb4 - a hexadecimal pointer


    // ---------------- using C++ pointers ----------------
    int *p; 

    // access the value of the pointer `p`
    cout << "value of p is " << p << endl; // garbage hexadecimal address
    // know the size of the pointer
    cout << "size of p is " << sizeof p << endl; // 8 (???)
    // find the address of the pointer
    cout << "address of p is " << &p << endl; // hexadecimal address

    // we can assign new addresses to the pointer `p`
    p = nullptr; // 0 
    // access the new value of the pointer
    cout << "new value of p is " << p << endl; // 0


    return 0;
}