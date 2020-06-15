class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string res;
        for (string s : strs) {
            res += to_string(hash(s)) + "," + s;
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> res;
        size_t pos = 0;
        
        stringstream ss(str);
        while (ss) {
            unsigned int hash_value;
            char comma = 0;
            ss >> hash_value >> comma;
            if (comma != ',') {
                break;
            }
            res.push_back(check(hash_value, ss));
        }
        return res;
    }
    
private:
    unsigned int hash(const string& str) {
        unsigned int hash = 5381;
        for (char c : str) {
            hash = hash * 33 + c;
        }
        return hash;
    }
    
    string check(int target_hash, stringstream& ss) {
        string res;
        unsigned int hash = 5381;
        while (ss) {
            char c;
            ss >> c;
            hash = hash * 33 + c;
            res += c;
            if (hash == target_hash) {
                return res;
            }
        }
    }
};
