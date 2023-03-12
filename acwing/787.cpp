#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int a[N], tmp[N];

void merge_sort(int a[], int l, int r) {
  if (l >= r) return;
  int mid = l + (r - l) / 2;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);
  int i = l, j = mid + 1;
  int k = l;
  while (i <= mid && j <= r) {
    if (a[i] < a[j])
      tmp[k++] = a[i++];
    else
      tmp[k++] = a[j++];
  }
  while (i <= mid) tmp[k++] = a[i++];
  while (j <= r) tmp[k++] = a[j++];
  for (int i = l; i <= r; i++) {
    a[i] = tmp[i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
