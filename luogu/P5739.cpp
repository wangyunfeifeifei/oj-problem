#include <cstdio>

int fact(int n, int last) {
    if (n == 0) return last;
    return fact(n - 1, last * n);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fact(n, 1));
    return 0;
}
