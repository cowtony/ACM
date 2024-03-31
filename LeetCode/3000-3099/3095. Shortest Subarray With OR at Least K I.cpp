class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bit_count(32, 0);
        int result = INT_MAX;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            if (nums[r] >= k) {
                return 1;
            }
            
            update(bit_count, nums[r], true);
            while (getNum(bit_count) >= k && l < r) {
                result = min(result, r - l + 1);
                update(bit_count, nums[l++], false);
            }
        }
        
        return result == INT_MAX? -1: result;
    }
    
    void update(vector<int>& bit_count, int num, bool add) const {
        int bit = 0;
        while (num > 0) {
            bit_count[bit] += add? (num % 2) : (- num % 2);
            num >>= 1;
            bit++;
        }
    }
    
    int getNum(vector<int>& bit_count) const {
        int num = 0;
        for (int i = 0, power = 1; i < 31; i++, power <<= 1) {
            if (bit_count[i] > 0) {
                num += power;
            }
        }
        return num;
    }
    
    
};
