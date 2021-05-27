class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; i++)
        {
            result = say(result);
        }
        return result;
    }
    
    string say(string s)
    {
        string result = "";
        
        while (!s.empty())
        {
            char c = s[0];
            int count = 0;
            while (!s.empty() && c == s[0])
            {
                count++;
                s.erase(s.begin());
            }
        
            result += to_string(count) + c;
        }
        
        return result;
    }
};
