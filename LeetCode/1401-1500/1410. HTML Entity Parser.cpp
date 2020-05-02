class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> m = {{"&quot;", '\"'}, 
                                         {"&apos;", '''},
                                         {"&amp;", '&'},
                                         {"&gt;", '>'},
                                         {"&lt;", '<'},
                                         {"&frasl;", '/'},
                                        };
        string ret;
        for (size_t i = 0; i < text.length(); i++) {
            if (text[i] == '&') {
                size_t pos = text.find(";", i);
                if (pos != string::npos) {
                    string sub = text.substr(i, pos - i + 1);
                    if (m.find(sub) != m.end()) {
                        ret.push_back(m.at(sub));
                        i = pos;
                        continue;
                    }
                }
            }
            ret.push_back(text[i]);
        }
        
        return ret;
    }
};
