class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def helper(a: str, b: str) -> bool:
            i = 0
            j = len(a) - 1
            while i < j and a[i] == b[j]:
                i += 1
                j -= 1
            return  i >= j or a[i : j+1] == a[j : i-1 : -1] or b[i : j+1] == b[j : i-1 : -1]

        return helper(a, b) or helper(b, a)
