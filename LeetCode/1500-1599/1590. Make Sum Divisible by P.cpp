class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int need = 0;
        for (int num : nums) {
            need = (need + num) % p;
        }
        
        int result = INT_MAX;
        int prefix_sum = 0;
        unordered_map<int, int> reminders;
        reminders[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            reminders[prefix_sum] = i;
            
            int reminder = (p + prefix_sum - need) % p;
            if (reminders.count(reminder) > 0) {
                result = min(result, i - reminders.at(reminder));
            }
        }
        return result == nums.size()? -1 : result;
    }
};
