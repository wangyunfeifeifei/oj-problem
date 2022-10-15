#include <stdio.h>

int N;
int a[101];

void print() {
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      printf("%d", a[i]);
    } else {
      printf(" %d", a[i]);
    }
  }
  printf("\n");
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &a[i]);
  }
  print();
  for (int i = 1; i < N; i++) {
    int k = a[i];
    int j;
    for (j = i - 1; j >= 0 && a[j] > k; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = k;
    print();
  }
}
