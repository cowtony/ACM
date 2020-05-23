class Solution {
public:
    /**
     * @param str: The first string given
     * @param sub: The given second string
     * @return: Returns the deleted string
     */
    string CharacterDeletion(string &str, string &sub) {
        unordered_set<char> subs;
        for (char c : sub) {
            subs.insert(c);
        }
        for (char c : subs) {
            str = remove(str, c);
        }
        return str;
    }
    
    string remove(string str, char c) {
        size_t pos = 0;
        while (pos < str.length()) {
            pos = str.find(c, pos);
            if (pos == string::npos) {
                break;
            }
            str.erase(pos, 1);
        }
        return str;
    }
};
