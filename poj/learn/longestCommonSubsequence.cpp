/**
 * 给定两个字符串 s1s2...sn和t1t2...tn。求出这两个字符串最长的公共子序列的长度。字符串s1s2...sn的子序列指可以表示为s1i si2 ... sim的序列。
 * 1 <= n, m <= 1000
 */
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
char s[MAX_N + 1], t[MAX_M + 1];

int dp[MAX_N + 1][MAX_M + 1];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

