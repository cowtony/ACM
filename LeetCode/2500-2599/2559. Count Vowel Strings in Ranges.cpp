class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix_sum(words.size() + 1, 0);
        for (int i = 0; i < words.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + (vowelWord(words[i])? 1 : 0);
        }
        
        vector<int> result;
        for (const vector<int>& query : queries) {
            result.push_back(prefix_sum[query[1] + 1] - prefix_sum[query[0]]);
        }
        return result;
    }
    
    bool vowelWord(const string& word) {
        static unordered_set<char> kVowel = {'a', 'e', 'i', 'o', 'u'};
        return kVowel.find(word.front()) != kVowel.end() && kVowel.find(word.back()) != kVowel.end();
    }
};
