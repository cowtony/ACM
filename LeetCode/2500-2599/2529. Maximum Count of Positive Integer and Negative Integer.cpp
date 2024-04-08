class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative = lowerBound(nums.begin(), nums.end(), 0) - nums.begin();
        int positive = nums.size() - (upperBound(nums.begin(), nums.end(), 0) - nums.begin());
        return max(negative, positive);
    }

    template<class Iterator>
    Iterator lowerBound(Iterator begin, Iterator end, typename Iterator::value_type target) {
        while (begin != end) {
            Iterator mid = std::next(begin, std::distance(begin, end) / 2);
            if (*mid < target) {
                begin = mid + 1;
            } else {  // *mid > target
                end = mid;
            }
        }
        return begin;
    }

    template<class Iterator>
    Iterator upperBound(Iterator begin, Iterator end, typename Iterator::value_type target) {
        while (begin != end) {
            Iterator mid = std::next(begin, std::distance(begin, end) / 2);
            if (*mid <= target) {
                begin = mid + 1;
            } else {  // *mid > target
                end = mid;
            }
        }
        return begin;
    }
};
