class Solution {
public:
    int confusingNumberII(int N) {
        string s = to_string(N);
        return countConfusingNumber(s) - countSameConfusingNumber(s) - 1;
    }
    
private:
    const unordered_map<char, char> confusing_digits = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    const vector<int> how_many_before = {0, 1, 2, 2, 2, 2, 2, 3, 3, 4, 5};
    
    int countConfusingNumber(const string& s) {
        if (s.length() == 1) {
            return how_many_before[s[0] - '0' + 1];
        }
        int res = (how_many_before.at(s[0] - '0')) * pow(5, s.length() - 1);
        if (confusing_digits.find(s.front()) != confusing_digits.end()) {
            res += countConfusingNumber(s.substr(1));
        }
        return res;
    }
    
    // Count all ConfusingNumber which equal to itseft after rotate except 0.
    int countSameConfusingNumber(const string& s, string path = "") {
        if (s.empty()) {
            return 0;
        }
        if (path.length() == (s.length() + 1) / 2) {
            // Exclude the odd length with 6 or 9 in the middle.
            if (s.length() % 2 == 1 and (path.back() == '6' or path.back() == '9')) {
                return false;
            }
            // Fill the right half of the string.
            for (int i = s.length() / 2 - 1; i >= 0; i--) {
                path += confusing_digits.at(path[i]);
            }
            return path <= s? 1 : 0;
        }
        
        int res = 0;
        for (char c : {'0', '1', '6', '8', '9'}) {
            if (path.empty() and c == '0') {
                res += countSameConfusingNumber(string(s.length() - 1, '9'), path);
            } else {
                res += countSameConfusingNumber(s, path + c);
            }
        }
        return res;
    }
};
