class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pop_i = 0;
        int stack_size = 0; 
        for (int num : pushed) {
            // Push action: Borrow pushed as stack.
            pushed[stack_size++] = num; 
            
            while (stack_size > 0 and pushed[stack_size - 1] == popped[pop_i]) {
                // Pop action.
                pop_i++;
                stack_size--;
            }
        }
        return stack_size == 0;
    }
};
