class Solution {
public:
    long long minEnd(int n, int x) {
        if (n == 1) {
            return x;
        }
        vector<int> n_bits = toBit(n - 1);
        vector<int> x_bits = toBit(x);

        int j = 0;
        for (int i = 0; i < x_bits.size(); i++) {
            if (x_bits[i] == 0 && j < n_bits.size()) {
                x_bits[i] = n_bits[j++];
            }
        }
        x_bits.insert(x_bits.end(), n_bits.begin() + j, n_bits.end());
        
        return toValue(x_bits);
    }
    
    vector<int> toBit(int n) {
        vector<int> bits;
        while (n) {
            bits.push_back(n % 2);
            n>>= 1;
        }
        return bits;
    }
    
    long long toValue(const vector<int>& bits) {
        long long result = 0;
        for (int i = bits.size() - 1; i >= 0; i--) {
            result <<= 1;
            result += bits[i];
        }
        return result;
    }
};
