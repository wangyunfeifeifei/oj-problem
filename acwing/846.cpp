#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = N * 2;

// h存头结点
int h[N], e[M], ne[M], idx = 0;
int n;

void init() { memset(h, -1, sizeof h); }

void add(int a, int b) {
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx;
  idx++;
}

bool vis[N];
int ans = INT_MAX;
int dfs(int u) {  // 返回以u为根的子树的大小
  vis[u] = true;
  int cnt = 1;  // 这根子树大小，作为返回值
  int res = 0;
  // 遍历所有出边
  for (int i = h[u]; i != -1; i = ne[i]) {
    if (!vis[e[i]]) {
      int s = dfs(e[i]);
      cnt += s;
      res = max(s, res);
    }
  }
  res = max(res, n - cnt);
  ans = min(ans, res);
  return cnt;
}

int main() {
  cin >> n;
  init();
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
