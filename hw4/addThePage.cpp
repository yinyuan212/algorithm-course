#include <iostream>
#include <vector>

using namespace std;

void addThePage(int& sum) {
    int total = 0;
    int i = 1;
    while (total < sum) {
        total += i;
        i++;
    }

    int diff = total - sum;

    // 最後一頁被抽走
    if (diff == 0) {
        cout << i << " " << i << endl;
    } else {
        cout << i - 1 << " " << diff << endl;
    }

}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int sum;
        cin >> sum;

        addThePage(sum);
    }

    return 0;
}
