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
