#include <iostream>
#include <string>
using namespace std;

// 將每組信用卡號以 Luhn Algorithm 驗證
bool isValidCardNumber(const string& cardNumber) {
    string digits = "";
    
    // 移除空白，組成連續16位數字
    for (char ch : cardNumber) {
        if (ch != ' ') digits += ch;
    }

    if (digits.length() != 16) return false;

    int sum = 0;
    // Luhn 演算法從右往左看，每偶數位(從右數起的第二、四、六...)乘2
    for (int i = 0; i < 16; ++i) {
        int num = digits[15 - i] - '0'; // 右邊第 i 位
        if (i % 2 == 1) { // 偶數位（右數第2、4...）
            num *= 2;
            if (num > 9) num -= 9; // 加總位數相當於：大於9就減9（因為最多是18）
        }
        sum += num;
    }

    // 合法條件是總和 mod 10 為 0
    return (sum % 10 == 0);
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // 清除換行符號

    for (int i = 0; i < N; ++i) {
        string card;
        getline(cin, card);
        if (isValidCardNumber(card)) {
            cout << "Valid" << endl;
        } else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}
