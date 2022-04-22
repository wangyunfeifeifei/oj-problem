#include <cstdio>

int main() {
    int m, n;
    int ans[10] = {0};
    scanf("%d%d", &m, &n);
    for (int x = m; x <= n; x++) {
        int t = x;
        while (t != 0) {
            ans[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (i != 9)
            printf("%d ", ans[i]);
        else
            printf("%d\n", ans[i]);
    }
    return 0;
}
