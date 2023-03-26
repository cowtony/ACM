class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if (k <= numOnes) {
            return k;
        }
        k -= numOnes;
        if (k <= numZeros) {
            return numOnes;
        }
        k -= numZeros;
        return numOnes - k;
    }
};
