class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        path += "/";
        while (!path.empty()) {
            string s = path.substr(0, path.find('/'));
            if (path.find('/') != string::npos) {
                path.erase(path.begin(), path.begin() + path.find('/') + 1);
            }
            if (s.empty()) {
                continue;
            } else if (s == ".") {
                continue;
            } else if (s == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else {
                paths.push_back(s);
            }
        }
        string ret;
        for (string s : paths) {
            ret += '/' + s;
        }
        if (ret.empty()) {
            return "/";
        }
        return ret;
    }
};
