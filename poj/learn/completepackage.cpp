/**
 * 问题描述：
 * 有n种重量和价值分别为wi, vi的物品。从这些物品中挑选总重量不超过W的物品，求出挑选物品价值总和的最大值。在这里，每种物品可以挑选任意多件。
 * 1 <= n <= 100
 * 1 <= wi <= 100
 * 1 <= W <= 10000
 */
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 10000;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_M];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}

