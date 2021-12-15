#include <bits/stdc++.h>

// Idea: get a point. Shift all points so the point that was just chosen becomes origin.
// Rotate all points by 90º so the all points are in the first quadrant. Use simple reciprocals
// and negative numbers, not trig for this. We know two points produce a right triangle
// if they are in neighbouring quadrants and their coordinates are the same.

using namespace std;

int n, ans;

int xree[1502], yree[1502];

double get_angle(int x, int y) {
    double y_ = y, x_ = x;
    if (x == 0 || y == 0) return 0;
    if (x > 0 && y > 0) return (y_/x_); // Quadrant 1
    if (x < 0 && y < 0) return (y_/x_); // Quadrant 3
    if (x > 0 && y < 0) return -(x_/y_); // Quadrant 2
    return -(x_/y_); // Quadrant 4
}


int get_quadrant(int x, int y) {
    if (x >= 0 && y > 0) return 0; // Quadrant 1
    if (x <= 0 && y < 0) return 2; // Quadrant 3
    if (x > 0 && y <= 0) return 1; // Quadrant 2
    return 3; // Quadrant 4
}


signed main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xree[i], &yree[i]);
    }

    for (int i = 0; i < n; i++) {
        unordered_map<double, int> angles[4];

        int x1 = xree[i], y1_ = yree[i];
        for (int j = 0; j < n; j++) {
            int x = xree[j] - x1, y = yree[j] - y1_;
            if (i == j) continue;
            angles[get_quadrant(x, y)][get_angle(x, y)]++;
        }

        for (auto [angle, number]: angles[1]) {
            if (angles[0].contains(angle)) ans += (angles[0][angle] * number);
            if (angles[2].contains(angle)) ans += (angles[2][angle] * number);
        }

        for (auto [angle, number]: angles[3]) {
            if (angles[2].contains(angle)) ans += (angles[2][angle] * number);
            if (angles[0].contains(angle)) ans += (angles[0][angle] * number);
        }
    }

    printf("%d\n", ans);
}
