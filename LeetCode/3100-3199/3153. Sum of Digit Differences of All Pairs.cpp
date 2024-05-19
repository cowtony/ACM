class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long sum = 0;
        while (nums[0] > 0) {
            vector<int> count(10, 0);
            for (int& num : nums) {
                count[num % 10]++;
                num /= 10;
            }
            
            sum += helper(count, nums.size());
        }
        return sum;
    }
    
    long long helper(const vector<int>& count, int size) {
        long long sum = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                sum += (long long)(count[i]) * count[j];
            }
        }
        return sum;
    }
    
};
