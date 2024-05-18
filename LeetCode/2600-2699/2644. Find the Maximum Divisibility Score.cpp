class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max_score = 0;
        int min_divisor = INT_MAX;
        for (int divisor : divisors) {
            int count = count_if(nums.begin(), nums.end(), [divisor](int num) {
                return num % divisor == 0;
            });
            if (count > max_score) {
                min_divisor = divisor;
                max_score = count;
            } else if (count == max_score) {
                min_divisor = min(min_divisor, divisor);
            }
        }
        return min_divisor;
    }
};
