namespace mniu {
template<class Iterator, class Compare>
Iterator partition(Iterator begin, Iterator end, const Compare& compare) {
    if (begin == end--) { return begin; }
    auto pivot = *begin;
    while (begin != end) {
        while (begin != end and !compare(*end, pivot)) { --end; }
        *begin = *end;
        while (begin != end and compare(*begin, pivot)) { ++begin; }
        *end = *begin;
    }
    *begin = pivot;
    return begin;
}

template<class Iterator, class Compare>
void nth_element(Iterator begin, Iterator nth, Iterator end, const Compare& compare) {
    while (begin != end) {
        Iterator p = mniu::partition(begin, end, compare);
        if (distance(begin, p) < distance(begin, nth)) {
            begin = p + 1;
        } else {
            end = p;
        }
    }
}
} // namespace mniu

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum_a = 0;
        vector<int> opportunity_cost(costs.size());
        for (int i = 0; i < costs.size(); i++) {
            sum_a += costs[i][0];
            opportunity_cost[i] = costs[i][1] - costs[i][0];
        }
        
        mniu::nth_element(opportunity_cost.begin(), 
                          opportunity_cost.begin() + costs.size() / 2, 
                          opportunity_cost.end(),
                          [](const auto& a, const auto& b){return a < b;});
        
        for (int i = 0; i < costs.size() / 2; i++) {
            sum_a += opportunity_cost[i];
        }
        
        return sum_a;
    }
};
