class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        def GCD(a: int, b: int) -> int:
            x, y = a, b
            while y:
                x, y = y, x % y
            return x
                
        def LCM(a: int, b: int) -> int:
            return a * b / GCD(a, b)

        lcm = LCM(a, b)
        low, high = 2, 10 ** 14
        while low < high:
            mid = (low + high) // 2
            if mid // a + mid // b - mid // lcm < n:
                low = mid + 1
            else:
                high = mid
        
        return low % (10 ** 9 + 7)
        
