#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectNumber(long long num) {
    if (num < 2) return false; // 小於 2 的數不可能是完美數

    long long sum = 1; // 1 是所有數的因數
    long long limit = sqrt(num); // 只需檢查到 sqrt(num)

    for (long long i = 2; i <= limit; i++) {
        if (num % i == 0) {
            sum += i; // 加入 i
            if (i != num / i) { // 避免平方數重複加
                sum += num / i;
            }
        }
    }

    return sum == num;
}

int main() {
    int n;
    cin >> n; // 讀取測試數量

    bool first = true; // 控制輸出格式
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num; // 讀取每個數字

        if (isPerfectNumber(num)) {
            if (!first) cout << " "; // 輸出前加空格
            cout << num;
            first = false;
        }
    }
    cout << endl; // 最後換行

    return 0;
}
