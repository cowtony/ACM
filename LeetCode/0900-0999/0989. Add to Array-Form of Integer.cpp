class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        for (int i = 0; k > 0; i++) {
            if (i == num.size()) {
                num.push_back(0);
            }
            num[i] += k % 10;
            k /= 10;
            if (num[i] > 9) {
                num[i] -= 10;
                k++;
            }
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
