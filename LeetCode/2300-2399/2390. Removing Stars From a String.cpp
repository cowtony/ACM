class Solution {
public:
    string removeStars(string s) {
        string result;
        for (char c : s) {
            if (c == '*') {
                result.pop_back();
            } else {
                result += c;
            }
        }
        return result;
    }
};
