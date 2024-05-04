class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int shift = 0;
        if (k < 0) {
            shift = 1 - k;
            k = -k;
        }

        const int N = code.size();
        
        int val = 0;
        for (int i = 0; i < k; i++) {
            val += code[i];
        }
        
        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            val += code[(i + k + N) % N] - code[i];
            result[(i + shift) % N] = val;
        }
        return result;
    }
};
