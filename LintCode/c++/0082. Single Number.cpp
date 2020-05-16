class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int x = 0;
        for (int num : A)
            x ^= num;
        return x;
    }
};
