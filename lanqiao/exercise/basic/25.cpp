#include <climits>
#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;
  int a[201][201];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int next[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int b[] = {0, m - 1, n - 1, 0};
  int d = 0;
  int cnt = m * n;
  int i = 0, j = 0;
  for (int t = 0; t < cnt; t++) {
    if (t == 0) {
      cout << a[i][j];
    } else {
      cout << " " << a[i][j];
    }
    a[i][j] = INT_MIN;
    if (i + next[d][0] == m || i + next[d][0] < 0 || j + next[d][1] == n ||
        j + next[d][1] < 0 || a[i + next[d][0]][j + next[d][1]] == INT_MIN) {
      d = (d + 1) % 4;
    }
    i += next[d][0];
    j += next[d][1];
  }
  cout << endl;
  return 0;
}
