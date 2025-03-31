#include <iostream>

void fibonacci(int n) {
    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }
    if (n == 1) {
        std::cout << 1 << std::endl;
        return;
    }

    unsigned long long a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    std::cout << c << std::endl;
}

int main() {
    int k, n;
    std::cin >> k;  // 讀取測資數量

    while (k--) {
        std::cin >> n;
        fibonacci(n);
    }

    return 0;
}
