class Solution {
public:
    bool checkValidString(string s) {
        int min_stack_size = 0, max_stack_size = 0;
        for (char c : s) {
            if (c == '(') {
                min_stack_size++;
                max_stack_size++;
            } else if (c == ')') {
                min_stack_size = max(min_stack_size - 1, 0);
                max_stack_size--;
            } else {
                min_stack_size = max(min_stack_size - 1, 0);
                max_stack_size++;
            }
            if (max_stack_size < 0) {
                return false;
            }
        }
        return min_stack_size == 0;
    }
};
