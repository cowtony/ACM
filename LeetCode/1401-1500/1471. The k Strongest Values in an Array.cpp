class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        nth_element(arr.begin(), arr.begin() + (arr.size() - 1) / 2, arr.end());
        int m = arr[(arr.size() - 1) / 2];

        // cout << m << endl;
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [m](int a, int b) {
            if (abs(a - m) == abs(b - m)) {
                return a > b;
            } else {
                return abs(a - m) > abs(b - m);
            } 
        });
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        
        return res;
    }
};
