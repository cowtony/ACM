using LL = long long;

int add(LL x, LL y, int mod) {
    return (x % mod + y % mod) % mod;
}

int minus(LL x, LL y, int mod) {
    return (x % mod - y % mod + mod) % mod;
}

int multiply(LL x, LL y, int mod) {
    return ((x % mod) * (y % mod)) % mod;
}

// Calculate `(x ^ y) % mod` by converting the y into binary bits.
int pow(LL x, LL y, int mod) {
    if (y <= 0) {
        return 1;
    }
    x %= mod;
    LL result = 1;
    while (y) {
        if (y & 1) {
            result = multiply(result, x, mod);
        }
        x = multiply(x, x, mod);
        y >>= 1;
    }
    return result;
}

// What is this?
int inverse(LL x, int mod) {
    return pow(x, mod - 2, mod);
}
