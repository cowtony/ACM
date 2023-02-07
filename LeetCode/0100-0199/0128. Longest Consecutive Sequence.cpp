class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_table(nums.begin(), nums.end());

        int result = 0;
        for (int num : nums) {
            if (hash_table.find(num - 1) == hash_table.end()) { // Begin of a sequence
                int n = num + 1;
                while (hash_table.find(n) != hash_table.end()) {
                    n++;
                }
                result = max(result, n - num);
            }
        }
        return result;
    }
};