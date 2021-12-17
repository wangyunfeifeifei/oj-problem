/**
 * 问题描述：有n个重量和价值分别为wi, vi的物品。从这些物品中挑选出总重量不超过W的物品，求所有挑选方案中价值总和的最大值
 */
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX_N = 101;
const int MAX_W = 10001;

int n, W;
int w[MAX_N], v[MAX_N];

// solution1
//// 从第i个物品开始挑选总重小于j的部分
//int rec(int i, int j) {
//    int res;
//    if (i==n) {
//        // 没有剩余物品了
//        res = 0;
//    } else if (j < w[i]) {
//        // 无法挑选这个物品
//        res = rec(i+1, j);
//    } else {
//        // 挑选和不挑选两种都尝试一下
//        res = max(rec(i+1, j), rec(i+1, j-w[i]) + v[i]);
//    }
//    return res;
//}


// solution2
//int dp[MAX_N + 1][MAX_W + 1]; // 记忆化数组
//
//int rec(int i, int j) {
//    if (dp[i][j] >= 0) {
//        // 已经计算过的话直接使用之前的结果
//        return dp[i][j];
//    }
//    int res;
//    if (i == n) {
//        res == 0;
//    } else if (j < w[i]) {
//        res = rec(i + 1, j);
//    } else {
//        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
//    }
//    return dp[i][j] = res;
//}
//
//void solve() {
//    memset(dp, -1, sizeof(dp));
//    printf("%d\n", rec(0, W));
//}

// solution3
int dp[MAX_N + 1][MAX_W + 1];

void solve() {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= W; j++) {
            if (j < w[i]) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[0][W]);
}
