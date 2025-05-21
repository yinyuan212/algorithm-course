#include <iostream>
#include <cmath>
using namespace std;

// 回傳某個數的除數個數
int count_divisors(int n) {
    int count = 0;
    int sqrt_n = static_cast<int>(sqrt(n));
    for (int i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            count += 2; // i 與 n/i
            if (i == n / i) count--; // 若 i 是平方根，避免重複算
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int L, U;
        cin >> L >> U;

        int max_div = 0;
        int number_with_max_div = L;

        for (int i = L; i <= U; ++i) {
            int divs = count_divisors(i);
            if (divs > max_div || (divs == max_div && i < number_with_max_div)) {
                max_div = divs;
                number_with_max_div = i;
            }
        }

        cout << "Between " << L << " and " << U << ", " << number_with_max_div
             << " has a maximum of " << max_div << " divisors." << endl;
    }

    return 0;
}
