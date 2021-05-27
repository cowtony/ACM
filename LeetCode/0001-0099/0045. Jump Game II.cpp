class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int max_reach = 0;
        int previous_max_reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > previous_max_reach) {
                count++;
                previous_max_reach = max_reach;
            }
            max_reach = max(max_reach, nums[i] + i);
        }
        
        return count;
    }
};
