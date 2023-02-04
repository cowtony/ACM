class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> dict;
        dict[' '] = ' ';
        char letter = 'a';
        for (char c : key) {
            if (dict.find(c) == dict.end()) {
                dict[c] = letter++;
            }
        }

        for (char& c : message) {
            c = dict[c];
        }
        return message;
    }
};