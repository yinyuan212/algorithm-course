#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

// 將每一邊解析為：x 的係數總和、常數項總和
pair<int, int> parse_expression(const string& expr) {
    int x_coef = 0;
    int constant = 0;
    string s;
    // 把 - 換成 +-，方便以 + 為分隔符
    for (size_t i = 0; i < expr.size(); ++i) {
        if (expr[i] == '-' && (i == 0 || expr[i - 1] != '+' && expr[i - 1] != '-'))
            s += "+-";
        else
            s += expr[i];
    }

    if (s[0] == '+') s = s.substr(1); // 移除開頭的 '+'

    stringstream ss(s);
    string term;
    while (getline(ss, term, '+')) {
        if (term.empty()) continue;
        size_t x_pos = term.find('x');
        if (x_pos != string::npos) {
            string coeff_str = term.substr(0, x_pos);
            if (coeff_str == "") coeff_str = "1";
            if (coeff_str == "-") coeff_str = "-1";
            x_coef += stoi(coeff_str);
        } else {
            constant += stoi(term);
        }
    }
    return {x_coef, constant};
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略換行

    while (n--) {
        string equation;
        getline(cin, equation);
        size_t eq_pos = equation.find('=');
        string left = equation.substr(0, eq_pos);
        string right = equation.substr(eq_pos + 1);

        auto [lx, lc] = parse_expression(left);
        auto [rx, rc] = parse_expression(right);

        int x_coef = lx - rx;
        int const_total = rc - lc;

        if (x_coef == 0) {
            if (const_total == 0)
                cout << "IDENTITY" << endl;
            else
                cout << "IMPOSSIBLE" << endl;
        } else {
            double result = static_cast<double>(const_total) / x_coef;
            cout << static_cast<int>(floor(result)) << endl;
        }
    }

    return 0;
}
