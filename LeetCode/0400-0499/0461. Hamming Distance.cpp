class Solution {
public:
    int hammingDistance(int x, int y) {
        return bitCount(x ^ y);
    }
    
    int bitCount(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1; 
        }
        return res;
    }
};
