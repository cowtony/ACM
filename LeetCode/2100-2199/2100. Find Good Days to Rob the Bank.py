class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        good = [True] * len(security)

        for i in range(0, len(security)):
            count = count + 1 if i > 0 and security[i] <= security[i - 1] else 1
            if count < time + 1:
                good[i] = False
        
        for i in range(len(security) - 1, -1, -1):
            count = count + 1 if i < len(security) - 1 and security[i] <= security[i + 1] else 1
            if count < time + 1:
                good[i] = False

        return [i for i in range(len(security)) if good[i]]

        
