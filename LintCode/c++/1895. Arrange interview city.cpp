namespace mniu {
template<class Iterator>
Iterator partition(Iterator begin, Iterator end) {
    static auto compare = [](const typename Iterator::value_type& a, 
          const typename Iterator::value_type& b){
        return a < b;
    };
    if (begin == end) { return begin; }
    --end;
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

template<class Iterator>
void nth_element(Iterator begin, Iterator nth, Iterator end) {
    while (begin != end) {
        Iterator p = partition(begin, end);
        if (distance(begin, p) > distance(begin, nth)) {
            end = p;
        } else if (distance(begin, p) < distance(begin, nth)) {
            begin = p + 1;
        } else {
            return;
        }
    }
}
} // namespace mniu

class Solution {
public:
    /**
     * @param cost: The cost of each interviewer
     * @return: The total cost of all the interviewers.
     */
    int TotalCost(vector<vector<int>> &costs) {
        int sum_a = 0;
        vector<int> opportunity_cost(costs.size());
        for (int i = 0; i < costs.size(); i++) {
            sum_a += costs[i][0];
            opportunity_cost[i] = costs[i][1] - costs[i][0];
        }
        
        mniu::nth_element(opportunity_cost.begin(), 
                          opportunity_cost.begin() + costs.size() / 2, 
                          opportunity_cost.end());
        
        for (int i = 0; i < costs.size() / 2; i++) {
            sum_a += opportunity_cost[i];
        }
        
        return sum_a;
    }
};
