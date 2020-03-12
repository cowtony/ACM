class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
                s.erase(s.begin() + i);
            else
                break;
        }
            
        return s.size() - s.rfind(' ') - 1;
    }
};
