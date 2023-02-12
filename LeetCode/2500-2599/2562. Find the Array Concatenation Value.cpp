class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long result = 0;
        
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
            long long concate = nums[i];
            for (int n = nums[j]; n > 0; n /= 10) {
                concate *= 10;
            }
            result += concate + nums[j];
        }
        if (nums.size() % 2 == 1) {
            result += nums[nums.size() / 2];
        }
        return result;
    }
};
