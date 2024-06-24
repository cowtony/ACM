class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> flip(nums.size(), false);

        int result = 0;
        bool current_flip = false;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && flip[i - k]) {
                current_flip = !current_flip;
            }
            if ((nums[i] ^ current_flip) == 0) {  // Need flip from 0 to 1
                if (i + k > nums.size()) {
                    return -1;
                }
                flip[i] = true;
                current_flip = !current_flip;
                result++;
            }
        }
        return result;
    }
};
