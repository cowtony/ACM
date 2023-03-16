class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        prefix_sum = list(accumulate(sorted(nums)))
        return [bisect_right(prefix_sum, q) for q in queries]
