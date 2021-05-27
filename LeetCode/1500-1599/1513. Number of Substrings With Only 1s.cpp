class Solution {
public:
    int numSub(string s) {
        long count_1 = 0;
        s.push_back('0');
        
        long res = 0;
        for (char c : s) {
            if (c == '0') {
                count_1 = 0;
            } else {
                count_1++;
                res = (res + count_1) % 1000000007;
            }
        }
        return res;
    }
};
