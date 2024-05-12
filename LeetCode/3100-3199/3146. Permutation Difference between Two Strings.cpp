class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> index(26, -1);
        for (int i = 0; i < s.length(); i++) {
            index[s[i] - 'a'] = i;
        }
        
        int result = 0;
        for (int i = 0; i < t.length(); i++) {
            result += abs(i - index[t[i] - 'a']); 
        }
        return result;
    }
};
