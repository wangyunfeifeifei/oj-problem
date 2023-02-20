#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string An(int n, int k) {
  if (k == 0) return "";
  stringstream ss;
  string pre = An(n, k - 1);
  ss << pre << (char)('A' + k - 1) << pre;
  return ss.str();
}

int main() {
  int n;
  cin >> n;
  cout << An(n, n) << endl;
  return 0;
}
