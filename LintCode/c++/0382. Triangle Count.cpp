class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(), S.end());
        int ans = 0;
        for (int i = S.size() - 1; i >= 2; i--) {
            ans += twoSum(S, i, S[i]);
        }
        return ans;
    }
    
    // Find the pairs that two number sum > target.
    int twoSum(vector<int>& S, int size, int target) {
        int lo = 0;
        int ans = 0;
        for (int hi = size - 1; hi > lo; hi--) {
            while (S[lo] + S[hi] <= target and lo < hi) {
                lo++;
            }
            ans += hi - lo;
        }
        return ans;
    }
};
