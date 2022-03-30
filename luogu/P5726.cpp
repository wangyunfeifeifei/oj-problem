#include <cstdio>

int main() {
    int n;
    int num_min = 0x7fffffff;
    int num_max = 0;
    int sum = 0;
    int k;
    scanf("%d", &n);
    if (n <= 2) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        sum += k;
        if (k > num_max) num_max = k;
        if (k < num_min) num_min = k;
    }
    sum = sum - num_max - num_min;
    printf("%.2lf\n", (sum * 1.0) / (n - 2));
    return 0;
}
