/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        qsort(nuts, bolts, compare, 0, nuts.size() - 1);
    }
    
    void qsort(vector<string> &nuts, vector<string> &bolts, Comparator compare, int begin_idx, int end_idx) {
        if (begin_idx < end_idx) {
           int mid =  partition(nuts, bolts, compare, begin_idx, end_idx);
           qsort(nuts, bolts, compare, begin_idx, mid - 1);
           qsort(nuts, bolts, compare, mid + 1, end_idx);
        }
    }
    
    int partition(vector<string> &nuts, vector<string> &bolts, Comparator compare, int begin_idx, int end_idx) {
        string pivot_nut = nuts[begin_idx];
        for (int i = begin_idx; i <= end_idx; i++) {
            if (compare.cmp(pivot_nut, bolts[i]) == 0) {
                swap(bolts[begin_idx], bolts[i]);
            }
        }
        string pivot_bolt = bolts[begin_idx];
        
        int lo = begin_idx, hi = end_idx;
        while(lo < hi)
        {
            while(lo < hi && compare.cmp(pivot_nut, bolts[hi]) == -1) {
                --hi;
            }
            bolts[lo] = bolts[hi];
            
            while(lo < hi && compare.cmp(pivot_nut, bolts[lo]) == 1) {
                ++lo;
            }
            bolts[hi] = bolts[lo];
        }
        bolts[lo] = pivot_bolt;
        
        lo = begin_idx, hi = end_idx;
        while(lo < hi)
        {
            while(lo < hi && compare.cmp(nuts[hi], pivot_bolt) == 1) {
                --hi;
            }
            nuts[lo] = nuts[hi];
            
            while(lo < hi && compare.cmp(nuts[lo], pivot_bolt) == -1) {
                ++lo;
            }
            nuts[hi] = nuts[lo];
        }
        nuts[lo] = pivot_nut;
        
        return lo;
    }
};
