class Solution {
public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b){
            if (a.first == b.first) {
                // Second element in reverse order to make sure [3, 3] will not put into [3, 4].
                return b.second < a.second; 
            } else {
                return a.first < b.first;
            }
        });
        
        // Longest Increasing Subsequence O(nlogn), O(n)
        vector<int> res;
        for(auto p : envelopes) {
            auto it = std::lower_bound(res.begin(), res.end(), p.second);  // Binary Search O(logn)
            if(it == res.end()) { res.push_back(p.second); }
            else { *it = p.second; }
        }
        return res.size();  // The list may not be a feasible answer.
    }
};
