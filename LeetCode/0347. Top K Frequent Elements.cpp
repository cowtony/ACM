class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        
        vector<pair<int, int>> data{m.begin(), m.end()};
        nth_element(data.begin(), data.begin() + k, data.end(), [](auto a, auto b) { 
            return a.second > b.second;
        });
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(data[i].first);
        }
        return res;
    }
    
    template<class Iterator, class Compare>
    Iterator quickSelect(Iterator begin, Iterator end, const Compare& compare) {
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
            Iterator p = quickSelect(begin, end, compare);
            if (distance(begin, p) < distance(begin, nth)) { begin = p + 1; }
            else { end = p; }
        }
    }
};
