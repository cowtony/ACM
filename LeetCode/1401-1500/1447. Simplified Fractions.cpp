class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int denominator = 2; denominator <= n; ++denominator) {
            for (int numerator = 1; numerator < denominator; ++numerator) {
                if (gcd(numerator, denominator) == 1) {
                    res.push_back(to_string(numerator) + "/" + to_string(denominator));
                }
            }
        }
        return res;
    }
    
    int gcd(int a, int b) {
        if (a == 0) { return b; }
        return gcd(b % a, a);
    }
};
