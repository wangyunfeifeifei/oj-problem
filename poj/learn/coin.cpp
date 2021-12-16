/**
 * 问题描述：有1元、5元、10元、50元、100元、500元的硬币个C1 C5 C10 C50 C100 C500枚
 * 现在要用这些硬币来支付A元，最少需要多少枚硬币？ 假设本题至少存在一种支付方案
 *
 * 限制条件
 * 0 <=Ci <=10^9
 * 0 <=A<=10^9
 */
#include <cstdio>
#include<algorithm>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};

// 输入
int C[6];
int A;

void solve() {
    int ans = 0;

    for (int i = 5; i >= 0; i--) {
        int t = min(A/V[i], C[i]);
        A -= t * V[i];
        ans += t;
    }

    printf("%d\n", ans);
}
