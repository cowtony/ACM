// Combination
uint64_t C(int total, int pick) {
    if (total < 0 || pick < 0 || pick > total) {
        return 0;
    } else if (pick > total - pick) {
        return C(total, total - pick);
    }

    uint64_t result = 1;
    for (int i = total, j = 1; j <= pick; --i, ++j) {
        result *= i;
        result /= j;
    }
    return result;
}

// Greatest Common Divisor
int GCD(int a, int b) {
    if (a == 0) { return b; }
    return gcd(b % a, a);
}

// Least Common Multiple
int LCM(int a, int b) {
    return a * b / GCD(a, b);
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
