class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int a : nums) {
            for (int b : nums) {
                count[a & b]++;
            }
        }
        int result = 0;
        for (int num : nums) {
            for (auto& [x, c] : count) {
                if ((num & x) == 0) {
                    result += c;
                }
            }
        }
        return result;
    }
};
