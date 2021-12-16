// 思路： 将最短的板合并所产生的长度，等于将这个板分成最短的板的消耗，所以每次将最短的两个板合并，最终得到最低消耗

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 20001;

int N, L[MAX_N];

typedef long long ll;

void solve() {
    ll ans = 0;

    // 直到计算到模板为1块时停止
    while (N > 1) {
        // 求最短板和次短板
        int mii1 = 0, mii2 = 1;
        if (L[mii1] > L[mii2]) swap(mii1, mii2);

        for (int i = 2; i < N; i++) {
            if (L[i] < L[mii1]) {
                mii2 = mii1;
                mii1 = i;
            } else if (L[i] < L[mii2]) {
                mii2 = i;
            }
        }

        // 合并最短板和次短板
        int t = L[mii1] + L[mii2];
        ans += t;

        if (mii1 == N-1) swap(mii1, mii2);
        L[mii1] = t;
        L[mii2] = L[N-1];
        N--;
    }

    printf("%lld\n", ans);
}

int main(int argc, char *argv[]) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }
    solve();
    return 0;
}
