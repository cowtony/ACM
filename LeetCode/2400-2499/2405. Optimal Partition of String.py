class Solution:
    def partitionString(self, s: str) -> int:
        letters = set()
        result = 1
        
        for c in s:
            if c in letters:
                result += 1
                letters.clear()
            letters.add(c)

        return result
