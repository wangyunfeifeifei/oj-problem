#include <cstdio>

int main() {
    int cnt[81] = {0};
    int s1, s2, s3;
    scanf("%d%d%d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; i++)
        for (int j = 1; j <= s2; j++)
            for (int k = 1; k <= s3; k++)
                cnt[i + j + k]++;
    int maxi = 0;
    for (int i = 0; i <= 80; i++) {
        if (cnt[i] > cnt[maxi]) maxi = i;
    }
    printf("%d\n", maxi);
    return 0;
}
