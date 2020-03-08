class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int result = 1;
        int preVal = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == preVal)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
            preVal = nums[i];
        }
        
        return nums.size();
    }
};
