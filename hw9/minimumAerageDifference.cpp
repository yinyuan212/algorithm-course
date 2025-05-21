#include <iostream>
#include <vector>
#include <cmath>
#include <climits> // 為了使用 LLONG_MAX
using namespace std;

int findMinAvgDiffIndex(const vector<int>& nums) {
    long long totalSum = 0;
    for (int num : nums) totalSum += num;

    long long leftSum = 0;
    int n = nums.size();
    int minIndex = 0;
    long long minDiff = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        leftSum += nums[i];
        long long leftAvg = leftSum / (i + 1);
        long long rightSum = totalSum - leftSum;
        long long rightAvg = (i == n - 1) ? 0 : rightSum / (n - i - 1);
        long long diff = abs(leftAvg - rightAvg);

        if (diff < minDiff) {
            minDiff = diff;
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << findMinAvgDiffIndex(nums) << endl;
    }
    return 0;
}
