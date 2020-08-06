class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
