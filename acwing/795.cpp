#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int a[N], s[N] = {0};
int l, r;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }

  while (m--) {
    scanf("%d%d", &l, &r);
    printf("%d\n", s[r] - s[l - 1]);
  }
  return 0;
}
