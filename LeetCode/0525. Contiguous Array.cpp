class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        int max_length = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                sum--;
            } else {
                sum++;
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
            max_length = max(max_length, i - m[sum]);
        }
        return max_length;
    }
};
