class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for (char c : num) {
            while (!res.empty() and res.back() > c and k > 0) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        // In case k == num.length()
        while (k-- > 0) {
            res.pop_back();
        }
        // Remove the leading '0'.
        while (!res.empty() and res.front() == '0') {
            res.erase(0, 1);
        }
        return res.empty()? "0" : res;
    }
};
