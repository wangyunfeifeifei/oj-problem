#include <iostream>
using namespace std;

int main() {
  // 兔子速度，乌龟速度
  int v1, v2, t, s, l;
  cin >> v1 >> v2 >> t >> s >> l;
  int stop = 0;
  int r = 0;   // 兔子距离
  int tu = 0;  // 乌龟距离
  int i;
  for (i = 0; r < l && tu < l; i++) {
    tu += v2;
    if (stop > 0) {
      stop--;
    } else {
      r += v1;
      if (r - tu >= t) {
        stop = s;
      }
    }
    if (r >= l && tu >= l) {
      cout << "D" << endl;
    } else if (r >= l) {
      cout << "R" << endl;
    } else if (tu >= l) {
      cout << "T" << endl;
    }
  }
  cout << i << endl;

  return 0;
}
