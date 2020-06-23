class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_apparence(26, -1);
        for (int i = 0; i < S.length(); i++) {
            last_apparence[S[i] - 'a'] = i;
        }
        
        vector<int> res;
        int lo = 0;
        while (lo < S.length()) {
            int hi = last_apparence[S[lo] - 'a'];
            for (int i = lo; i <= hi; i++) {
                hi = max(hi, last_apparence[S[i] - 'a']);
            }
            res.push_back(hi - lo + 1);
            lo = hi + 1;
        }
        return res;
    }
};
