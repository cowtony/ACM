class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        stack<int> s;
        for (int num : pushed) {
            s.push(num);
            while (!s.empty() and s.top() == popped[i]) {
                i++;
                s.pop();
            }
        }
        return s.empty();
    }
};
