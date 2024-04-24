class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total_customer = 0;
        int unsatisfied = 0;
        int current_suppressed = 0;
        int max_suppressed = 0;
        for (int i = 0; i < customers.size(); i++) {
            total_customer += customers[i];
            if (grumpy[i] == 1) {
                unsatisfied += customers[i];
                current_suppressed += customers[i];
            }
            if (i - minutes >= 0 && grumpy[i - minutes] == 1) {
                current_suppressed -= customers[i - minutes];
            }
            max_suppressed = max(max_suppressed, current_suppressed);
        }
        
        return total_customer - unsatisfied + max_suppressed;
    }
};
