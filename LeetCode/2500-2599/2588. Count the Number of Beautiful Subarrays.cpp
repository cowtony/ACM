class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> xor_count{{0, 1}};
        int running_xor = 0;
        long long result = 0;
        for (int num : nums) {
            running_xor ^= num;
            result += xor_count[running_xor]++;
        }
        return result;
    }
};
