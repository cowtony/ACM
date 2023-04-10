class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                sta.push(c);
            } else if (!sta.empty() && c > sta.top() && c - sta.top() <= 2) {  // In ASCII the left and right bracket has at most 2 index away.
                sta.pop();
            } else {
                return false;
            }
        }
        return sta.empty();
    }
};
