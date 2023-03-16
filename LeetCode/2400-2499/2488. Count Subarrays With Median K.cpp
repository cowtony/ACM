class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        idx_k = nums.index(k)

        count_bigger = defaultdict(int)
        count_bigger[0] = 1
        bigger = 0
        for i in range(idx_k + 1, len(nums)):
            bigger += 1 if nums[i] > k else -1
            count_bigger[bigger] += 1

        result = count_bigger[0] + count_bigger[1]
        smaller = 0
        for i in reversed(range(idx_k)):
            smaller += 1 if nums[i] < k else -1
            result += count_bigger[smaller] + count_bigger[smaller + 1]

        return result
