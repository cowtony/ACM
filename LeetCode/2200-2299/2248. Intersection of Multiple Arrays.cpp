class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> count(1001, 0);
        for (const auto& num_array : nums) {
            for (int num : num_array) {
                count[num]++;
            }
        }
        vector<int> result;
        for (int i = 1; i < count.size(); i++) {
            if (count[i] == nums.size()) {
                result.push_back(i);
            }
        }
        return result;
    }
};
