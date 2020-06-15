class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> count;
        for (int a : arr) {
            count[a]++;
        }
        
        vector<int> counts;
        for (auto p : count) {
            counts.push_back(p.second);
        }
        
        sort(counts.begin(), counts.end());
        
        int sum = 0;
        for (int i = 0; i < counts.size(); i++) {
            sum += counts[i];
            if (sum > k) {
                return counts.size() - i;
            }
        }
        return 0;
    }
};
