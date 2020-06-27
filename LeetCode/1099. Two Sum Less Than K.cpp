class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        vector<int> counting_sort(1001, 0);
        for (int a : A) {
            counting_sort[a]++;
        }
        
        int lo = 0, hi = 1000;
        int res = -1;
        while (lo < hi) {
            while (counting_sort[lo] == 0) {
                lo++;
            }
            counting_sort[lo]--;
            while (hi >= 0 and counting_sort[hi] == 0 or lo + hi >= K) {
                hi--;
            }
            if (lo >= hi) {
                break;
            }
            res = max(res, lo + hi);
        }
        
        return res;
    }
};
