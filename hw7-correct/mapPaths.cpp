#include <iostream>
using namespace std;

// 快速計算組合 C(n, k)
long long combination(int n, int k) {
    if (k > n - k) k = n - k;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - k + i) / i;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        cout << combination(m + n - 2, m - 1) << endl;
    }
    return 0;
}
