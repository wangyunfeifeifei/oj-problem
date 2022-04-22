#include <cstdio>
#include <cmath>

int main() {
    int n;
    int scores[1005][3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &scores[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            int sum1 = 0;
            int sum2 = 0;
            for (int k = 0; k < 3; k++) {
                if (abs(scores[i][k]-scores[j][k])>5)flag = false;
                sum1 += scores[i][k];
                sum2 += scores[j][k];
            }
            if(flag && abs(sum1-sum2) <= 10) ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
