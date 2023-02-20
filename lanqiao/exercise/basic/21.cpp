#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string An(int n, int k) {
  if (k > n) return "";
  stringstream ss;
  ss << "sin(" << k << (k == n ? "" : (k % 2 == 1 ? "-" : "+")) << An(n, k + 1)
     << ")";
  return ss.str();
}

string Sn(int n, int k) {
  stringstream ss;
  if (k == n) {
    ss << An(n - k + 1, 1) << "+" << k;
    return ss.str();
  }
  ss << "(" << Sn(n, k + 1) << ")" << An(n - k + 1, 1) << "+" << k;
  return ss.str();
}

int main() {
  int n;
  cin >> n;
  cout << Sn(n, 1);
  return 0;
}
