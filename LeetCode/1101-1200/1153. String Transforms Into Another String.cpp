class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        
        unordered_map<char, char> um;
        for (int i = 0; i < str1.length(); i++) {
            if (um.find(str1[i]) == um.end()) {
                um[str1[i]] = str2[i];
            } else {
                if (um[str1[i]] != str2[i]) {
                    return false;
                }
            }
        }
        
        unordered_set<char> us;
        for (char c : str2) {
            us.insert(c);
        }
        return us.size() < 26;
    }
};
