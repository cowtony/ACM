class Solution {
public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, "");
        return all_result;
    }
    
    vector<string> all_result;
    map<char, string> m ={{'2',"abc"}, 
                          {'3',"def"},
                          {'4',"ghi"},
                          {'5',"jkl"},
                          {'6',"mno"},
                          {'7',"pqrs"},
                          {'8',"tuv"},
                          {'9',"wxyz"}};
    
    void dfs(string digits, string s) {
        if (digits.empty()) {
            if (!s.empty()) {
                all_result.emplace_back(s);
            }
            return;
        }
        for (char c : m[digits.front()]) {
            dfs(digits.substr(1), s + c);
        }
    }
};
