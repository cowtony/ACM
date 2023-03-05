class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        if (s.length() % 2 == 1) {
            s += '0';
        }
        sort(s.begin(), s.end());
        
        int result = 0;
        int base = 1;
        while (s.length() > 0) {
            result += base * (s.back() - '0');
            s.pop_back();
            result += base * (s.back() - '0');
            s.pop_back();
            base *= 10;
        }
        return result;
    }
};
