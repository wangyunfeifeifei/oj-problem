#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);

    // 打印正方形
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%02d", n * i + j + 1);
        }
        printf("\n");
    }

    // 打印三角形
    printf("\n");
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }
        for (int j = 0; j < i+1; j++) {
            printf("%02d", ++k);
        }
        printf("\n");
    }

    return 0;
}
