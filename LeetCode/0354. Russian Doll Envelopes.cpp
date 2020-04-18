class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b){
            if (a[0] == b[0]) {
                // Second element in reverse order to make sure [3, 3] will not put into [3, 4].
                return b[1] < a[1]; 
            } else {
                return a[0] < b[0];
            }
        });
        
        // Longest Increasing Subsequence O(nlogn), O(n)
        vector<int> res;
        for(auto p : envelopes) {
            auto it = lower_bound(res.begin(), res.end(), p[1]);  // Binary Search O(logn)
            if(it == res.end()) { res.push_back(p[1]); }
            else { *it = p[1]; }
        }
        return res.size();  // The list may not be a feasible answer.
    }
};
