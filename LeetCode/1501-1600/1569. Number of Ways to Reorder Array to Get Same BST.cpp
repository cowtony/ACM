class Solution {
public:
    int numOfWays(vector<int>& nums) {
        return (helper(nums) + 1000000007 - 1) % 1000000007;
    }
    
    long helper(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        
        // cout << "show: ";
        // for (int num : nums) {
        //     cout << num << ' ';
        // }
        // cout << endl;
        
        vector<int> large, small;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                large.push_back(nums[i]);
            } else { // <
                small.push_back(nums[i]);
            }
        }

        return (((combinition(large.size(), small.size()) * helper(large)) % 1000000007) * helper(small)) % 1000000007;
    }
    
    long combinition(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        // a >= b
        if (b == 0) {
            return 1;
        }
        
        static vector<vector<long>> dp(1001, vector<long>(1001, -1));
        // cout << a << ' ' << b << endl;
        if (dp[a][b] != -1) {
            return dp[a][b];
        }
        
        return dp[a][b] = (combinition(a - 1, b) + combinition(a, b - 1)) % 1000000007;
    }
};
