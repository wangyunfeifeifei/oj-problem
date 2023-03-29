#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10;
int n, m;
char str[N];
ULL h[N] = {0}, p[N], P = 131;  // p存储p^i

ULL get(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  cin >> str + 1;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * P;
    h[i] = h[i - 1] * P + str[i];
  }
  while (m--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (get(l1, r1) == get(l2, r2))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
