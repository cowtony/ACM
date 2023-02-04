class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        uint64_t sum_package = 0;
        for (uint64_t package : packages) {
            sum_package += package;
        }

        uint64_t min_boxes = LONG_LONG_MAX;
        for (auto& supplier : boxes) {
            sort(supplier.begin(), supplier.end());
            uint64_t sum_boxes = 0;
            auto prev = packages.begin();
            for (uint64_t box : supplier) {
                auto it = UpperBound(prev, packages.end(), box);
                sum_boxes += distance(prev, it) * box;
                if (it == packages.end()) {  // All packed.
                    min_boxes = min(min_boxes, sum_boxes);
                    break;
                }
                prev = it;
            }
        }

        return min_boxes == LONG_LONG_MAX? -1 : (min_boxes - sum_package) % 1000000007LL;
    }

    template<class It>
    It UpperBound(It begin, It end, typename It::value_type value) {
        while (begin != end) {
            It mid = std::next(begin, std::distance(begin, end) / 2);
            if (*mid <= value) {
                begin = mid + 1;
            } else {  // *mid > value
                end = mid;
            }
        }
        return begin;
    }
};