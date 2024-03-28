class Solution:
    def rob(self, nums: List[int]) -> int:
        skip, rob = 0, 0

        for num in nums:
            skip, rob = max(skip, rob), skip + num 

        return max(skip, rob)
        
