class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vector<int>& item1, const vector<int>& item2) {
            return item1[0] > item2[0];
        });

        unordered_set<int> categories;
        long long profit = 0;
        stack<int> st;
        for (int i = 0; i < k ; i++) {
            profit += items[i][0];
            if (categories.count(items[i][1]) > 0) {
                st.push(items[i][0]);
            }
            categories.insert(items[i][1]);
        }
        
        long long result = profit + categories.size() * categories.size();
        for (int i = k; i < items.size(); i++) {
            if (categories.count(items[i][1]) == 0 && !st.empty()) {
                profit += items[i][0];

                profit -= st.top();
                st.pop();
                categories.insert(items[i][1]);
                result = max(result, (long long)(profit + categories.size() * categories.size()));
            }
        }
        return result;
    }
};
