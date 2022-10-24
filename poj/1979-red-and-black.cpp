#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > qu;
int W, H;
char tiles[21][21];
int si, sj;  // 开始的位置
int ans;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

void input() {
  for (int i = 0; i < H; i++) {
    getchar();
    for (int j = 0; j < W; j++) {
      cin >> tiles[i][j];
      if (tiles[i][j] == '@') {
        si = i;
        sj = j;
      }
    }
  }
}

void output() { cout << ans << endl; }

void calc() {
  ans = 0;
  qu.push(make_pair(si, sj));
  while (!qu.empty()) {
    int i = qu.front().first, j = qu.front().second;
    qu.pop();
    ++ans;
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ni >= 0 && ni < H && nj >= 0 && nj < W && tiles[ni][nj] == '.') {
        tiles[ni][nj] = '#';
        qu.push(make_pair(ni, nj));
      }
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  while (cin >> W >> H) {
    if (W == 0 && H == 0) break;
    input();
    calc();
    output();
  }
  return 0;
}
