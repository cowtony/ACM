class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for (int f = 1; f * f <= n; f++) {
            if (n % f == 0) {
                k--;
                factors.push_back(f);
            }
            if (k == 0) {
                return f;
            }
        }
        
        if (factors.back() * factors.back() == n) {
            k++;
        }
        if (k <= factors.size()) {
            return n / factors[factors.size() - k];
        }
        return -1;
    }
};
