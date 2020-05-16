class Solution {
public:
    /**
     * @param a: the n numbers
     * @param k: the number of integers you can choose
     * @return: how many ways that the sum of the k integers is a prime number
     */
    int getWays(vector<int> &a, int k) {
        dfs(a, k, 0, 0);
        return count;
    }
    
    int count = 0;
    void dfs(vector<int> &a, int left, int index, int sum) {
        if (left == 0) {
            if (isPrime(sum)) {
                count++;
            }
            return;
        }
        for (int i = index; i < a.size(); i++) {
            dfs(a, left - 1, i + 1, sum + a[i]);
        }
    }
    
    bool isPrime(int num) {
        if (num % 2 == 0) {
            return false;
        }
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};
