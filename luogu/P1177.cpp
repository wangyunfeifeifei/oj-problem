#include <cstdio>
#include <cstdlib>
#include <ctime>

void qsort(int a[], int l, int r);

int partition(int a[], int l, int r);

void exch(int a[], int i, int j);

int main() {
    int n;
    int a[100005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void exch(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void qsort(int a[], int l, int r) {
    if (l >= r) return;
    srand(time(NULL));
    int p = partition(a, l, r);
    qsort(a, l, p - 1);
    qsort(a, p + 1, r);
}

int partition(int a[], int l, int r) {
    int x = l + rand() % (r - l);
    exch(a, l, x);
    int v = a[l];
    int i = l, j = r + 1;
    while (true) {
        while (a[--j] > v) if (j == l)break;
        while (a[++i] < v) if (i == r)break;
        if (i >= j)break;
        exch(a, i, j);
    }
    exch(a, l, j);
    return j;
}
