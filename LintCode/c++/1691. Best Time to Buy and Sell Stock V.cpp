class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the maximum profit
     */
    int getAns(vector<int> &a) {
        priority_queue<int, vector<int>, greater<int>> min_head;
        multiset<int> bought;
        int res = 0;
        for (int price : a) {
            if (!min_head.empty() and min_head.top() < price) {
                res -= min_head.top();
                if (bought.find(min_head.top()) != bought.end()) {
                    bought.erase(bought.find(min_head.top())); // Sold then bought.
                } else {
                    min_head.pop(); // Really bought.
                }
                res += price;
                bought.insert(price);
            }
            min_head.push(price);
        }
        return res;
    }
};
