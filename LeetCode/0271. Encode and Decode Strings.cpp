class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (string s : strs) {
            res += to_string(hash(s)) + "," + s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        size_t pos = 0;
        
        stringstream ss(s);
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
    
    string check(unsigned int target_hash, stringstream& ss) {
        string res;
        unsigned int hash = 5381;
        char c;
        while (hash != target_hash and ss.get(c)) {
            hash = hash * 33 + c;
            res += c;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
