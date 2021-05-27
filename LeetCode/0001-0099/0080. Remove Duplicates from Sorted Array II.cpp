class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int pointer = 1;
        int occurance = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                occurance++;
            } else {
                occurance = 1;
            }
            nums[pointer] = nums[i];
            if (occurance <= 2) {
                pointer++;
            }
        }
        return pointer;
    }
};
