#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        long long n;
        cin >> n;  // Number of odd numbers in the sequence
        
        long long layer = (n + 1) / 2;  // Calculate the layer number
        // cout << "layer: " << layer << endl;  // Output the layer number
        
        long long a = pow(layer, 2) * 2 - 1;  // Last number in the layer
        long long b = a - 2;
        long long c = a - 4;

        // cout << a << " " << b << " " << c << endl;  // Output the last three numbers in the layer
        cout << a * b * c << endl;  // Output the product of the last three numbers
    }
    
    return 0;
}