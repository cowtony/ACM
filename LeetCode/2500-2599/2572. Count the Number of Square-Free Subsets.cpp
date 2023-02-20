class Solution {
public:
    const int kMod = 1000000007;
    
    // Solution with 01 knapsack. O(1000 * 2^10), 400ms
    int squareFreeSubsets2(vector<int>& nums) {
        for (int& num : nums) {
            num = factorMapping(num);
        }
        vector<vector<int>> dp(nums.size(), vector<int>(1024, -1));
        return (dfs(nums, 0, 0, dp) + kMod - 1) % kMod;
    }

    // Solution with counting the distinct nums, O(2^19), 6ms
    int squareFreeSubsets(vector<int>& nums) {
        map<int, int> count;
        for (int i = 0; i < nums.size(); i++) {
            if (factorMapping(nums[i]) != -1) {
                count[factorMapping(nums[i])]++;  // Max 19 keys
            }
        }
        vector<pair<int, int>> num_count;
        for (auto [num, c] : count) {
            if (num > 0) {
                num_count.push_back({num, c});
            }
        }
        
        dfs2(num_count, 0, 0, 1);
        if (count[0] > 0) {  // Special handle for num 1, because we can select multiple 1s.
            return (result * pow2(count[0]) - 1 + kMod) % kMod;
        } else {
            return (result - 1 + kMod) % kMod;  // subtract all empty case.
        }   
    }
    
    int dfs(const vector<int>& nums, int i, int mask, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return 1;
        }
        if (dp[i][mask] >= 0) {
            return dp[i][mask];
        }
        dp[i][mask] = dfs(nums, i + 1, mask, dp);     // Not select
        if (nums[i] >= 0 && (mask & nums[i]) == 0) {  // select
            dp[i][mask] = (dp[i][mask] + dfs(nums, i + 1, mask | nums[i], dp)) % kMod;
        }
        return dp[i][mask];
    }
    
    // Map number to their prime factor representations.
    // If one prime factor appear more than once, marked -1.
    int factorMapping(int num) {
        static const vector<int> kMapping{-1,  0,  1,   2,  -1,  4,  
                                               3,  8,  -1,  -1,  5,
                                              16, -1,  32,   9,  6,
                                              -1, 64,  -1, 128, -1,
                                              10, 17, 256,  -1, -1,
                                              33, -1,  -1, 512,  7};
        return kMapping[num];
    }

    long long result = 0;
    void dfs2(const vector<pair<int, int>>& num_count, int i, int mask, long long count = 1) {
        if (i == num_count.size()) {
            result = (result + count) % kMod;
            return;
        }
        dfs2(num_count, i + 1, mask, count);  // Not select
        if ((mask & num_count[i].first) == 0)// select
            dfs2(num_count, i + 1, mask | num_count[i].first, (count * num_count[i].second) % kMod); 
    }

    int pow2(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * 2) % kMod;
        }
        return result;
    }
};
