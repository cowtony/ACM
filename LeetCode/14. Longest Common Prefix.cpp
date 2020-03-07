class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.size() == 0)
            return result;
        
        size_t minSize = 99999;
        for (string s: strs)
            minSize = min(minSize, s.size());
        
        for (int i = 0; i < minSize; i++)
        {
            char c = strs[0][i];
            for (string s: strs)
            {
                if (c != s[i])
                    return result;
            }
            result += c;
        }
        return result;
    }
};
