class Solution {
public:
    string reformat(string s) {
        string letter;
        string number;
        for (char c : s) {
            if (c >= '0' and c <= '9') {
                number += c;
            } else {
                letter += c;
            }
        }
        
        if (letter.length() < number.length()) {
            swap(letter, number);
        }
        if (letter.length() - number.length() > 1) {
            return "";
        }
        string ret;
        while (!letter.empty() and !number.empty()) {
            ret += letter[0];
            letter = letter.substr(1);
            ret += number[0];
            number = number.substr(1);
        }
        return ret + letter;
    }
};
