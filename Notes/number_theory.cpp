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
