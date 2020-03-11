class Solution {
public:
    int number;
    vector<string> result;
    
    void DFS(string s, int stack)
    {
        if (s.length() == number * 2)
        {
            if (stack == 0)
                result.push_back(s);
            return;
        }
        if (stack < number)
            DFS(s + '(', stack + 1);
        if (stack > 0)
            DFS(s + ')', stack - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        number = n;
        
        DFS("", 0);
        
        return result;
    }
};
