class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int result = 0;
        for (int i = 0; i <= s.length() - k; i++) {
            int val = stoi(s.substr(i, k));
            if (val != 0 && num % val == 0) {
                result++;
            }
        }
        return result;
    }
};
