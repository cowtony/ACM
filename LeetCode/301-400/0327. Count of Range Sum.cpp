class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<int64_t, int> ms; // <sum, occurance>
        ms[0]++;
        
        int64_t sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            int64_t new_lower = sum - upper;
            int64_t new_upper = sum - lower;
            for (auto it = ms.lower_bound(new_lower); it != ms.end() and it->first <= new_upper; it++) {
                count += it->second;
            }
            ms[sum]++;
        }
        return count;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lower_ = lower, upper_ = upper;
        vector<long> prefix_sum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        return mergeSort(prefix_sum.begin(), prefix_sum.end(), [](long a, long b){ return a < b; });
    }
    
    int lower_, upper_;
    
    template<class Iterator, class Compare>
    int inplace_merge(const Iterator& begin, const Iterator& mid, const Iterator& end, const Compare& compare) {
        std::vector<typename Iterator::value_type> temp;
        temp.reserve(std::distance(begin, end));
        Iterator l = begin;
        Iterator r = mid;
        
        int count = 0;
        Iterator left = mid, right = mid; // Special code.
        
        for (Iterator l = begin; l != mid; l++) {
            while (r != end and compare(*r, *l)) { temp.emplace_back(*r++); }
            temp.emplace_back(*l); 
            
            // Special code start.
            while(left != end && *left - *l < lower_) { left++; }
            while(right != end && *right - *l <= upper_) { right++; }
            count += distance(left, right);
            // Special code end.
        }
        temp.insert(temp.end(), r, end);
        std::move(temp.begin(), temp.end(), begin);
        return count;
    }
    
    template<class Iterator, class Compare>
    int mergeSort(const Iterator& begin, const Iterator& end, const Compare& compare) {
        int size = std::distance(begin, end);   
        if (size <= 1) { return 0; }
        Iterator mid = std::next(begin, size / 2);
        return mergeSort(begin, mid, compare) // sort left half
             + mergeSort(mid, end, compare) // sort right half
             + inplace_merge(begin, mid, end, compare); // merge left and right. `std::implace_merge()`
    }
};
