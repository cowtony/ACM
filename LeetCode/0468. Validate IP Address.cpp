class Solution {
public:
    string validIPAddress(string IP) {
        vector<string> splits = split(IP, ".");
        if (splits.size() == 4) {
            for (string s : splits) {
                if (!validIPv4Number(s)) {
                    return "Neither";
                }
            }
            return "IPv4";
        }
        splits = split(IP, ":");
        if (splits.size() == 8) {
            for (string s : splits) {
                if (!validIPv6Number(s)) {
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
    
    vector<string> split(string s, string delimiter) {
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
    
    bool validIPv4Number(string s) {
        if (s.empty()) {
            return false;
        }
        if (s.length() > 1 and s.front() == '0') {
            return false;
        }
        if (s.length() > 3) {
            return false;
        }
        for (char c : s) {
            if (c < '0' or c > '9') {
                return false;
            }
        }
        return stoi(s) < 256;
    }
    
    bool validIPv6Number(string s) {
        if (s.empty()) {
            return false;
        }
        if (s.length() > 4) {
            return false;
        }
        for (char c : s) {
            if (c >= '0' and c <= '9' or c >= 'a' and c <= 'f' or c >= 'A' and c <= 'F') {
                
            } else {
                return false;
            }
        }
        return true;
    }
};
