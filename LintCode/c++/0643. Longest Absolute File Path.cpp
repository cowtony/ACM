class Solution {
public:
    /**
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    int lengthLongestPath(string &input) {
        input += "\\n";
        stack<string> s;
        stack<int> len;
        int max_len = 1;

        while (!input.empty()) {
            string name = input.substr(0, input.find("\\n"));
            input = input.substr(input.find("\\n") + 2);
            
            int l = 0;
            while (name.find("\\t") == 0) {
                l++;
                name = name.substr(2);
            }

            while (s.size() > l) {
                s.pop();
                len.pop();
            }

            s.push(name);
            len.push((len.empty()? 0 : len.top()) + name.length() + 1);
            if (name.find('.') != string::npos) {
                max_len = max(max_len, len.top());
            }
            
        }
        return max_len - 1;
    }
};
