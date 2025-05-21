#include <iostream>
using namespace std;

int main() {
    int a[6]; // 分別儲存 1x1 ~ 6x6 數量

    while (true) {
        for (int i = 0; i < 6; ++i) cin >> a[i];
        if (a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0 && a[5]==0) break;

        int box = 0;

        // 6x6
        box += a[5];

        // 5x5
        box += a[4];
        a[0] -= a[4] * 11;
        if (a[0] < 0) a[0] = 0;

        // 4x4
        box += a[3];
        int need2x2 = a[3] * 5;
        if (a[1] >= need2x2) {
            a[1] -= need2x2;
        } else {
            int left = need2x2 - a[1];
            a[0] -= left * 4;
            a[1] = 0;
        }
        if (a[0] < 0) a[0] = 0;

        // 3x3
        box += a[2] / 4;
        int rem = a[2] % 4;
        if (rem) {
            box += 1;
            int space2x2[4] = {0, 5, 3, 1}; // 剩餘可放 2x2 個數
            int space1x1[4] = {0, 7, 6, 5}; // 剩餘可放 1x1 個數

            if (a[1] >= space2x2[rem]) {
                a[1] -= space2x2[rem];
            } else {
                int lack = space2x2[rem] - a[1];
                a[0] -= lack * 4;
                a[1] = 0;
            }

            a[0] -= space1x1[rem];
            if (a[0] < 0) a[0] = 0;
        }

        // 2x2
        if (a[1]) {
            box += a[1] / 9;
            if (a[1] % 9 != 0) box += 1;

            int rem = a[1] % 9;
            if (rem != 0) {
                int space = 36 - rem * 4;
                a[0] -= space;
                if (a[0] < 0) a[0] = 0;
            }
        }

        // 1x1
        if (a[0]) {
            box += a[0] / 36;
            if (a[0] % 36 != 0) box += 1;
        }

        cout << box << endl;
    }

    return 0;
}
