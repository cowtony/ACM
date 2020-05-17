class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        for (auto& v : favoriteCompanies) {
            sort(v.begin(), v.end());
        }
        
        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (isSubSet(favoriteCompanies[i], favoriteCompanies[j])) {
                    goto end;
                }
            }
            res.push_back(i);
            end:;
        }
        
        return res;
    }
    
    // Check if a is a subset of b. a and b must be sorted before.
    bool isSubSet(vector<string>& a, vector<string>& b) {
        int i = 0; 
        int j = 0;
        while (i < a.size() and j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                if (a[i] < b[j]) {
                    return false;
                } else {
                    j++;
                }
            }
        }
        return i == a.size();
    }
};
