#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, l, r;
vector<PII> segs;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &l, &r);
    segs.push_back({l, r});
  }
  sort(segs.begin(), segs.end(),
       [](PII a, PII b) { return a.first < b.first; });
  PII cur = segs[0];
  int ans = 0;
  for (auto [s, e] : segs) {
    if (s > cur.second) {
      ans++;
      cur = {s, e};
    } else {
      cur.second = max(cur.second, e);
    }
  }
  ans++;
  printf("%d\n", ans);
  return 0;
}
