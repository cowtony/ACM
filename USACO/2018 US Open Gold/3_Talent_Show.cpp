#include <bits/stdc++.h>
using namespace std;

bool knapsack(const vector<pair<int, int>>& cows, const int W, const int64_t ratio) {
    vector<int64_t> dp(W + 1, INT_MIN); // The maximum `1000 * t - r * w` for sum weight w, or W when w >= W.
	dp[0] = 0;
	for (const auto& [weight, talent] : cows) {
		int64_t adjusted = 1000 * talent - ratio * weight;
		for (int w = W; w >= 0; --w) {
			if (dp[w] != INT_MIN) {
                dp[min(W, w + weight)] = max(dp[min(W, w + weight)], dp[w] + adjusted);
			}
		}
	}
	return dp[W] >= 0;
}

int main() {
	ifstream fin("talent.in");
    ofstream fout("talent.out");
    int N, W;
	fin >> N >> W;
	vector<pair<int, int>> cows(N); // <weight, talent>
	for (int i = 0; i < N; ++i) {
	    fin >> cows[i].first >> cows[i].second;
	}

	int low = 0, high = 1000 * 1000;
	while (low < high) {
        int mid = high - (high - low) / 2;
		if (knapsack(cows, W, mid)) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	fout << low;
	cout << low;
}
