class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        arr2.push_back(-100000);
        arr2.push_back(100000);
        sort(arr2.begin(), arr2.end());
        
        int count = 0;
        int j = 0;
        for (int num : arr1) {
            int minimum = INT_MAX;
            
            while (arr2[j] < num) {
                j++;
            }
            if (min(arr2[j] - num, num - arr2[j - 1]) > d) {
                count++;
            }
        }
        return count;
    }
};
