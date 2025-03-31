#include <iostream>
#include <vector>
#include <string>

using namespace std;

void ageSort(vector<int>& count, int n) {
    for (int i = 0; i < count.size(); i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                cout << i;
                if (--n) {  
                  cout << " ";
                }
            }
        }
    }

    cout << "\n";
}


int main() {

    while (true) {
        
        int n;
        cin >> n;

        if (n == 0) {
            return 0;
        }

        vector<int> count(101, 0);
        for (int i = 0; i < n; i++) {
            int age;
            cin >> age;
            count[age]++;
        }
        
        ageSort(count, n);
    }

    return 0;
}
