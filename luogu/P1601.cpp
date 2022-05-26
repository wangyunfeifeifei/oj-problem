#include <cstdio>
#include <cstring>

int main() {
    char a[505];
    char b[505];
    scanf("%s%s", a, b);
    int c = 0;
    int lena = strlen(a), lenb = strlen(b);
    char sum[505];
    int i = 0;
    for (int ia = lena - 1, ib = lenb - 1; ia >= 0 || ib >= 0; ia--, ib--) {
        int x = ia >= 0 ? a[ia] - '0' : 0;
        int y = ib >= 0 ? b[ib] - '0' : 0;
        int s = x + y + c;
        sum[i++] = '0' + s % 10;
        c = s / 10;
    }
    if (c > 0) sum[i++] = '0' + c;
    for (int k = i - 1; k >= 0; k--) {
        printf("%c", sum[k]);
    }
    printf("\n");
    return 0;
}
