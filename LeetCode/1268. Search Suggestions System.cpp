class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string>> res;
        for (int len = 1; len <= searchWord.length(); len++) {
            vector<string> suggestions;
            auto it = lower_bound(products.begin(), products.end(), searchWord.substr(0, len));
            for (int i = 0; i < 3; i++) {
                if (it == products.end() or searchWord.substr(0, len) != it->substr(0, len)) {
                    break;
                }
                suggestions.emplace_back(*it++);
            }
            res.emplace_back(suggestions);
        }
        
        return res;
    }
};
