#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 結構儲存字串 + 未排序程度 + 輸入時順序
struct DNA {
    string str;
    int disorder;
    int index; // 用來保持原順序
};

// 計算一個字串的未排序程度
int countDisorder(const string& s) {
    int cnt = 0;
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            if (s[i] > s[j]) cnt++;
        }
    }
    return cnt;
}

// 排序用，先比 disorder，小的排前面，若相同，比index
bool compare(const DNA& a, const DNA& b) {
    if (a.disorder != b.disorder)
        return a.disorder < b.disorder;
    else
        return a.index < b.index;
}

int main() {
    int testCase;
    cin >> testCase;
    bool firstGroup = true;

    while (testCase--) {
        if (!firstGroup) {
            cout << endl; // 每組中間空一行
        }
        firstGroup = false;

        int n, m;
        cin >> n >> m;
        vector<DNA> data;

        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            DNA dna;
            dna.str = s;
            dna.disorder = countDisorder(s);
            dna.index = i;
            data.push_back(dna);
        }

        sort(data.begin(), data.end(), compare);

        for (const auto& d : data) {
            cout << d.str << endl;
        }
    }

    return 0;
}
