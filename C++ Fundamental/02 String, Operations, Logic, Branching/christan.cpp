// Chose the second option, used last time's homework as foundation

#include <iostream>

using namespace std;

int main()
{  // In the same line of `main()`
    cout<<"Hello! Welcome to Christan's ultimate calculator v2!" << endl;  // Spaces between `<<`
   
    bool should_continue = true;
   
    while (should_continue){  // Space before {
        char operation;
        // One suggestion is you can write the string in multiline. Normally we won't exceed 80 chars per line.
        cout << "Enter the operation here. 'm' for multiplication, "
                "'d' for division, 'a' for addition, and 's' for subtraction!" << endl;
        cin >> operation;
       
        double num1;  // double num1, num2;
        double num2;
        cout << "Enter the first number here: " << endl;
        cin >> num1;
        cout << "Enter the second number here: " << endl;
        cin >> num2;
       
        switch(operation) {
            case 'm':
                cout << "The product is " << num1 * num2 << endl;
                break;
            case 'd':
                cout << "The answer is " << num1 / num2 << endl;
                break;
            case 'a':
                cout << "The sum is " << num1 + num2 << endl;
                break;
            case 's':
                cout << "The answer is " << num1 - num2 << endl;
                break;
            default:
                // Haha!! Yeah!!
                cout << "Invalid operation. Get outta here. You're banned from the premises. "
                        "Come back and I'm calling the cops." << endl;
                exit(3);
        }
       
        cout << "Continue? 'true' or 'false'" << endl;
        cin >> std::boolalpha >> should_continue;
    }
   
    cout << "Hope you liked this calculator! Leave a good review if you did!... "
            "Or else... There WILL be consequences..." << endl;
   
    return 0;
}