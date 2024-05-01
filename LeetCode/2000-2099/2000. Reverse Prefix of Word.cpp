class Solution {
public:
    string reversePrefix(string word, char ch) {
        string result;
        bool reversed = false;
        for (char c : word) {
            result += c;
            if (c == ch && !reversed) {
                reverse(result.begin(), result.end());
                reversed = true;
            }
        }
        return result;
    }
};
