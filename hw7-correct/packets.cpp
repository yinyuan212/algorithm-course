#include <iostream>
using namespace std;

int main() {
    int a[6]; // a[0]=1x1, a[1]=2x2, ..., a[5]=6x6

    while (true) {
        for (int i = 0; i < 6; ++i) cin >> a[i];
        if (a[0] + a[1] + a[2] + a[3] + a[4] + a[5] == 0) break;

        int box = 0;

        // 6x6
        box += a[5];

        // 5x5
        box += a[4];
        a[0] -= a[4] * 11;

        // 4x4
        box += a[3];
        if (a[1] >= a[3] * 5) a[1] -= a[3] * 5;
        else {
            int left = a[3] * 5 - a[1];
            a[0] -= left * 4;
            a[1] = 0;
        }

        // 3x3
        box += (a[2] + 3) / 4;
        int r = a[2] % 4;
        if (r) {
            int rem2[4] = {0, 5, 3, 1}; // 每種餘數下可塞幾個2x2
            int rem1[4] = {0, 7, 6, 5}; // 剩下塞1x1的數量
            if (a[1] >= rem2[r]) a[1] -= rem2[r];
            else {
                a[0] -= (rem2[r] - a[1]) * 4;
                a[1] = 0;
            }
            a[0] -= rem1[r];
        }

        // 2x2
        box += (a[1] + 8) / 9;
        a[0] -= (9 - a[1] % 9) * 4 * (a[1] % 9 != 0);

        // 1x1
        if (a[0] > 0) box += (a[0] + 35) / 36;

        cout << box << endl;
    }

    return 0;
}
