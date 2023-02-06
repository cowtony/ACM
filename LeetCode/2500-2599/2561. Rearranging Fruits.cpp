class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        long long min_value = min(basket1[0], basket2[0]);
        vector<long long> merged;
        auto it1 = basket1.begin(), it2 = basket2.begin();
        while (it1 != basket1.end() || it2 != basket2.end()) {
            if (it2 == basket2.end()) {
                merged.push_back(*it1);
                it1++;
            } else if (it1 == basket1.end()) {
                merged.push_back(*it2);
                it2++;
            } else if (*it1 < *it2) {
                merged.push_back(*it1);
                it1++;
            } else if (*it1 > *it2) {
                merged.push_back(*it2);
                it2++;
            } else {
                it1++;
                it2++;
            }
        }

        for (int i = 0; i < int(merged.size()); i += 2) {
            if (merged[i] != merged[i + 1]) {
                return -1;
            }
        }
        long long cost = 0;
        for (int i = 0; i < int(merged.size()) / 2; i += 2) {
            cost += min(2 * min_value, merged[i]);
        }
        return cost;
    }
};