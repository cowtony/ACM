class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int result = 0;
        for (auto [num, c] : count) {
            result += c / 2;
        }
        return {result, int(nums.size()) - result * 2};
    }
};
