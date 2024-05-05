class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> count;
        int max_count = 0;
        for (int i = 0; i < word.length(); i += k) {
            max_count = max(max_count, ++count[word.substr(i, k)]);
        }
        
        return word.length() / k - max_count;
    }
};
