class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> unused;
        for (int i = 1; i <= n; i++) {
            unused.push_back(i + '0');
        }
        int base = 1;
        for (int i = 1; i <= n; i++) {
            base *= i;
        }
        
        string ret;
        for (int i = n; i > 0; i--) {
            base /= i;
            ret += unused[(k - 1) / base];
            unused.erase(unused.begin() + (k - 1) / base);
            k -= ((k - 1) / base) * base;
        }
        return ret;
    }
};
