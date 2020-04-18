class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums.begin(), nums.end());
        return nums;
    }
    
private:
    template<class Iterator>
    void inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end) {
        std::vector<typename Iterator::value_type> temp;
        temp.reserve(std::distance(begin, end));
        Iterator l = begin;
        Iterator r = mid;
        while (l != mid and r != end) {
            if (*r < *l) { temp.emplace_back(*r++); }
            else { temp.emplace_back(*l++); }
        }
        temp.insert(temp.end(), l, mid);
        temp.insert(temp.end(), r, end);
        std::move(temp.begin(), temp.end(), begin);
    }
    
    template<class Iterator>
    void mergeSort(const Iterator& begin, const Iterator& end) {
        int size = std::distance(begin, end);   
        if (size <= 1) { return; }
        Iterator mid = std::next(begin, size / 2);
        mergeSort(begin, mid); // sort left half
        mergeSort(mid, end); // sort right half
        inplace_merge(begin, mid, end); // merge left and right.
    }
};
