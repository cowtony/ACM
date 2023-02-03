// Modulo
(a + b) % m = ((a % m) + (b % m)) % m  // Add
(a * b) % m = ((a % m) * (b % m)) % m  // Multiply
(a - b) % m = ((a % m) - (b % m) + m) % m  // Minus
(a / b) % m = ((a % m) * (inv(b) % m)) % m; inv(b) = b^(m-2)  // Divide

int quickPow(int a, int b, int mod) {
	if (b < 0) {
		return 0;
	}
	int result = 1;
	a %= mod;
	while (b > 0) {
		if (b & 1) {
			result = (result * a) % mod;
		}
		b >> 1;
		a = (a * a) % mod;
	}
	return result;
}

int inv(int x, int mod) {
	return quickPow(x, mod - 2);
}

int moduloDivide(int a, int b, int mod) {
	return ((a % mod) * (inv(b) % mod)) % mod;
}