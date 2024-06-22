class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        nums.push_back(1);
        int l = 0, r = 0, odd = 0;
        for (;r < nums.size() && odd < k; r++) {
            if (nums[r] % 2 == 1) {
                odd++;
            }
        }

        int result = 0;
        while (r < nums.size()) {
            int l_count = 1;
            while (l < nums.size() && nums[l++] % 2 == 0) {
                l_count++;
            }
            int r_count = 1;
            while (r < nums.size() && nums[r++] % 2 == 0) {
                r_count++;
            }
            result += l_count * r_count;
        }
        return result;
    }
};
