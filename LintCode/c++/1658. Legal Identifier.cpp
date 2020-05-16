class Solution {
public:
    /**
     * @param str: The identifier need to be judged.
     * @return: Return if str is a legal identifier.
     */
    bool isLegalIdentifier(string &str) {
        if (str.empty()) {
            return false;
        }
        if (str.front() >= '0' and str.front() <= '9') {
            return false;
        }
        for (char c : str) {
            if (!(c >= 'a' and c <= 'z' 
                or c >= 'A' and c <= 'Z' 
                or c >= '0' and c <= '9' 
                or c == '_')) {
                return false;
            }
        }
        return true;
    }
};
