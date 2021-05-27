class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> res(rains.size(), -1);
        set<int> buffer; // Store index of days can drain a lake.
        unordered_map<int, int> full_lakes; // Lake_id, index
        
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] > 0) {
                if (full_lakes.find(rains[i]) != full_lakes.end()) {
                    auto it = buffer.lower_bound(full_lakes[rains[i]]);
                    if (it == buffer.end()) {
                        return {};
                    }
                    res[*it] = rains[i];
                    buffer.erase(it);
                }
                full_lakes[rains[i]] = i;
            } else { // == 0
                buffer.insert(i);
                res[i] = 1;
            }
        }
        
        return res;
    }
};
