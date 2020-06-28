class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        static vector<int> kTwoPowMod({1}); // Store the value of 2^n % mod.
        
        int res = 0;
        for (int lo = 0, hi = nums.size() - 1; lo < nums.size(); lo++) {
            while (lo <= hi and nums[lo] + nums[hi] > target) {
                hi--;
            } 
            if (lo > hi) {
                break;
            }
            
            while (kTwoPowMod.size() <= hi - lo) {
                kTwoPowMod.push_back((kTwoPowMod.back() * 2) % 1000000007);
            }
            res = (res + kTwoPowMod[hi - lo]) % 1000000007;
        }
        
        return res;
    }
    
    // Calculate 2^n % mod in O(log n).
    int twoPowMod(int n, int mod = 1000000007) {
        int ret = 1;
        uint64_t base = 2;
        while (n > 0) {
            if (n & 1) {
                ret = (ret * base) % mod;
            }
            base = (base * base) % mod;
            n >>= 1;
        }
        return ret;
    }
};

