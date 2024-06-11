class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> count;
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> result;
        for (int num : arr2) {
            while (count[num]--) {
                result.push_back(num);
            }
            count.erase(num);
        }
        for (const auto& [num, cnt] : count) {
            while (count[num]--) {
                result.push_back(num);
            }
        }
        return result;
    }
};
