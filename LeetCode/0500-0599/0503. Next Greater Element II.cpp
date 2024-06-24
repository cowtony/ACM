class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int max_idx = distance(nums.begin(), max_element(nums.begin(), nums.end()));

        stack<int> mono_decrease;
        vector<int> result(nums.size(), -1);
        for (int i = 0, idx = (max_idx + 1) % nums.size(); i < nums.size(); i++, idx = (idx + 1) % nums.size()) {
            while (!mono_decrease.empty() && nums[idx] > nums[mono_decrease.top()]) {
                result[mono_decrease.top()] = nums[idx];
                mono_decrease.pop();
            }

            mono_decrease.push(idx);
        }

        return result;
    }
};
