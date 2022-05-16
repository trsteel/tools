#include "../../../include/seg_tree.h"
#include <iostream>

using namespace std;

const int maxn = 50010;

long t, n, a[maxn];
SegmentTree seg(maxn);

long add(long x, long y) { return x + y; }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> t;
  string op;
  int x, y;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    seg.set_merge_func(add);
    seg.init(a, n);
    while (true) {
      cin >> op;
      if (op == "Query") {
        cin >> x >> y;
        cout << "Case " << c << ": " << seg.query(x, y) << endl;
      } else if (op == "Add") {
        cin >> x >> y;
        seg.update(x, x, seg.query(x, x) + y);
      } else if (op == "Sub") {
        cin >> x >> y;
        seg.update(x, x, seg.query(x, x) - y);
      } else if (op == "End") {
        break;
      }
    }
  }
  return 0;
}