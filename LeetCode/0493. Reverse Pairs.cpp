class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums.begin(), nums.end());
    }
    
    template<class Iterator>
    long inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end) {
        std::vector<typename Iterator::value_type> temp;
        temp.reserve(std::distance(begin, end));
        Iterator l = begin;
        Iterator r = mid;

        while (l != mid and r != end) {
            if (*r <= *l) { temp.emplace_back(*r++); }
            else { temp.emplace_back(*l++); }
        }
        temp.insert(temp.end(), l, mid);
        temp.insert(temp.end(), r, end);
        
        long ret = 0;
        l = begin;
        r = mid;
        while (l != mid and r != end) {
            while (l != mid and *l <= *r * 2L) {
                l++;
            }
            ret += std::distance(l, mid);
            r++;
        }
        
        std::move(temp.begin(), temp.end(), begin);
        return ret;
    }
    
    template<class Iterator>
    long mergeSort(const Iterator& begin, const Iterator& end) {
        int size = std::distance(begin, end);   
        if (size <= 1) { return 0; }
        Iterator mid = std::next(begin, size / 2);
        long ret = 0;
        ret += mergeSort(begin, mid); // sort left half
        ret += mergeSort(mid, end); // sort right half
        ret += inplace_merge(begin, mid, end); // merge left and right.
        return ret;
    }
};
