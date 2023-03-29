#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n, m;
// a是保存离散化后的进行操作的数组，s是离散化后的前缀和数组
int a[N] = {0}, s[N] = {0};
int l, r, c;

vector<int> alls;  // 所有要离散化的值, 不管是操作还是查询，都插入进来
vector<PII> add, query;  // 插入操作，查询操作

int find(int x) {
  int l = 0, r = alls.size() - 1;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (alls[mid] <= x)
      l = mid;
    else
      r = mid - 1;
  }
  return l + 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, c;
    scanf("%d%d", &x, &c);
    add.push_back({x, c});

    alls.push_back(x);
  }

  for (int i = 0; i < m; i++) {
    scanf("%d%d", &l, &r);
    query.emplace_back(l, r);

    alls.push_back(l);
    alls.push_back(r);
  }
  // 去重
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());

  for (auto [x, c] : add) {
    a[find(x)] += c;
  }

  for (int i = 1; i <= alls.size(); i++) {
    s[i] += s[i - 1] + a[find(alls[i - 1])];
  }

  for (auto [l, r] : query) {
    printf("%d\n", s[find(r)] - s[find(l) - 1]);
  }

  return 0;
}
