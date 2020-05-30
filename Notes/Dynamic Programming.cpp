// Longest Increasing Subsequence O(nlogn), O(n)
// LeetCode 300
int longestIncreasingSubsequence(vector<int>& nums) {
    vector<int> res;
    for(int num : nums) {
        auto it = std::lower_bound(res.begin(), res.end(), num);  // Binary Search O(logn)
        if(it == res.end()) { res.push_back(num); }
        else { *it = num; }
    }
    return res.size();  // The list may not be a feasible answer.
}

