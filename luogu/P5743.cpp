#include <cstdio>

int main() {
    int n;
    int k = 1;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        k = (k + 1) * 2;
    }
    printf("%d\n", k);
    return 0;
}
