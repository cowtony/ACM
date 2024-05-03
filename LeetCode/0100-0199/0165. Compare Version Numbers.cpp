class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, ".");
        vector<string> v2 = split(version2, ".");
        
        for (int i = 0; i < v1.size() || i < v2.size(); i++) {
            int num1 = 0, num2 = 0;
            if (i < v1.size()) {
                num1 = stoi(v1[i]);
            }
            if (i < v2.size()) {
                num2 = stoi(v2[i]);
            }

            if (num1 < num2) {
                return -1;
            } else if (num1 > num2) {
                return 1;
            }
        }
        
        return 0;
    }

    vector<string> split(string s, string delimiter = " ") {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            res.emplace_back(s.substr(p, pos - p));
            p = pos + delimiter.length();
        }
        return res;
    }

};
