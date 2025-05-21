#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

// 計算兩點之間的歐幾里得距離
double getDistance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 排序用：根據 X 座標排序
bool compareX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

// 排序用：根據 Y 座標排序
bool compareY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

// 使用分治法找最近點對
double closestPairRec(vector<Point>& points, int left, int right) {
    if (right - left <= 3) { 
        double minDist = 1e9;
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                minDist = min(minDist, getDistance(points[i], points[j]));
            }
        }
        sort(points.begin() + left, points.begin() + right, compareY);
        return minDist;
    }

    int mid = (left + right) / 2;
    int midX = points[mid].x;

    double dLeft = closestPairRec(points, left, mid);
    double dRight = closestPairRec(points, mid, right);
    double d = min(dLeft, dRight);

    vector<Point> strip;
    for (int i = left; i < right; i++) {
        if (abs(points[i].x - midX) < d) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, getDistance(strip[i], strip[j]));
        }
    }

    return d;
}

// 主函數
double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestPairRec(points, 0, points.size());
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        double result = closestPair(points);
        if (result >= 10000) {
            cout << "INFINITY" << endl;
        } else {
            cout << fixed << setprecision(4) << result << endl;
        }
    }
    return 0;
}
