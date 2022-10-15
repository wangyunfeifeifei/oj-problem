#include <stdio.h>

bool isPrime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int ans = 0;
  int n;
  scanf("%d", &n);
  int t;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    if (isPrime(t)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
