#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 高精度乘法: base^exp，回傳 string 型結果
string power(string base, int exp) {
    string res = "1";
    while (exp--) {
        string temp = "";
        int carry = 0;
        reverse(res.begin(), res.end());
        for (char c : res) {
            int prod = (c - '0') * stoi(base) + carry;
            temp += (prod % 10 + '0');
            carry = prod / 10;
        }
        while (carry) {
            temp += (carry % 10 + '0');
            carry /= 10;
        }
        reverse(temp.begin(), temp.end());
        res = temp;
    }
    return res;
}

// 高精度比較: a < b
bool less_or_equal(string a, string b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a <= b;
}

string int_to_string(int x) {
    return to_string(x);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string p;
        cin >> n >> p;

        int low = 1, high = 1000000000, ans = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            string mid_power = "1";
            string m = int_to_string(mid);
            for (int i = 0; i < n; ++i) {
                string temp = "";
                int carry = 0;
                reverse(mid_power.begin(), mid_power.end());
                for (char c : mid_power) {
                    int prod = (c - '0') * mid + carry;
                    temp += (prod % 10 + '0');
                    carry = prod / 10;
                }
                while (carry) {
                    temp += (carry % 10 + '0');
                    carry /= 10;
                }
                reverse(temp.begin(), temp.end());
                mid_power = temp;
            }

            if (less_or_equal(mid_power, p)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
