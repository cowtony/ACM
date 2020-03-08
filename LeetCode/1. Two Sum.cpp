class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums.at(i)) == m.end()) {
                m[target - nums.at(i)] = i;
            } else {
                return {m[nums.at(i)], i};
            }
        }
        return {};
    }
};
