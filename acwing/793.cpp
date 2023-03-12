#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> mul(vector<int> A, int b) {
  vector<int> c;
  int t = 0;

  for (int i = 0; i < A.size(); i++) {
    int x = A[i] * b + t;
    c.push_back(x % 10);
    t = x / 10;
  }
  for (; t > 0; t /= 10) c.push_back(t % 10);
  while (c.size() > 1 && c.back() == 0) c.pop_back();

  return c;
}

int main() {
  string a;
  int b;
  cin >> a >> b;
  vector<int> A;
  for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
  auto c = mul(A, b);
  for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
  return 0;
}
