class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.length();
        vector<int> indegree(N, 0);
        vector<vector<int>> graph(N);
        for (const auto& edge : edges) {
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> dp(N, vector<int>(26, 0));
        for (int i = 0; i < N; ++i) {
            dp[i][colors[i] - 'a'] = 1;
        }

        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0, result = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int next : graph[node]) {
                dp[node][colors[next] - 'a']++;
                for (int i = 0; i < 26; ++i) {
                    dp[next][i] = max(dp[next][i], dp[node][i]);
                    result = max(result, dp[next][i]);
                }
                dp[node][colors[next] - 'a']--;
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return count == N? result : -1;
    }
};
