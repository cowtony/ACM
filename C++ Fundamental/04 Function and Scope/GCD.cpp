#include <iostream>
using namespace std;

// 14 = 2 * 7
// 35 = 5 * 7
// GCD(14, 35) = 7
// Euclid's algorithm:
// GCD(14, 35) = GCD(14, 21) = GCD(14, 7) = GCD(7, 7)


// return GCD of a and b
// 1. a == b
// 2. (big, small) -> (big - small, small)
int GCD(int x, int y) {
    if (x == 0) {
        return y;
    }

    return GCD(y, x % y);
}


int main() {
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b);
}
