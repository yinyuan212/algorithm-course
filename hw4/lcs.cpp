#include <iostream>
#include <vector>

using namespace std;

int lcs(string& s1, string& s2){
    int m = s1.size();
    int n = s2.size();

    // dp[i][j]  表示 s1 前 i 個字元 和 s2 前 j 個字元 的 LCS 長度
    // dp[0][*] 表示 s1 是空字串。
    // dp[*][0] 表示 s2 是空字串。
    // 好處：邊界情況變簡單，用畫格子的方法想像，邊界都是 0。

    vector<vector<int>> dp(m+1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        string s1, s2;
        cin >> s1; 
        cin >> s2;

        cout << lcs(s1, s2) << endl;
    }

    return 0;
}
