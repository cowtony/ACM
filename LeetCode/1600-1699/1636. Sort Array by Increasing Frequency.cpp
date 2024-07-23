class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }

        vector<pair<int, int>> pairs;
        for (const auto& [num, count] : counter) {
            pairs.emplace_back(count, num);
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<int> result;
        for (const auto& [count, num] : pairs) {
            for (int i = 0; i < count; i++) {
                result.push_back(num);
            }
        }

        return result;
    }
};
