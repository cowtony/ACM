class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(dict)
        for start, end, dist in roads:
            graph[start][end] = graph[end][start] = dist
        
        dq = deque([1])
        visited = [False] * (n + 1)
        result = inf
        while dq:
            node = dq.popleft()
            for nxt, dist in graph[node].items():
                result = min(result, dist)
                if not visited[nxt]:
                    dq.append(nxt)
                    visited[nxt] = True

        return result
