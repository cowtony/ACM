class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        for i, bed in enumerate(flowerbed):
            if bed == 0 and \
              (i == 0 or flowerbed[i - 1] == 0) and \
              (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0):
                n -= 1
                flowerbed[i] = 1
        
        return n <= 0
