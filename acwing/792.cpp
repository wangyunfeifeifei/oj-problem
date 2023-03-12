#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 判断A>=B
bool cmp(const vector<int> &A, const vector<int> &B) {
  if (A.size() != B.size()) return A.size() > B.size();
  for (int i = A.size() - 1; i >= 0; i--)
    if (A[i] != B[i]) return A[i] > B[i];
  return true;  // A == B
}

vector<int> sub(const vector<int> &A, const vector<int> &B) {
  vector<int> c;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    int x = A[i] - t;
    if (i < B.size()) x -= B[i];
    c.push_back((x + 10) % 10);
    t = x >= 0 ? 0 : 1;
  }
  while (c.size() > 1 && c.back() == 0) c.pop_back();  // 去前导0
  return c;
}

int main() {
  string a, b;
  vector<int> A, B;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
  if (cmp(A, B)) {
    auto c = sub(A, B);
    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
  } else {
    auto c = sub(B, A);
    printf("-");
    for (int i = c.size() - 1; i >= 0; i--) printf("%d", c[i]);
  }
  return 0;
}
