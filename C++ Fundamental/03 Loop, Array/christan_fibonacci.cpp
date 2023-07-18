#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "This is the Fibonacci Sequence Printer 5000. It prints the Fibonacci "
            "Sequence up to a selected number." << endl;

// I used push_back() here to add the 1s because I got this weird error when adding them directly:
/* main.cpp:11:32: error: conversion from ‘int’ to non-scalar type ‘std::vector’ requested
   11 |     vector<int> fib_list = (1, 1);
      |                                ^  */
// The error is gone if I use push_back().

    vector<int> fib_list;
    fib_list.push_back(1);
    fib_list.push_back(1);
   
    int n;
    cin >> n;
   
    int i = 1;
   
    while (fib_list[i] < n) {
        fib_list.push_back(fib_list[i] + fib_list[i - 1]);
        i++;
    }
   
// If, for example, I used 19 as n, the program would originally go all the way up to 23.
// This, albeit a stupid solution, prevents that from happening.

    if (fib_list[i] > n) {
        fib_list.pop_back();
    }
   
    for (int number : fib_list) {
        cout << number << " ";
    }
}