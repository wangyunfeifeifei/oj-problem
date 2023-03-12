#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int a[N];

int partition(int a[], int l, int r) {
  int x = l + rand() % (r - l + 1);
  swap(a[l], a[x]);
  int i = l, j = r + 1;
  int v = a[l];
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

void quick_sort(int a[], int l, int r) {
  if (l >= r) return;
  int j = partition(a, l, r);
  quick_sort(a, l, j - 1);
  quick_sort(a, j + 1, r);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  quick_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
