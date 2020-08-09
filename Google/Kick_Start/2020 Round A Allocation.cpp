#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int helper(vector<int>& A, int B) {
    sort(A.begin(), A.end());
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        if (sum > B) {
            return i;
        }
    }
    return A.size();
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        int N, B;
        cin >> N >> B;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        printf("Case #%d: %d\n", testcase, helper(A, B));
    }
}
