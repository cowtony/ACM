class Solution {
public:
    int convert(int n)
    {
        int result = 0;
        while (n)
        {
            result += (n % 10) * (n % 10);
            n /= 10;
        }
        return result;
    }
    
    bool isHappy(int n) {
        int walker = n, runner = n;
        do
        {
            walker = convert(walker);
            runner = convert(runner);
            runner = convert(runner);
        }while (walker != runner);
        
        return walker == 1;
    }
};
