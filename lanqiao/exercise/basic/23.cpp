#include <iostream>
using namespace std;

int main() {
  int mat[21][21];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  bool ans[21] = {false};
  for (int i = 0; i < n; i++) {
    ans[i] = true;
    for (int j = 0; j < n; j++) {
      if (j != i && ans[j] && mat[j][i] == 0) {
        ans[i] = false;
      }
    }
    for (int j = 0; j < n && ans[i]; j++) {
      if (mat[i][j] == 1 && mat[j][i] != 1) {
        ans[i] = false;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (ans[i]) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;

  return 0;
}
