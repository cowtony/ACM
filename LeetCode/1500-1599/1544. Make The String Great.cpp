class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char c : s) {
            if (!res.empty() && abs(c - res.back()) == 'a' - 'A') {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
