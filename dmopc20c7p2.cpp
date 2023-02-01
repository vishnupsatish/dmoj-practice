/**
*  author:  vishnus
*  created: 2023-02-01
**/
#include <iostream>
#include <map>
#include <functional>

using namespace std;

// I give up on getting the last 30/100. Idea: Store all edges and points that occur. 
// If an edge has more than 1 occurrence and a point has more than 2 occurrences, delete 
// them since they shouldn't exist. Then, start from the min x, then min y point, and 
// try going to several next points. If an edge exists, go. Greedy for clockwise.

#pragma GCC target ("avx2")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<pair<int, int>, pair<int, int>> pt_id;
  map<pair<int, int>, int> edges;
  int edgeidcounter = 0;
  function<int(pair<int, int>)> GetPtId = [&](pair<int, int> pt) -> int {
    if (pt_id.find(pt) != pt_id.end()) {
      pt_id[pt].second++;
      return pt_id[pt].first;
    }
    pt_id[pt] = {edgeidcounter, 1};
    return edgeidcounter++;
  };
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 4 == 0) { // Square
      edges[{GetPtId({x, y}), GetPtId({x, y + 1})}]++;
      edges[{pt_id[{x, y + 1}].first, GetPtId({x + 1, y + 1})}]++;
      edges[{pt_id[{x, y}].first, GetPtId({x + 1, y})}]++;
      edges[{pt_id[{x + 1, y}].first, pt_id[{x + 1, y + 1}].first}]++;
    } else { // Octagon
      edges[{GetPtId({x - 1, y}), GetPtId({x - 1, y + 1})}]++;
      edges[{pt_id[{x - 1, y + 1}].first, GetPtId({x, y + 2})}]++;
      edges[{pt_id[{x, y + 2}].first, GetPtId({x + 1, y + 2})}]++;
      edges[{pt_id[{x + 1, y + 2}].first, GetPtId({x + 2, y + 1})}]++;
      edges[{GetPtId({x + 2, y}), pt_id[{x + 2, y + 1}].first}]++;
      edges[{GetPtId({x + 1, y - 1}), pt_id[{x + 2, y}].first}]++;
      edges[{GetPtId({x, y - 1}), pt_id[{x + 1, y - 1}].first}]++;
      edges[{pt_id[{x - 1, y}].first, pt_id[{x, y - 1}].first}]++;
    }
  }
  int cnt = 0;
  for (auto it = pt_id.begin(); it != pt_id.end(); ) {
    if ((*it).second.second > 2) {
      pt_id.erase(it++);
    } else {
      cnt++;
      it++;
    }
  }
  for (auto it = edges.begin(); it != edges.end(); ) {
    if ((*it).second > 1) {
      edges.erase(it++);
    } else {
      it++;
    }
  }
  cout << cnt << '\n';
  int x = (*pt_id.begin()).first.first;
  int y = (*pt_id.begin()).first.second;
  for (int i = 0; i < cnt; i++) {
    cout << x << ' ' << y << '\n';
    function<bool(int, int)> Check = [&](int xcn, int ycn) -> bool {
      if (pt_id.find({x + xcn, y + ycn}) == pt_id.end()) {
        return false;
      }
      int xo = x;
      int yo = y;
      int xn = xo + xcn;
      int yn = yo + ycn;
      if (yo > yn) {
        swap(xo, xn);
        swap(yo, yn);
      }
      if (xo > xn) {
        swap(xo, xn);
        swap(yo, yn);
      }
      if (edges.find({pt_id[{xo, yo}].first, pt_id[{xn, yn}].first}) == edges.end()) {
        return false;
      }
      pt_id.erase({x, y});
      x += xcn;
      y += ycn;
      return true;
    };
    if (Check(0, 1)) {
      continue;
    }
    if (Check(1, 1)) {
      continue;
    }
    if (Check(1, 0)) {
      continue;
    }
    if (Check(1, -1)) {
      continue;
    }
    if (Check(0, -1)) {
      continue;
    }
    if (Check(-1, -1)) {
      continue;
    }
    if (Check(-1, 0)) {
      continue;
    }
    if (Check(-1, 1)) {
      continue;
    }
  }
}
