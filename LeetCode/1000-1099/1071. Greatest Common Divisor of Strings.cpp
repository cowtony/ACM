// 辗转相除

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() > str2.length()) {
            return gcdOfStrings(str2, str1);
        } else if (str1.length() < str2.length()) {
            if (str2.substr(0, str1.length()) != str1) {
                return "";    
            }
            return gcdOfStrings(str1, str2.substr(str1.length()));
        } else {
            return str1 == str2? str1 : "";
        }
    }
};