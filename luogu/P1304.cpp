#include <cstdio>

#define N 100005

bool p[N] = {false};
int prime[N];
int len = 0;

void sieve() {
    for (int i = 2; i <= N; i++) {
        if (!p[i]) prime[len++] = i;
        for (int j = i * 2; !p[i] && j <= N; j += i) {
            p[j] = true;
        }
    }
}

int main() {
    sieve();
    int n;
    scanf("%d", &n);
    for (int i = 4; i <= n; i += 2) {
        int l = 0, r = len - 1;
        while (l <= r) {
            if (prime[l] + prime[r] == i) {
                printf("%d=%d+%d\n", i, prime[l], prime[r]);
                break;
            } else if (prime[l] + prime[r] < i) {
                l++;
            } else {
                r--;
            }
        }
    }
    return 0;
}
