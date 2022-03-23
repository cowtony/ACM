int64_t Combination(int total, int pick) {
  int64_t result = 1;
  for (int i = total, j = 1; j <= pick; --i, ++j) {
    result *= i;
    result /= j;
  }
  return result;
}
