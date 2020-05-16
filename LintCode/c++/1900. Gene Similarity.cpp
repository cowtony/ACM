class Solution {
public:
    /**
     * @param Gene1: a string
     * @param Gene2: a string
     * @return: return the similarity of two gene fragments
     */
    string GeneSimilarity(string &Gene1, string &Gene2) {
        int same = 0;
        
        int i = 0, j = 0;
        int len1 = 0, len2 = 0;
        char c1, c2;
        while (!Gene1.empty() or !Gene2.empty()) {
            if (len1 == 0) {
                len1 = getNumber(Gene1);
                i += len1;
                c1 = Gene1[0];
                Gene1 = Gene1.substr(1);
            }
            if (len2 == 0) {
                len2 = getNumber(Gene2);
                j += len2;
                c2 = Gene2[0];
                Gene2 = Gene2.substr(1);
            }
            
            int min_len = min(len1, len2);
            if (c1 == c2) {
                same += min_len;
            }
            len1 -= min_len;
            len2 -= min_len;
        }
        return to_string(same) + "/" + to_string(i);
    }
    
    int getNumber(string &s) {
        int num = 0;
        int i = 0;
        while (!s.empty() and s[i] >= '0' and s[i] <= '9') {
            num = num * 10 + s[i] - '0';
            i++;
        }
        s = s.substr(i);
        return num;
    }
};
