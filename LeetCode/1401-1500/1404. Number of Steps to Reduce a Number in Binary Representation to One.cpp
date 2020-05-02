class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
                count++;
            } else {// s[i] == '1'
                int i;
                for (i = s.length() - 1; i >= 0; i--) {
                    if (s[i] == '0') {
                        s[i] = '1';
                        break;
                    } else {
                        s[i] = '0';
                    }
                }
                if (i == -1) {
                    s = '1' + s;
                }
                count++;
            }
        }
        return count;
    }
};
