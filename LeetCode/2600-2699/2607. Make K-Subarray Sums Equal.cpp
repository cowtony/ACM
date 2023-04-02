class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        unordered_set<int> start;
        for (int i = 0; i < k; ++i) {
            start.insert(i);
        }
        long result = 0;
        while (!start.empty()) {
            int i = *start.begin();
            vector<long> temp;
            while (arr[i] > 0) {
                start.erase(i);
                temp.push_back(arr[i]);
                arr[i] = 0;
                i = (i + k) % arr.size();
            }

            sort(temp.begin(), temp.end());
            long final_num = temp[temp.size() / 2];
            for (int i = 0; i < temp.size(); i++) {
                result += abs(temp[i] - final_num);
            }
        }
        return result;
    }
};
