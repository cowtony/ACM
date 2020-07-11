class Solution {
public:
    /**
     * @param sourceString: a string
     * @param targetStrings: a string array
     * @return: Returns a bool array indicating whether each string in targetStrings is a substring of the sourceString
     */
    vector<bool> whetherStringsAreSubstrings(string &sourceString, vector<string> &targetStrings) {
        vector<bool> res;
        for (string s : targetStrings) {
            res.push_back(sourceString.find(s) != string::npos);
        }
        return res;
    }
};
