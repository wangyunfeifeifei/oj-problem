#include <cstdio>

int main() {
    int x, y;
    int leap[500];
    int k = 0;
    scanf("%d%d", &x, &y);
    for (int i = x; i <= y; i++) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) leap[k++] = i;
    }
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        if (i == k - 1)printf("%d\n", leap[i]);
        else printf("%d ", leap[i]);
    }
    return 0;
}
