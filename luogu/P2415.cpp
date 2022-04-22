#include <cstdio>

int main() {
    long long int n = 1;
    long long int s[31];
    long long int i = 0;
    while (scanf("%lld", &s[i]) != EOF) {
        n *= 2;
        i++;
    }
    long long int ans = 0;
    for (int j = 0; j < i; j++) {
        ans = ans + s[j] * (n / 2);
    }
    printf("%lld\n", ans);
    return 0;
}
