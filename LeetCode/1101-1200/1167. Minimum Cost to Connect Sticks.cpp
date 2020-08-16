class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int stick : sticks) {
            pq.push(stick);
        }
        
        int cost = 0;
        while (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            cost += a + b;
        }
        return cost;
    }
};
