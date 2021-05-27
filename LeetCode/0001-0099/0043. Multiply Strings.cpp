struct BigInt {
    vector<int> digit;
    
    BigInt(const string& s = "") {
        for (int i = s.length() - 1; i >= 0; i--) {
            digit.emplace_back(s[i] - '0');
        }
    }
    
    string toString() const {
        string s;
        for (int d : digit) {
            s = char(d + '0') + s;
        }
        return s;
    }
    
    BigInt operator *(const BigInt& num) const {
        BigInt result;
        int lo = 0, hi = 0;
        int len = max(num.digit.size(), this->digit.size());
        
        int remain = 0;
        while (lo < len) {
            for (int i = lo, j = hi; i <= hi and j >= lo; i++, j--) {
                if (i < this->digit.size() and j < num.digit.size()) {
                    remain += this->digit[i] * num.digit[j];
                }
            }
            result.digit.push_back(remain % 10);
            remain /= 10;
            
            if (hi < len - 1) {
                hi++;
            } else {
                lo++;
            }
        }
        while (remain > 0) {
            result.digit.push_back(remain % 10);
            remain /= 10;
        }
        while (result.digit.size() > 1 and result.digit.back() == 0) {
            result.digit.pop_back();
        }

        return result;
    }
    
};

class Solution {
public:
    string multiply(string num1, string num2) {
        BigInt a(num1);
        BigInt b(num2);
        return (a * b).toString();
    }
};
