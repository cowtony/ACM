class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> str_count;
        for (const string& str : arr) {
            str_count[str]++;
        }

        for (const string& str : arr) {
            if (str_count[str] == 1) {
                k--;
                if (k == 0) {
                    return str;
                }
            }
        }
        return "";
    }
};
