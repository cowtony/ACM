int bitCount(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1; 
    }
    return res;
}

void setBit(int& num, int k) {
    num |= 1UL << k;
}

void clearBit(int& num, int k) {
    num &= ~(1UL << k);
}

void toggleBit(int& num, int k) {
    num ^= 1UL << k;
}

std::bitset<10> x;

long long countIthBitsUnder(long long num, int i) {
    // Example: the third bit, 100 -> 4
    // return num / 8 * 4 + max(0, num % 8 - 4)
    return (num >> i + 1 << i) + max(0LL, (num & (1LL << i + 1) - 1) - (1LL << i));
}
