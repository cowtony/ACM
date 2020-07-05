class Solution {
public:
    int evaluate(string expression, unordered_map<string, int> vars = {}) {
        auto parsed = parse(expression);
        
        // "add", "let", "mult"
        if (funcs.find(parsed[0]) != funcs.end()) { 
            return funcs.at(parsed[0])(this, parsed, vars);
        } 
        // It's a variable like "x"
        else if (vars.find(parsed[0]) != vars.end()) {  
            return vars.at(parsed[0]);
        } 
        // Number like "12".
        else {  
            return stoi(parsed[0]);
        }
    }
    
private:
    vector<string> parse(const string& s) {
        if (s[0] != '(') {
            return {s};
        }
        
        vector<string> res;
        string tmp;
        int parenthese = 0;
        for (int i = 1; i < s.length() - 1; i++) {
            tmp += s[i];
            switch (s[i]) {
                case ' ':
                    if (parenthese == 0) {
                        tmp.pop_back();
                        res.push_back(tmp);
                        tmp = "";
                    }
                    break;
                case '(':
                    parenthese++;
                    break;
                case ')':
                    parenthese--;
                    break;
            }
        }
        res.push_back(tmp);
        return res;
    }
    
    const unordered_map<string, function<int(Solution*, const vector<string>&, unordered_map<string, int>)>> funcs{{"add", &Solution::add}, {"let", &Solution::let}, {"mult", &Solution::mult}};
    
    int add(const vector<string>& input, unordered_map<string, int> variables) {
        return evaluate(input[1], variables) + evaluate(input[2], variables);
    }
    
    int let(const vector<string>& input, unordered_map<string, int> variables) {
        for (int var = 1; var < input.size() - 2; var += 2) {
            variables[input[var]] = evaluate(input[var + 1], variables);
        }
        return evaluate(input.back(), variables);
    }
    
    int mult(const vector<string>& input, unordered_map<string, int> variables) {
        return evaluate(input[1], variables) * evaluate(input[2], variables);
    }
};
