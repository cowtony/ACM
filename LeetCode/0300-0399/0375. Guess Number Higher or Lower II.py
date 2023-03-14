class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        for length in range(2, n + 1):
            for left in range(1, n + 1 - (length - 1)):
                dp[left][length] = \
                min(guess + max(dp[left][guess - left], \
                                dp[guess + 1][left + length - 1 - guess]) \
                    for guess in range(left, left + length - 1))

        return dp[1][n]
