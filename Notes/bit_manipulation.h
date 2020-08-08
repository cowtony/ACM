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
