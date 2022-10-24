#include <limits.h>
#include <stdio.h>

int w, h;
int g[21][21];
int si, sj;
int ei, ej;
int ans = INT_MAX;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int min(int a, int b) { return a < b ? a : b; }

// 输入g
void input() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", &g[i][j]);
      if (g[i][j] == 2) {
        si = i;
        sj = j;
      } else if (g[i][j] == 3) {
        ei = i;
        ej = j;
      }
    }
  }
}

bool valid(int r, int c) { return r >= 0 && r < h && c >= 0 && c < w; }

void dfs(int r, int c, int k) {
  if (k >= 10) return;
  for (int i = 0; i < 4; i++) {
    int nr = r;
    int nc = c;
    while (valid(nr + dx[i], nc + dy[i]) && g[nr + dx[i]][nc + dy[i]] != 1) {
      nr += dx[i];
      nc += dy[i];
      if (nr == ei && nc == ej) {
        ans = min(ans, k + 1);
        return;
      }
    }
    if ((nr != r || nc != c) && valid(nr + dx[i], nc + dy[i]) &&
        g[nr + dx[i]][nc + dy[i]] == 1) {
      // 撞倒墙了
      g[nr + dx[i]][nc + dy[i]] = 0;
      dfs(nr, nc, k + 1);
      g[nr + dx[i]][nc + dy[i]] = 1;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  while (scanf("%d%d", &w, &h) != EOF) {
    if (w == 0 && h == 0) {
      break;
    }
    input();
    ans = INT_MAX;
    dfs(si, sj, 0);
    printf("%d\n", ans == INT_MAX ? -1 : ans);
  }
}
