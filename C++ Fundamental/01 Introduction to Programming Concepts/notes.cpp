#include <iostream>
using namespace std;

// Comment starts with two slashes.
// Use Ctrl + / to quickly comment / uncomment a line.

/*
This is an example of multiline comment.
*/

int main() {
    // Primitive data types:
    // Integer
    short sh;        // 2 bytes, -2^15 to 2^15 - 1
    int i;           // 4 bytes, -2^31 to 2^31 - 1, most frequently used.
    long lo;         // 4 bytes, same as `int`
    long long ll;    // 8 bytes, -2^63 to 2^63 - 1
    signed int si;   // Same as `int`, `signed` can be omitted.
    unsigned int ui; // 0 to 2^32 - 1
    // The `sizeof` is helpful to show the size of a data type.
    cout << "The `long long` type takes " << sizeof(long) << " bytes." << endl;

    // Floating point number
    float f = 1.0;   // 4 bytes
    double d = 2.1;  // 8 bytes

    // Charachter
    char c = 'A';    // 1 byte

    // Boolean
    bool b = true;   // 1 byte

    // Input: c-in
    cin >> i;
    // Output: c-out; `endl` stand for end-line
    cout << "The integer you typed is: " << i << endl;
    

    return 0;
}