class Solution {
public:
    /**
     * @param ListA: The relation between ListB's books
     * @param ListB: The relation between ListA's books
     * @return: The answer
     */
    vector<string> maximumAssociationSet(vector<string> &ListA, vector<string> &ListB) {
        for (int i = 0; i < ListA.size(); i++) {
            add(ListA[i]);
            add(ListB[i]);
            connect(ListA[i], ListB[i]);
        }
        vector<string> ans;
        for (pair<string, string> p : father) {
            if (root(p.first) == max_head) {
                ans.emplace_back(p.first);
            }
        }
        return ans;
    }
private:
    unordered_map<string, string> father;
    unordered_map<string, int> count;
    int max_count = 0;
    string max_head;
    
    void add(string book) {
        if (father.find(book) == father.end()) {
            father[book] = book;
            count[book] = 1;
        }
    }
    void connect(string a, string b) {
        string ra = root(a);
        string rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count[rb] += count[ra];
            if (count[rb] > max_count) {
                max_count = count[rb];
                max_head = rb;
            }
        }
    }
    string root(string s) {
        if (father[s] == s) {
            return s;
        } else {
            return father[s] = root(father[s]);
        }
    }
};
