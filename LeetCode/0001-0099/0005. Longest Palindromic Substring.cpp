class Solution {
public:
    string longestPalindrome(string s) {        
        string ss = "#";
        for (char c : s) {
            ss += c;
            ss += '#';
        }
        
        int max_right = -1, center = -1;
        int max_palindromic = 0, palindromic_idx = 0;
        vector<int> manacher(ss.length(), 0);
        
        for (int i = 0; i < ss.length(); ++i) {
            if (i >= max_right) {
                manacher[i] = expand(ss, i, 0);
            } else {
                int mirror = 2 * center - i;
                if (manacher[mirror] == max_right - i) {
                    manacher[i] = expand(ss, i, manacher[mirror]);
                } else {
                    manacher[i] = min(manacher[mirror], max_right - i);
                }
            }
            
            if (i + manacher[i] > max_right) {
                max_right = i + manacher[i];
                center = i;
            }
            if (manacher[i] > max_palindromic) {
                max_palindromic = manacher[i];
                palindromic_idx = i;
            }
        }
        
        return s.substr((palindromic_idx - max_palindromic) / 2, max_palindromic);
    }
    
    int expand(const string& s, int center, int len = 0) {
        int left = center - 1 - len;
        int right = center + 1 + len;
        for (; left >= 0 and right < s.length(); --left, ++right) {
            if (s.at(left) != s.at(right)) {
                break;
            }
        }
        return center - left - 1;
    };
};
