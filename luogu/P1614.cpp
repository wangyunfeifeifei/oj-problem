#include <cstdio>
#include <algorithm>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int sum[5001];
    int t = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += t;
        t = sum[i];
    }
    int min_sum = sum[m - 1];
    for (int i = m; i < n; i++) {
        min_sum = std::min(min_sum, sum[i] - sum[i - m]);
    }
    printf("%d\n", min_sum);
    return 0;
}
