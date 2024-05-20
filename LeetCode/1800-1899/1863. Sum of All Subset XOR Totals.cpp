class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bit_or = 0;
        for (int num : nums) {
            bit_or |= num;
        }
        
        return bit_or << (nums.size() - 1);
    }
};
