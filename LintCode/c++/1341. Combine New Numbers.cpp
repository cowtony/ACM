class Solution {
public:
    /**
     * @param a: the array in problem.
     * @return: represent the new number.
     */
    string Combine(vector<int> &a) {
        vector<string> mm;
        priority_queue<int, std::vector<int>, std::greater<int>> mod_1, mod_2;
        int sum = 0;
        for (int num : a) {
            sum += num;
            if (num % 3 == 1) {
                mod_1.push(num);
            } else if (num % 3 == 2) {
                mod_2.push(num);
            } else {
                mm.push_back(to_string(num));
            }
        }
        
        if (sum % 3 == 1) {
            if (mod_1.size() < 1) {
                mod_2.pop();
                mod_2.pop();
            } else if (mod_2.size() < 2) {
                mod_1.pop();
            } else {
                int a = mod_1.top();
                mod_1.pop();
                int b1 = mod_2.top();
                mod_2.pop();
                int b2 = mod_2.top();
                mod_2.pop();
                int b = stoi(max(to_string(b1) + to_string(b2), to_string(b2) + to_string(b1)));
                if (a > b) {
                    mm.push_back(to_string(a));
                } else {
                    mm.push_back(to_string(b1));
                    mm.push_back(to_string(b2));
                }
            }
        } else if (sum % 3 == 2) {
            if (mod_1.size() < 2) {
                mod_2.pop();
            } else if (mod_2.size() < 1) {
                mod_1.pop();
                mod_1.pop();
            } else {
                int a1 = mod_1.top();
                mod_1.pop();
                int a2 = mod_1.top();
                mod_1.pop();
                int b = mod_2.top();
                mod_2.pop();
                int a = stoi(max(to_string(a1) + to_string(a2), to_string(a2) + to_string(a1)));
                if (a >= b) {
                    mm.push_back(to_string(a1));
                    mm.push_back(to_string(a2));
                } else {
                    mm.push_back(to_string(b));
                }
            }
        }
        
        while (!mod_1.empty()) {
            mm.push_back(to_string(mod_1.top()));
            mod_1.pop();
        }
        while (!mod_2.empty()) {
            mm.push_back(to_string(mod_2.top()));
            mod_2.pop();
        }

        
        sort(mm.begin(), mm.end(), [](string a, string b){
            return a + b > b + a;
        });

        string res;
        for (string s : mm) {
            res += s;
        }
        return res;
    }
};
