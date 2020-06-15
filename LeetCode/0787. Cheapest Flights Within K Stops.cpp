class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n); // Next node and cost.
        for (auto edge : flights) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        typedef tuple<int, int, int> Node; // distance, vertex, edges.
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.emplace(0, src, 0);
        while (!pq.empty()) {
            auto [distance, vertex, stops] = pq.top();
            pq.pop();
            
            if(vertex == dst) {
                return distance;
            }
            if(stops > K) {
                continue;
            }
            for(auto edge : graph[vertex]) {
                auto [next, weight] = edge;
                pq.emplace(distance + weight, next, stops + 1);
            }
        }
        
        return -1;
    }
};
