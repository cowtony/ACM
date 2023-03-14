class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(set)
        for (a, b) in roads:
            graph[a].add(b)
            graph[b].add(a)

        result = 0
        for a in range(n):
            for b in range(a + 1, n):
                result = max(result, len(graph[a]) + len(graph[b]) - (b in graph[a]))
        
        return result
