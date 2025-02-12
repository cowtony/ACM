class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // Store the historical maximum value for a specific digitSum.
        vector<int> historical_max(82, -1);

        int result = -1;
        for (int num : nums) {
            int dSum = digitSum(num);
            if (historical_max[dSum] != -1) {
                result = max(result, historical_max[dSum] + num);
            }
            historical_max[dSum] = max(historical_max[dSum], num);
        }
        return result;
    }

    int digitSum(int num) {
        int result = 0;
        while (num) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }
};
