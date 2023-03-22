class Solution:
    def numDupDigitsAtMostN(self, n: int) -> int:
        str_n = str(n)
        distinct = 0
        used = set()
        for idx in range(len(str_n)):
            distinct += 9 * perm(9, idx)  # all distinct permutation with length `idx + 1`
            
            if len(used) == idx:
                for digit in range(int(str_n[idx]) + 1, 10):
                    if digit not in used:
                        distinct -= perm(10 - idx - 1, len(str_n) - idx - 1)  # Example: 8765, 9XXX, 88XX-89XX, 877X-879X, 8766-8769

            used.add(int(str_n[idx]))
            
        return n - distinct
