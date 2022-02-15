#include <bits/stdc++.h>

using namespace std;

// Idea: add an edge from a -> b if a is stopping b from going down. Then topo sort

const int MAXN = 5003;

struct Point {
    int x, y;
};

struct LineSegment {
    Point u, v;
};


int n, ind[MAXN];
vector<pair<LineSegment, int>> a;
vector<int> adj[MAXN];

// Given three collinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // collinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        LineSegment cur = {{x1, y1}, {x2, y2}};
        a.emplace_back(cur, i);
    }

    // Add edge from v -> u if v is stopping u from going down
    for (auto u : a) {
        for (auto v : a) {
            if (u.second == v.second) continue;

            if (doIntersect(v.first.u, v.first.v, u.first.u, {u.first.u.x, 0}) || doIntersect(v.first.u, v.first.v, u.first.v, {u.first.v.x, 0}) || doIntersect(u.first.u, u.first.v, v.first.u, {v.first.u.x, 10000}) || doIntersect(u.first.u, u.first.v, v.first.v, {v.first.v.x, 10000})) {
                adj[v.second].emplace_back(u.second);
                ind[u.second]++;
            }
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) q.emplace(i);
    }

    int cnt = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        cout << u << (++cnt == n ? '\n' : ' ');

        for (auto v : adj[u]) {
            if (--ind[v] == 0) q.emplace(v);
        }
    }
}
