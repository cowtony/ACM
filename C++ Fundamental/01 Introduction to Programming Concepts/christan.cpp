#include <iostream>

using namespace std;

int main()
{  // Normally the `{` is following the function definition in teh same line, instead of a new line: `int main() {`
    cout<<"Hello！ Welcome to Christan's ultimate calculator!" << endl;  // The first "!" seems in wide-char (Chinese input method). This might be very deceptive when you have '；'
   
    bool cont = true;  // Suggest using a differnt name, such as `should_continue`, because `cont` is very silimar to `cout`.
    double num1;  // Prefer to declare right before usage. I.E. move into the while loop.
    double num2;  // same
    string operation;  // same, this will help your code more readable.
   
    while (cont){  // Add a space before '{'
        cout << "Enter the operation here. 'm' for multiplication and 'd' for division!" << endl;
        cin >> operation;
       
        cout << "Enter the first number here: " << endl;
        cin >> num1;
        cout << "Enter the second number here: " << endl;
        cin >> num2;
       
        if (operation == "m"){ // Add a space before '{'
            cout << "The product is " << num1 * num2 << "." << endl;
        }
        if (operation == "d"){ // Add a space before '{'
            cout << "The answer is " << num1 / num2 << "." << endl;
        }
       
        cout << "Continue? 'true' or 'false'" << endl;
        cin >> std::boolalpha >> cont;   // This `std::boolalpha` is cool!
        // Althernatively, You can add a `if (!cond) { break; }` here, then you don't need to define `bool cont` outside of while loop as well.
    }
    return 0;
}