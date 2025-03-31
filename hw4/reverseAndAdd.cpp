#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrome(int num) {
    string s = to_string(num);
    int left = 0, right = s.size() -1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int reverseNum(int num) {
    int result = 0;
    while (num) {
        result = result * 10 + num % 10;
        num /= 10;
    }

    return result;
}

void reverseAndAdd(int& num){
    int count = 0;

    while (true) {
        int reversed = reverseNum(num);
        num = num + reversed;
        count++;
        
        if(isPalindrome(num)){
            cout << count << " " << num << endl;
            return;
        }
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int num;
        cin >> num;

       reverseAndAdd(num);
    }

    return 0;
}
