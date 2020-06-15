// Greatest Common Divisor
int gcd(int a, int b) {
    if (a == 0) { return b; }
    return gcd(b % a, a);
}

// Check if it's prime number
bool isPrime(int n) {
    if (n < 2) { return false; }
    if (n % 2 == 0) { return n == 2; }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Combinition
long combinition(int from, int pick) {
    pick = min(pick, from - pick);
    long res = 1;
    for (int i = 1, j = from; i <= pick; i++, j--) {
        res *= j;
        res /= i;
    }
    return res;
}
