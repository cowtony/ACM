class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        multiset<int> multi_set(changed.begin(), changed.end());

        vector<int> result;
        result.reserve(changed.size() / 2);
        while (!multi_set.empty()) {
            int x = *multi_set.begin();
            result.push_back(x);
            multi_set.erase(multi_set.begin());

            if (multi_set.find(2 * x) == multi_set.end()) {
                return {};
            }
            multi_set.erase(multi_set.find(2 * x));
        }
        return result;
    }
};
