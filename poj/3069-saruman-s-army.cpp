/**
 * 问题描述
 * 直线上有N个点。点i的位置是Xi。从这N个点中选择若干个，给它们加上标记。
 * 对每一个点，其距离为R以内的区域里必须有带有标记的点（自己本身带有标记的点，可以认为与其距离为0的地方有一个带有标记的点）。
 * 在满足这个条件的情况下，希望能为尽可能少的点添加标记。请问至少要有多少点被加上标记？
 *
 * 1 <= N <= 1000
 * 0 <= R <= 1000
 * 0 <= Xi <= 1000
 *
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;
int N, R;
int X[MAX_N];

void solve() {
    sort(X, X + N);

    int i = 0, ans = 0;
    while (i < N) {
        // s 是没有被覆盖的最左的点
        int s = X[i++];

        // 右进到距s大于R的点
        while (i < N && X[i] <= s + R) i++;

        // p是新加上标记的点
        int p = X[i - 1];

        // 右进到距p大于R的点
        while (i < N && X[i] <= p + R) i++;

        ++ans;
    }

    printf("%d\n", ans);
}

int main() {
    while (scanf("%d%d", &R, &N)) {
        if(N == -1 && R == -1) break;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &X[i]);
        }
        solve();
    }
    return 0;
}
