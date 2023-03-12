#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int a[N];

// >=k的左边界
int bsearch1(int l, int r, int k) {
  while (l < r) {
    int mid = l + r >> 1;
    if (a[mid] >= k)
      r = mid;
    else
      l = mid + 1;
  }
  return a[l] == k ? l : -1;
}
// <= k的右边界
int bsearch2(int l, int r, int k) {
  while (l < r) {
    int mid = l + 1 + r >> 1;
    if (a[mid] <= k)
      l = mid;
    else
      r = mid - 1;
  }
  return a[l] == k ? l : -1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int q;
  while (m--) {
    scanf("%d", &q);
    int l = bsearch1(0, n - 1, q);
    int r = bsearch2(0, n - 1, q);
    printf("%d %d\n", l, r);
  }
  return 0;
}
