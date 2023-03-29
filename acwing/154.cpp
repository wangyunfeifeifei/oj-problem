#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k;
int a[N], q[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  // 求最小值
  int pre = 0, rear = 0;
  for (int i = 0; i < n; i++) {
    if (pre < rear && i - k + 1 > q[pre]) pre++;
    while (pre < rear && a[q[rear - 1]] >= a[i]) rear--;
    q[rear++] = i;
    if (i >= k - 1) cout << a[q[pre]] << ' ';
  }
  cout << endl;

  pre = 0, rear = 0;
  for (int i = 0; i < n; i++) {
    if (pre < rear && i - k + 1 > q[pre]) pre++;
    while (pre < rear && a[q[rear - 1]] <= a[i]) rear--;
    q[rear++] = i;
    if (i >= k - 1) cout << a[q[pre]] << ' ';
  }
  cout << endl;
  return 0;
}
