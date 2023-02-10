class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> left_idx;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left_idx.push(i);
            } else if (s[i] == ')') {
                if (!left_idx.empty()) {
                    left_idx.pop();
                } else {
                    s[i] = '*';
                }
            }
        }
        while (!left_idx.empty()) {
            s[left_idx.top()] = '*';
            left_idx.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
