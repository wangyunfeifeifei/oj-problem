#include <iostream>
using namespace std;

const int N = 1010;
int n, V;
int v[N];
int w[N];
int dp[N];

int main() {
  cin >> n >> V;
  for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
  for (int i = 1; i <= n; i++) {
    for (int j = V; j >= 0; j--) {
      if (j >= v[i]) dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[V] << endl;

  return 0;
}
