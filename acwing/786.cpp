#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, k;
int a[N];

int partition(int l, int r) {
  int x = l + rand() % (r - l + 1);
  swap(a[x], a[l]);
  int v = a[l];
  int i = l, j = r + 1;
  while (true) {
    while (a[++i] < v)
      if (i == r) break;
    while (a[--j] > v)
      if (j == l) break;
    if (i >= j) break;
    swap(a[i], a[j]);
  }
  swap(a[l], a[j]);
  return j;
}

int quick_select(int l, int r) {
  if (l >= r) return a[l];
  int j = partition(l, r);
  if (j == k - 1)
    return a[j];
  else if (j < k - 1)
    return quick_select(j + 1, r);
  else
    return quick_select(l, j - 1);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("%d\n", quick_select(0, n - 1));
  return 0;
}
