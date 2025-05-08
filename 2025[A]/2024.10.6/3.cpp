#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

// 计算两点之间的欧氏距离
double distance(Point p1, Point p2) {
    return sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 按x坐标排序的比较函数
bool cmpX(const Point &a, const Point &b) {
    return a.x < b.x;
}

// 按y坐标排序的比较函数
bool cmpY(const Point &a, const Point &b) {
    return a.y < b.y;
}

// 暴力求解最近点对，适用于小规模点集
double bruteForce(const vector<Point> &points, int left, int right) {
    double minDist = numeric_limits<double>::infinity();
    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

// 处理带状区域，找到跨越左右两部分的最近点对
double stripClosest(vector<Point> &strip, int size, double d) {
    double minDist = d;
    sort(strip.begin(), strip.begin() + size, cmpY);
    
    // 在带状区域中检查距离
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    return minDist;
}

// 分治法递归求解最近点对
double closestUtil(vector<Point> &points, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];

    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, strip.size(), d));
}

// 主函数，解决问题的入口
double closest(vector<Point> &A, vector<Point> &B, int N) {
    vector<Point> points(2 * N);
    for (int i = 0; i < N; i++) {
        points[i] = A[i];
        points[i + N] = B[i];
    }

    sort(points.begin(), points.end(), cmpX);
    return closestUtil(points, 0, 2 * N - 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<Point> A(N), B(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i].x >> A[i].y;
        }

        for (int i = 0; i < N; i++) {
            cin >> B[i].x >> B[i].y;
        }

        double result = closest(A, B, N);
        cout << fixed << setprecision(3) << result << endl;
    }

    return 0;
}
