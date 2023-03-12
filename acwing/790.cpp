#include <iostream>
using namespace std;

int main() {
  double x;
  scanf("%lf", &x);
  int neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }
  double l = 0, r = x;
  while (r - l > 1e-9) {
    double mid = (r + l) / 2;
    if (mid * mid * mid >= x)
      r = mid;
    else
      l = mid;
  }
  if (neg) printf("-");
  printf("%.6lf\n", l);
  return 0;
}
