class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int previous = 0;
        for (int num : target) {
            for (int i = 1; i < num - previous; i++) {
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
            previous = num;
        }
        return res;
    }
};
