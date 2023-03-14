class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        dp = [0] * (len(arr) + 1)

        for i in range(len(arr)):
            maximum = 0
            for j in range(min(i + 1, k)):
                maximum = max(maximum, arr[i - j])
                dp[i + 1] = max(dp[i + 1], dp[i - j] + (j + 1) * maximum)

        return dp[-1]
