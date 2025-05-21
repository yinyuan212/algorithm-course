
#include <iostream>
#include <vector>

using namespace std;

bool canMakeLength(int target, vector<int> bars, int index, int sum) {
    if (target == sum) return true;
    if (sum > target || index >= bars.size()) return false;

    return canMakeLength(target, bars, index + 1, sum + bars[index]) || canMakeLength(target, bars, index + 1, sum);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> bars(p);
        for (int i = 0; i < p; ++i) {
            cin >> bars[i];
        }

        if (canMakeLength(n, bars, 0, 0)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}