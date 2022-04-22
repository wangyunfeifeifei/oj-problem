#include <cstdio>

int main() {
    int cnt[26] = {0};
    char ch;
    int maxn = 0;
    while (scanf("%c", &ch) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            int i = ch - 'A';
            cnt[i]++;
            if (cnt[i] > maxn) maxn = cnt[i];
        }
    }
    for (int i = maxn; i > 0; i--) {
        int k;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] >= i)k = j;
        }
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                if (cnt[j] >= i) printf("*");
                else printf(" ");
            } else {
                if (cnt[j] >= i) printf(" *");
                else printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++) {
        if (i == 0)
            printf("%c", i + 'A');
        else
            printf(" %c", i + 'A');

    }
//    for (int i = 0; i < 26; i++) {
//        printf("%c: %d\n", i + 'A', cnt[i]);
//    }
    return 0;
}
