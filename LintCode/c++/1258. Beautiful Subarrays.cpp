class Solution {
public:
    /**
     * @param nums: an integer list
     * @param numOdds: an integer
     * @return: return the number of beautiful subarrays
     */
    int BeautifulSubarrays(vector<int> &nums, int numOdds) {
        vector<int> odd_idx;
        odd_idx.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                odd_idx.push_back(i + 1);
            }
        }
        odd_idx.push_back(nums.size() + 1);
        if (odd_idx.size() - 2 < numOdds) {
            return 0;
        }
        
        int ret = 0;
        for (int i = 1; i + numOdds < odd_idx.size(); i++) {
            int x = (odd_idx[i] - odd_idx[i - 1]) * (odd_idx[i + numOdds] - odd_idx[i + numOdds - 1]);
            ret += x;
        }
        return ret;
    }
};
