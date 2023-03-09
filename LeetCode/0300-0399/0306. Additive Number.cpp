class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int len1 = 1; len1 <= num.length() / 2; ++len1) {
            for (int len2 = 1; max(len1, len2) <= num.length() - len1 - len2; ++len2) {
                if (check(num, len1, len2)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check(const string& num, int len1, int len2) {
        int i = 0;
        while (i + len1 + len2 < num.length()) {
            string a = num.substr(i, len1);
            string b = num.substr(i + len1, len2);
            if (a.length() > 1 && a.front() == '0' || 
                b.length() > 1 && b.front() == '0') {
                return false;
            }
            string sum = add(a, b);
            if (num.length() - i - len1 - len2 < sum.length()) {
                return false;
            }
            if (sum != num.substr(i + len1 + len2, sum.length())) {
                return false;
            }
            i += len1;
            len1 = len2;
            len2 = sum.length();
        }
        return true;
    }

    string add(string a, string b) {
        string result;
        int carry = 0;
        while (!a.empty() || !b.empty()) {
            if (!a.empty()) {
                carry += a.back() - '0';
                a.pop_back();
            }
            if (!b.empty()) {
                carry += b.back() - '0';
                b.pop_back();
            }
            result += (carry % 10) + '0';
            carry /= 10;
        }
        if (carry > 0) {
            result += carry + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }

};
