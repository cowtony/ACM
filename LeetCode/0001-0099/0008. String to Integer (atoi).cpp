class Solution {
public:
    int myAtoi(string str) {
        while (!str.empty() and str.front() == ' ') {
            str.erase(str.begin());
        }

        long long negative = 1;
        if (str.front() == '-') {
            negative = -1;
            str.erase(str.begin());
        } else if (str.front() == '+') {
            str.erase(str.begin());
        }
        
        long long ret = 0;
        for (char c : str) {
            if (c < '0' or c > '9') {
                break;
            }
            ret *= 10;
            ret += c - '0';
            if (negative * ret > INT_MAX) {
                return INT_MAX;
            }
            if (negative * ret < INT_MIN) {
                return INT_MIN;
            }
        }
        return negative * ret;
    }
};
