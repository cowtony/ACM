class Solution {
public:
    bool checkValidString(string s) {
        int min_stack_size = 0, max_stack_size = 0;
        for (char c : s) {
            switch (c) {
                case '(':
                    min_stack_size++;
                    max_stack_size++;
                    break;
                case ')':
                    if (min_stack_size > 0) {
                        min_stack_size--;
                    }
                    max_stack_size--;
                    if (max_stack_size < 0) {
                        return false;
                    }
                    break;
                case '*':
                    if (min_stack_size > 0) {
                        min_stack_size--;
                    }
                    max_stack_size++;
                    break;
            }
        }
        return min_stack_size <= 0 and max_stack_size >= 0;
    }
};
