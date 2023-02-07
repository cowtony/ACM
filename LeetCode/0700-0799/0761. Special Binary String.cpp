class Solution {
public:
    string makeLargestSpecial(string s) {
        int count_1 = 0;
        string special;
        vector<string> specials;
        for (char c : s) {
            if (c == '1') {
                count_1++;
            } else {  // c == '0'
                count_1--;
            }
            special += c;
            if (count_1 == 0) {  // found one special string
                specials.push_back('1' + makeLargestSpecial(special.substr(1, special.length() - 2)) + '0');
                special.clear();
            }
        }
        sort(specials.begin(), specials.end(), greater<string>());
        return join(specials, "");
    }

    string join(const vector<string>& words, const string& delimiter = " ") {
        if (words.empty()) {
            return "";
        }
        string res = words.at(0);
        for (int i = 1; i < words.size(); i++) {
            res += delimiter + words.at(i);
        }
        return res;
    }
};