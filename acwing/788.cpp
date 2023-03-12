#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int a[N], tmp[N];
unsigned long long int ans = 0;

void merge_sort(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  merge_sort(l, mid);
  merge_sort(mid + 1, r);
  int i = l, j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    if (a[i] > a[j]) {
      ans += (mid - i + 1);
      tmp[k++] = a[j++];
    } else
      tmp[k++] = a[i++];
  }
  while (i <= mid) tmp[k++] = a[i++];
  while (j <= r) tmp[k++] = a[j++];
  for (int i = l; i <= r; i++) a[i] = tmp[i];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  merge_sort(0, n - 1);
  printf("%lld\n", ans);
  return 0;
}
