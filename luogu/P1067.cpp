#include <cstdio>
#include <cmath>

int main() {
    int n;
    int ef[105];
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &ef[i]);
    }
    for (int i = n; i >= 0; i--) {
        if (ef[n - i] != 0) {
            if (i != n && ef[n - i] > 0)printf("+");
            if (abs(ef[n - i]) > 1 || i == 0) printf("%d", ef[n - i]);
            if (ef[n - i] == -1 && i != 0) printf("-");
            if (i > 1) printf("x^%d", i);
            else if (i == 1)printf("x"); // 一次项
        }
    }
    printf("\n");
    return 0;
}
