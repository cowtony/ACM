class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        visited = set()

        def dfs(s: str):
            if s in visited:
                return

            visited.add(s)
            dfs(s[-b:] + s[:-b])
            dfs("".join(str((int(c) + a) % 10) if i & 1 else c for i, c in enumerate(s)))

        dfs(s)
        return min(visited)
