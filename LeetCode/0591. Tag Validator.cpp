class Solution {
public:
    bool isValid(string code) {
        stack<string> tags;
        while (!code.empty()) {
            if (code.find("<![CDATA[") == 0) { // CDATA
                if (tags.empty()) {
                    return false;
                }
                // cout << code.substr(0, code.find("]]>") + 3) << endl;
                if (code.find("]]>") == string::npos) {
                    return false;
                }
                code = code.substr(code.find("]]>") + 3);
            } else if (code.find("</") == 0) { // end tag
                if (code.find('>') == string::npos) {
                    return false;
                }
                string tag = code.substr(2, code.find('>') - 2);
                code = code.substr(code.find('>') + 1);
                if (!validTag(tag)) {
                    return false;
                }
                if (tags.empty() or tags.top() != tag) {
                    return false;
                }
                tags.pop();
                if (tags.empty() and !code.empty()) {
                    return false;
                }
            } else if (code.find("<") == 0) {  // start tag
                if (code.find('>') == string::npos) {
                    return false;
                }
                string tag = code.substr(1, code.find('>') - 1);
                code = code.substr(code.find('>') + 1);
                if (!validTag(tag)) {
                    return false;
                }
                tags.push(tag);
                // cout << tag << endl;
            } else {  // other char
                if (tags.empty()) {
                    return false;
                }
                // cout << code[0];
                code = code.substr(1);
            }
        }
        return tags.empty();
    }
    
private:
    bool validTag(string tag) {
        if (tag.length() > 9 or tag.empty()) {
            return false;
        }
        for (char c : tag) {
            if (c < 'A' or c > 'Z') {
                return false;
            }
        }
        return true;
    }
};
