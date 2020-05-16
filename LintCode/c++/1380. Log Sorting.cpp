class Solution {
public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        for (int i = 0; i < logs.size(); i++) {
            for (int j = i + 1; j < logs.size(); j++) {
                if (lessThan(logs[j], logs[i])) {
                    logs.insert(logs.begin() + i, logs[j]);
                    logs.erase(logs.begin() + j + 1);
                }
            }
        }
        return logs;
    }
    
    static bool lessThan(string s1, string s2) {
        string id1 = s1.substr(0, s1.find(' '));
        string id2 = s2.substr(0, s2.find(' '));
        string content1 = s1.substr(s1.find(' ') + 1);
        string content2 = s2.substr(s2.find(' ') + 1);
        
        bool is_num1;
        for (char c : content1) {
            if (c != ' ') {
                is_num1 = c >= '0' and c <= '9';
                break;
            }
        }
        bool is_num2;
        for (char c : content2) {
            if (c != ' ') {
                is_num2 = c >= '0' and c <= '9';
                break;
            }
        }
        
        if (is_num1 and is_num2) {
            return false;
        } else if (is_num1 and !is_num2) {
            return false;
        } else if (!is_num1 and is_num2) {
            return true;
        } 
        // Both letter contents.
        else if (content1 == content2) {
            return id1 < id2;
        } else {
            return content1 < content2;
        }
    }
};
