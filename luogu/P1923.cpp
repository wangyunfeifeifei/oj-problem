#include <cstdio>
#include <cstdlib>

int a[5000001];
int n, k;

int partition(int l, int r) {
    int x = (l + r) / 2;
    int c = a[x];
    a[x] = a[l];
    a[l] = c;

    int t = a[l];
    int i = l, j = r + 1;
    while (true) {
        while (a[--j] > t) if (j == l) break;
        while (a[++i] < t) if (i == r) break;
        if (i < j) {
            c = a[i];
            a[i] = a[j];
            a[j] = c;
        } else break;
    }
    a[l] = a[j];
    a[j] = t;
    return j;
}

void display() {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int _nth(int i, int j, int k) {
    if (i == j) return i;
    int p = partition(i, j);
    if (k < p) {
        return _nth(i, p - 1, k);
    } else if (k > p) {
        return _nth(p + 1, j, k);
    } else {
        return k;
    }
}

int nth(int k) {
    int p = _nth(0, n - 1, k);
    return a[p];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", nth(k));
    return 0;
}
