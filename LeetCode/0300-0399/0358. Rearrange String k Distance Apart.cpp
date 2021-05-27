class Solution {
public:
    string rearrangeString(string s, int k) {    
        if (k == 0) {
            return s;
        }
        vector<pair<int, char>> count(26);
        for (int i = 0; i < 26; i++) {
            count[i] = make_pair(0, i + 'a');
        }
        for (char c : s) {
            count[c - 'a'].first++;
        }
        sort(count.begin(), count.end(), [](auto a, auto b){ return a.first > b.first; });
        
        // Not possible case.
        int number_of_max_count = 1;
        for (int i = 1; i < 26 and count[i].first == count[i - 1].first; i++) {
            number_of_max_count++;
        }
        if ((count[0].first - 1) * k + number_of_max_count > s.length()) {
            return "";
        }
        
        string res(s.length(), ' ');
        
        // Example: len(s) = 10, k = 4. The filling order will be:
        // 0 1 2 3/4 5 6 7/8 9
        // 4 1 9 7 5 2 T 8 6 3
        int start = (s.length() - 1) % k;
        int i = start;
        for (auto p : count) {
            for (int c = 0; c < p.first; c++) {
                res[i] = p.second;
                i += k;
                if (i >= s.length()) {
                    i = start = (start - 1 + k) % k;
                }
            }
        }
        return res;
    }
};
