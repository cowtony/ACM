class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> score;
        int max_num = INT_MIN;
        long prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_num = max(max_num, nums[i]);
            prefix_sum += nums[i] + max_num;
            score.push_back(prefix_sum);
        }
        return score;
    }
};
