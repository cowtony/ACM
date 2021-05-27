class Solution {
public:
    int lengthLongestPath(string input) {
        input += "\n";
        stack<string> s;
        stack<int> len;
        int max_len = 1;

        while (!input.empty()) {
            string name = input.substr(0, input.find("\n"));
            input = input.substr(input.find("\n") + 1);
            
            int l = 0;
            while (name.find("\t") == 0) {
                l++;
                name = name.substr(1);
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
