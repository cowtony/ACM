class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int result = 0;
        for (auto [key, value] : count) {
            if (count.find(key + k) != count.end()) {
                result += count.at(key + k) * value;
            }
        }
        return result;
    }
};