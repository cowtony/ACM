class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (char c: s)
        {
            switch (c)
            {
                case '(': sta.push('('); break;
                case '[': sta.push('['); break;
                case '{': sta.push('{'); break;
                case ')': 
                    if (!sta.empty() && sta.top() == '(')
                        sta.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (!sta.empty() && sta.top() == '[')
                        sta.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (!sta.empty() && sta.top() == '{')
                        sta.pop();
                    else
                        return false;
                    break;
            }
        }
        return sta.empty();
    }
};
