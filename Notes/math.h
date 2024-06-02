// Combinition
int64_t C(int total, int pick) {
    if (pick > total) {
        return 0;
    } else if (pick > total - pick) {
        return C(total, total - pick);
    }

    int64_t result = 1;
    for (int i = total, j = 1; j <= pick; --i, ++j) {
        result *= i;
        result /= j;
    }
    return result;
}
