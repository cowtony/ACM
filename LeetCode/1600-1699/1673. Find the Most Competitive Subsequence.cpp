class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            while (!result.empty() && 
                   result.back() > nums[i] && 
                   result.size() + nums.size() - i > k) {
                result.pop_back();
            }
            if (result.size() < k) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};
