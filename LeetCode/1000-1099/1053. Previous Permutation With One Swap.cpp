class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int current_max = arr.back(), max_idx = arr.size() - 1;
        for (int i = arr.size() - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1]) {
                continue;
            }
            int value = INT_MIN, idx;
            for (int j = i + 1; j < arr.size() && arr[j] < arr[i]; ++j) {
                if (arr[j] > value) {
                    value = arr[j];
                    idx = j;
                }
            }
            swap(arr[i], arr[idx]);
            break;
        }
        return arr;
    }
};
