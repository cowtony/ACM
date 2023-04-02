class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> count(nums.size() + 1, 0);
        vector<vector<int>> result;
        for (int num : nums) {
            if (result.size() <= count[num]) {
                result.push_back({});
            }
            result[count[num]].push_back(num);
            count[num]++;
        }
        return result;
    }
};
