#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
};

double my_abs(double x) {
    if (x < 0) return -x;
    return x;
}

double dist2(Point &a, Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return dx*dx + dy*dy + dz*dz;
}

void sort_by_x(vector<Point> &pts) {
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pts[j].x < pts[i].x) {
                Point tmp = pts[i];
                pts[i] = pts[j];
                pts[j] = tmp;
            }
        }
    }
}

double brute_force(vector<Point> &pts, int l, int r) {
    double best = 1e18;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            double d = dist2(pts[i], pts[j]);
            if (d < best)
                best = d;
        }
    }
    return best;
}

double closest_rec(vector<Point> &pts, int l, int r) {
    if (r - l <= 3)
        return brute_force(pts, l, r);
    int mid = (l + r) / 2;
    double midx = pts[mid].x;
    double dl = closest_rec(pts, l, mid);
    double dr = closest_rec(pts, mid + 1, r);
    double d = (dl < dr) ? dl : dr;
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if (my_abs(pts[i].x - midx) * my_abs(pts[i].x - midx) < d) {
            strip.push_back(pts[i]);
        }
    }
    int m = strip.size();
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            double d2 = dist2(strip[i], strip[j]);
            if (d2 < d)
                d = d2;
        }
    }
    return d;
}

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y >> pts[i].z;
    }
    sort_by_x(pts);
    double best_squared = closest_rec(pts, 0, n - 1);
    cout << "Shortest distance: ";
    cout << sqrt(best_squared) << endl;
    return 0;
}
