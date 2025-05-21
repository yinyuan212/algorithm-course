#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        string field;
        cin >> field;

        int i = 0, scarecrows = 0;
        while (i < N) {
            if (field[i] == '#') {
                ++i; // 不毛之地，跳過
            } else {
                ++scarecrows; // 放稻草人
                i += 3;        // 保護這格 + 右兩格
            }
        }

        cout << "Case " << t << ": " << scarecrows << endl;
    }

    return 0;
}
