class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> indexes(arr.size(), arr.size() - 1);
        indexes[arr.size() - 1] = arr.size() - 2;

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        for (int i = 0; i < arr.size(); i++) {
            pq.push({double(arr[i]) / arr[indexes[i]], i});
        }

        while (--k) {
            auto [_, i] = pq.top();
            pq.pop();

            indexes[i]--;
            if (indexes[i] == i) {
                indexes[i]--;
            }

            if (indexes[i] >= 0) {
                pq.push({double(arr[i]) / arr[indexes[i]], i});
            }
        }

        auto [_, i] = pq.top();
        return {arr[i], arr[indexes[i]]};
    }
};
