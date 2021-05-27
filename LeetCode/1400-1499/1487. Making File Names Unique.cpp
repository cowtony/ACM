class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> count;
        vector<string> res;
        for (string name : names) {
            if (count.find(name) == count.end()) {
                count[name] = 1;
                res.push_back(name);
            } else {
                string new_name;
                while (count.find(new_name = name + "(" + to_string(count[name]) + ")") != count.end()) {
                    count[name]++;
                }
                res.push_back(new_name);
                count[new_name] = 1;
            }
        }
        return res;
    }
};
