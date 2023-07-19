#include <iostream>
using namespace std;


bool isPrimeNumber(int number) {
    for (int div = 2; div * div <= number; div++) {
        if (number % div == 0) {
            // `number` is not a prime number.
            return false;
        }
    }
    return true;
}


int main() {
    // Output all prime numbers with 100000.
    cout << 2 << " ";
    // Try each ODD number from 3 to 100.
    for (int num = 3; num <= 100; num += 2) {
        if (isPrimeNumber(num)) {
            cout << num << " ";
        }
    }

    return 0;
}
