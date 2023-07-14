#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        cout << "Please input your number:" << endl;
        int num;
        cin >> num;

        string even_or_odd = num % 2? "odd" : "even";
        if (num > 0) {
            cout << "Your number is positive and " << even_or_odd << endl;
        } else if (num < 0) {
            cout << "Your number is negative and " << even_or_odd <<endl;
        } else { // num == 0
            cout << "Your number is zero and " << even_or_odd << endl;
        }
    }

    return 0;
}

