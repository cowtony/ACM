class Solution {
public:
    string minInteger(string num, int k) {
        if (k == 0 or num.empty()) {
            return num;
        }
        char pivot = num[0];
        vector<vector<int>> indexs(pivot - '0');
        for (int i = 1; i < num.size(); i++) {
            if (num[i] < pivot) {
                indexs[num[i] - '0'].push_back(i);
            }
        }
        
        string head;
        set<int> used;
        for (int d = 0; d < pivot - '0'; d++) {
            int count_pre = 0;
            auto it = used.begin();
            for (int idx : indexs[d]) {
                while (it != used.end() and *it < idx) {
                    it++;
                    count_pre++;
                }
                int move = idx - count_pre;
                if (move <= k) {
                    k -= move;
                    head += char('0' + d);
                    num[idx] = 'u'; // used
                    used.insert(idx);
                    count_pre++;
                }
            }
        }

        if (head.empty()) {
            return num[0] + minInteger(num.substr(1), k);
        }
        
        string remain;
        for (char c : num) {
            if (c != 'u') {
                remain += c;
            }
        }
        return head + minInteger(remain, k);
    }
};
