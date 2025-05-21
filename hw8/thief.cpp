#include <iostream>
#include <vector>
using namespace std;

bool found;
vector<int> result;

void dfs(vector<int>& items, int idx, int target, vector<int>& path) {
    if (found) return;
    if (target == 0) {
        result = path;
        found = true;
        return;
    }
    if (idx == items.size() || target < 0) return;

    // 選擇這個物品
    path.push_back(items[idx]);
    dfs(items, idx + 1, target - items[idx], path);
    path.pop_back();

    // 不選擇這個物品
    dfs(items, idx + 1, target, path);
}

int main() {
    int K;
    cin >> K;

    while (K--) {
        int T, N;
        cin >> T >> N;
        vector<int> items(N);

        for (int i = 0; i < N; ++i) {
            cin >> items[i];
        }

        found = false;
        result.clear();
        vector<int> path;
        dfs(items, 0, T, path);

        if (found) {
            for (int i = 0; i < result.size(); ++i) {
                cout << result[i];
                if (i != result.size() - 1) cout << " ";
            }
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}
