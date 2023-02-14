class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int result = nums[0];
        for (int num : nums) {
            result = gcd(result, num);
        }
        return result == 1;
    }
};
