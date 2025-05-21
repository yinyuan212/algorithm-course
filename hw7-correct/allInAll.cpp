#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.size();
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
        if (isSubsequence(s, t)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
