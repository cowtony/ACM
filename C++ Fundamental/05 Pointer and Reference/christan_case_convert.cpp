// I did the one about turning a string uppercase/lowercase
#include <iostream>

using namespace std;

enum class Case {
    UPPER,
    LOWER,
};

void caseConverter(string &str, Case u_or_l)
{
    for (char& c : str) {
        if (u_or_l == Case::UPPER) {
            c = toupper(c);
        } else if (u_or_l == Case::LOWER) {
            c = tolower(c);
        }
    }
}

int main()
{
    string inputString;
    string reqCase;

    cout << "Input your string here. This program will make it entirely uppercase/lowercase." << endl;
    getline(cin, inputString);

    cout << "Do you want it to be converted to upper or lowercase (\"upper\"/\"lower\")?" << endl;
    cin >> reqCase;

    cout << reqCase << endl;

    // I do realize that it would've been a lot easier to cout this in the function,
    // but it makes using a reference kind of pointless

    if (reqCase == "upper") {
        caseConverter(inputString, Case::UPPER);
        cout << "The uppercase string is: \"" << inputString << "\". Yay!" << endl;
    } else if (reqCase == "lower") {
        caseConverter(inputString, Case::LOWER);
        cout << "The lowercase string is: \"" << inputString << "\". Yay!" << endl;
    } else {
        cout << "Invalid input! Get outta here!" << endl;
        exit(3);
    }
}
