#include <cstdio>

int w[5][5] = {
        {0, -1, 1, 1, -1},
        {1, 0, -1, 1, -1},
        {-1, 1, 0, -1, 1},
        {-1, -1, 1, 0, 1},
        {1, 1, -1, -1, 0}
};

int main() {
    int n, n1, n2;
    scanf("%d%d%d", &n, &n1, &n2);
    int a[201];
    int b[201];
    int scoreA = 0, scoreB = 0;
    for (int i = 0; i < n1; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &b[i]);
    for (int i = 0, j = 0, k = 0; k < n; k++, i = (i + 1) % n1, j = (j + 1) % n2) {
        if (w[a[i]][b[j]] > 0) scoreA++;
        if (w[b[j]][a[i]] > 0) scoreB++;
    }
    printf("%d %d\n", scoreA, scoreB);
    return 0;
}
