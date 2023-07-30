#include <iostream>
using namespace std;

// return nth Fibonacci number
// 1. Ending condition
// 2. f3 = f2 + f1
int fibonacci(int n) {
    if (n == 1 or n == 2) {
        return 1;
    } else if (n <= 0) {
        return 0;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}


int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
}
